from nicegui import ui, run
from components import canvas, convert_actions
import tkinter as tk
from tkinter import filedialog
import asyncio
from PIL import Image
import io
import base64
from pyzta import ZtaF

from data.state import ZtaFile, converter_state


def convert_dashboard():
    # ------------------- UI State -------------------
    file_list = None
    canvas_image = None

    # ------------------ Event handlers ------------------
    def signal_to_raw(pixels, width, height, channels) -> dict:
        """Convert to RGBA raw array for canvas rendering"""
        mode = {1: "L", 3: "RGB", 4: "RGBA"}.get(channels, "RGBA")
        img = Image.frombytes(mode, (width, height), bytes(pixels))
        img = img.convert("RGBA")  # canvas always needs RGBA
        return {
            "pixels": list(img.tobytes()),  # flat RGBA array
            "width": width,
            "height": height,
        }

    def load_files():
        async def show_zta_dialog():
            with (
                ui.dialog().props("persistent") as dialog,
                ui.card().classes(
                    "bg-gray-800 text-white min-w-[600px] p-4 gap-4 rounded-lg border border-gray-700"
                ),
            ):
                ui.label("Load ZTA files from your computer").classes("text-lg")

                with ui.column().classes("gap-2 w-full"):
                    ui.label("ZTA File").classes("text-gray-400")

                    with ui.row().classes("gap-2 w-full items-stretch items-center"):
                        zta_path = (
                            ui.input(placeholder="No file selected")
                            .props(
                                "readonly dense outlined dark clearable hide-bottom-space size=sm"
                            )
                            .classes(
                                "flex-1 bg-gray-700 text-white border-1 border-gray-500 text-sm input-field"
                            )
                        )
                        ui.button("Select Files", icon="folder_open").on_click(
                            lambda: [pick_files(zta_path, "ZTA")]
                        ).classes(
                            "bg-gray-600 text-white border-1 border-gray-500 hover:bg-gray-600 text-sm px-2"
                        ).props("flat dense size=sm")

                with ui.column().classes("gap-2 w-full"):
                    ui.label("Palette File").classes("text-gray-400")

                    with ui.row().classes("gap-2 w-full items-stretch items-center"):
                        pal_path = (
                            ui.input(placeholder="No file selected")
                            .props(
                                "readonly dense outlined dark clearable hide-bottom-space size=sm"
                            )
                            .classes(
                                "flex-1 bg-gray-700 text-white border-1 border-gray-500 text-sm input-field"
                            )
                        )
                        ui.button("Select Files", icon="folder_open").on_click(
                            lambda: [
                                pick_files(
                                    pal_path,
                                    "Palette",
                                    required_types=[("Palette files", "*.pal")],
                                )
                            ]
                        ).classes(
                            "bg-gray-600 text-white border-1 border-gray-500 hover:bg-gray-600 text-sm px-2"
                        ).props("flat dense size=sm")

                with ui.row().classes("gap-2 mt-4 w-full"):
                    ui.space()
                    ui.button("Cancel", icon="cancel").on_click(dialog.close).classes(
                        "bg-gray-600 text-white border-1 border-gray-500 hover:bg-gray-600 text-sm"
                    ).props("flat size=sm")
                    ui.button("Load", icon="save").on_click(
                        lambda: [confirm(dialog, zta_path, pal_path)]
                    ).classes(
                        "bg-gray-600 text-white border-1 border-gray-500 hover:bg-gray-600 text-sm"
                    ).props("flat size=sm")

            dialog.open()

        def confirm(dialog, zta, palette):
            print(f"Confirming files: {zta.value}, {palette.value}")
            if not zta.value or not palette.value:
                ui.notify(
                    "Please select both a ZTA file and a palette file", color="red"
                )
                return

            zta_location = zta.value
            pal_location = palette.value

            # convert tuple to string (get first item)
            converter_state.loaded_zta_files.append(
                ZtaFile(
                    location=zta_location,
                    buffer=b"",
                    palette_location=pal_location,
                    palette_buffer=b"",
                )
            )
            dialog.close()
            quick_validate_files()
            ztaf = ZtaF()
            zta_obj = ztaf.load(zta_location, 0, pal_location)
            if zta_obj:
                buffer = ztaf.get_frame_buffer()
                converter_state.loaded_zta_files[-1].buffer = buffer
                converter_state.converted_signals = [
                    signal_to_raw(
                        signal.pixels, signal.width, signal.height, signal.channels
                    )
                    for signal in buffer
                ]
                converter_state.current_frame_index = 0
            else:
                ui.notify("Error loading ZTA file", color="gray")
            refresh_file_list()

        def pick_files(target_input, filetype, required_types=[]):
            root = tk.Tk()
            root.withdraw()  # hides window
            root.attributes("-topmost", True)  # brings to front
            root.focus_force()  # focuses window
            filetypes = required_types if required_types else [("All files", "*.*")]
            path = filedialog.askopenfilename(
                title=f"Select {filetype} file", filetypes=filetypes
            )
            root.destroy()
            if path:
                target_input.value = path

        ui.timer(0, show_zta_dialog, once=True)

    def update_transparent_background(checked):
        converter_state.transparent_background = checked
        background_options.refresh()

    def update_background_color(color):
        converter_state.background_color = color
        print(f"Background color: {converter_state.background_color}")
        background_options.refresh()

    def update_export_format(format):
        converter_state.export_format = format
        print(f"Export format: {converter_state.export_format}")

    def update_dpi(dpi):
        converter_state.dpi = dpi
        print(f"DPI: {converter_state.dpi}")

    def update_bitdepth(bitdepth):
        converter_state.bitdepth = bitdepth
        print(f"Bit depth: {converter_state.bitdepth}")

    def update_optimize(optimize):
        converter_state.optimize = optimize
        print(f"Optimized: {converter_state.optimize}")

    def update_interlace(interlace):
        converter_state.interlace = interlace
        print(f"Interlaced: {converter_state.interlace}")

    def update_compression(compression):
        converter_state.compression_level = compression
        print(f"Compression: {converter_state.compression_level}")

    def truncate_filename(filename, max_length=30):
        if len(filename) <= max_length:
            return filename
        else:
            return filename[: max_length // 2] + "..." + filename[-max_length // 2 :]

    def quick_validate_files():
        seen = set()
        valid = []

        for zta_file in list(converter_state.loaded_zta_files):
            # if it has an extension, invalid file
            print(f"Validating file: {zta_file.location}")
            if "." in zta_file.location.split("/")[-1]:
                ui.notify(f"Invalid file skipped: {zta_file.location}", color="gray")
            elif zta_file.location in seen:
                ui.notify(f"Duplicate file skipped: {zta_file.location}", color="gray")
            else:
                seen.add(zta_file.location)
                valid.append(zta_file)
        converter_state.loaded_zta_files = valid

    def refresh_file_list():
        if file_list is None:
            return
        file_list.clear()
        with file_list:
            if not converter_state.loaded_zta_files:
                ui.label("No files loaded").classes("text-gray-500")
            else:
                for zta_file in converter_state.loaded_zta_files:
                    with ui.row().classes("items-center w-full"):
                        with ui.row().classes("items-center gap-2"):
                            ui.icon("image").classes("text-gray-400")
                            with ui.label(truncate_filename(zta_file.location)).classes(
                                "text-gray-300"
                            ):
                                ui.tooltip(zta_file.location).props(
                                    'anchor="bottom left" self="top left"'
                                )
                        ui.space()
                        ui.button(icon="close").classes(
                            "text-gray-400 hover:text-gray-300"
                        ).props("flat dense").on_click(
                            lambda zta_file=zta_file: delete_file(zta_file)
                        )
        print("Refresh file list")

    def delete_file(zta_file):
        converter_state.loaded_zta_files.remove(zta_file)
        refresh_file_list()

    def data_to_files(zta_files, export_format):
        for zta_file in zta_files:
            print(f"Converting {zta_file.location} to {export_format}")

            bg = None
            if not converter_state.transparent_background:
                bg = converter_state.background_color
            else:
                bg = (0, 0, 0, 0)

            if export_format == "PNG":
                img = Image.new("RGBA", (zta_file.width, zta_file.height), bg)
                img.save(zta_file.location.replace(".zta", ".png"))
            elif export_format == "GIF":
                # GIF conversion
                pass
        else:
            print("Unsupported export format")

    async def export_images():
        ui.notify("Exporting images... (this may take a moment)", color="blue")
        # grab the current state
        state = converter_state.copy()
        await run.io_bound(data_to_files, state.loaded_zta_files, state.export_format)
        ui.notify("Export complete!", color="green")

    def export_dialog():
        async def show_export_dialog():
            with (
                ui.dialog().props("persistent") as dialog,
                ui.card().classes(
                    "bg-gray-800 text-white min-w-[600px] p-4 gap-4 rounded-lg border border-gray-700"
                ),
            ):
                ui.label("Export Frames").classes("text-lg")

                with ui.column().classes("gap-2 w-full"):
                    ui.label("Destination").classes("text-gray-400")

                    with ui.row().classes("gap-2 w-full items-stretch items-center"):
                        out_path = (
                            ui.input(placeholder="No file selected")
                            .props(
                                "readonly dense outlined dark clearable hide-bottom-space size=sm"
                            )
                            .classes(
                                "flex-1 bg-gray-700 text-white border-1 border-gray-500 text-sm input-field"
                            )
                        )
                        ui.button("Select Path", icon="folder_open").on_click(
                            lambda: out_path.set_value(pick_path())
                        ).classes(
                            "bg-gray-600 text-white border-1 border-gray-500 hover:bg-gray-600 text-sm px-2"
                        ).props("flat dense size=sm")

                with ui.row().classes("gap-2 mt-4 w-full"):
                    ui.space()
                    ui.button("Cancel", icon="cancel").on_click(
                        lambda: [out_path.set_value(""), dialog.close()]
                    ).classes(
                        "bg-gray-600 text-white border-1 border-gray-500 hover:bg-gray-600 text-sm px-2"
                    ).props("flat dense size=sm")
                    ui.button("Save", icon="save").on_click(
                        lambda: [handle_save(out_path)]
                    ).classes(
                        "bg-gray-600 text-white border-1 border-gray-500 hover:bg-gray-600 text-sm px-2"
                    ).props("flat dense size=sm")

            dialog.open()

        def pick_path():
            root = tk.Tk()
            root.withdraw()  # Hide the main window
            file_path = filedialog.asksaveasfile(
                title="Save file",
                filetypes=[(f"{converter_state.export_format.capitalize()} files", f"*.{converter_state.export_format.lower()}")]
            )
            return file_path
        
        def handle_save(out_path):
            file_path = pick_path()
            if file_path:
                out_path.set_value(file_path)

        ui.timer(0, show_export_dialog, once=True)

    @ui.refreshable
    def background_options():
        is_disabled = converter_state.transparent_background
        disable_cls = (
            "opacity-60 cursor-not-allowed pointer-events-none" if is_disabled else ""
        )

        with (
            ui.card()
            .classes(f"bg-transparent shadow-none w-full p-0 {disable_cls}")
            .props("dense")
        ):
            with ui.column().classes(
                "bg-transparent w-full border-gray-600 rounded-sm gap-2 flex-nowrap text-sm"
            ):
                with ui.row().classes(
                    f"items-center w-full bg-transparent {disable_cls}"
                ):
                    ui.label("Pick background color").classes(
                        f"text-gray-400 text-sm {disable_cls}"
                    ).props("dense size=sm")
                    with (
                        ui.button(icon="colorize")
                        .props(f"dense size=sm {'disable' if is_disabled else ''}")
                        .classes(disable_cls) as button
                    ):
                        ui.color_picker(
                            on_pick=lambda e: button.classes(f"!bg-[{e.color}]")
                        ).props("flat dense size=sm")

    # ----------------- Convert Dashboard -----------------
    with ui.row().classes("items-stretch w-full gap-0 h-full overflow-hidden"):
        # ------------------ Left column: file list and canvas ------------------
        with ui.column().classes("flex-1 gap-0 min-h-0 overflow-hidden"):
            convert_actions.convert_actions(load=load_files)
            # ------------------ CANVAS CONTAINER ------------------
            with ui.card().classes(
                "flex flex-1 flex-col min-h-0 p-0 bg-transparent shadow-none rounded-lg w-full overflow-hidden object-none items-center justify-center"
            ):
                canvas_image = canvas.canvas()

        # ------------------ Right column: export options ------------------
        with ui.column().classes(
            "shrink-0 p-2 min-w-[300px] min-h-0 overflow-y-auto bg-gray-800 border-l border-gray-600 gap-2 text-sm"
        ):
            ui.button("Export", icon="save", on_click=lambda: export_dialog()).classes(
                "bg-gray-600 text-white border-1 border-gray-500 hover:bg-gray-600 text-sm w-full"
            ).props("flat size=sm")

            ui.select(
                options=["PNG", "GIF"], value="PNG", label="Export Format"
            ).classes("w-full bg-gray-700 text-gray-400 export-select").props(
                'dense rounded input-class="text-sm" label-class="text-sm"'
            )
            # if transparency off, choose color
            with (
                ui.expansion()
                .classes("text-gray-400 rounded-lg bg-gray-700 w-full hover:rounded-lg")
                .props("dense rounded") as expansion
            ):
                with expansion.add_slot("header"):
                    with ui.row().classes("items-center w-full gap-0"):
                        check = ui.checkbox(
                            value=True,
                            on_change=lambda e: update_transparent_background(e.value),
                        ).props("dense size=sm")
                        ui.label("Transparent Background").classes("ml-2 mr-2")

                background_options()

            # png export options
            # quality slider for png
            with ui.column().classes(
                "p-2 w-full bg-gray-700 rounded-lg gap-2 flex-nowrap "
            ):
                with ui.row().classes("items-center w-full gap-0"):
                    ui.label("Compression").classes("text-gray-400 mr-2")
                    ui.icon("info").classes("text-gray-400").tooltip(
                        "Higher values mean better compression but slower encoding"
                    ).props("dense size=xs")
                slider = (
                    ui.slider(
                        min=0,
                        max=9,
                        value=0,
                        on_change=lambda e: update_compression(e.value),
                    )
                    .props("dense")
                    .classes("px-4")
                )
                ui.label().bind_text_from(slider, "value").classes("text-gray-400")
            with (
                ui.expansion()
                .classes("text-gray-400 rounded-lg bg-gray-700 w-full hover:rounded-lg")
                .props("dense rounded") as expansion
            ):
                with expansion.add_slot("header"):
                    with ui.row().classes("items-center w-full gap-0"):
                        ui.label("Advanced").classes("text-gray-400")
                ui.checkbox(
                    "Interlaced", on_change=lambda e: update_interlace(e.value)
                ).classes("text-gray-400 text-sm").props(
                    'dense size=sm label-class="text-sm"'
                )
                ui.checkbox(
                    "Optimize", on_change=lambda e: update_optimize(e.value)
                ).classes("text-gray-400 text-sm").props(
                    'dense size=sm label-class="text-sm"'
                )
                ui.select(
                    options=["8", "16", "24"],
                    value="8",
                    label="Bit Depth",
                    on_change=lambda e: update_bitdepth(e.value),
                ).classes("w-full bg-gray-600 text-gray-400 export-select").props(
                    'dense rounded input-class="text-sm" label-class="text-sm"'
                )
                ui.number(
                    value=72, label="DPI", on_change=lambda e: update_dpi(e.value)
                ).classes("number-input w-full bg-gray-600").props("""
                        dense
                        label-color='grey-6'
                        input-class='text-gray-400'
                    """)
