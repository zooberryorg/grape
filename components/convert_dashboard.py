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
                            lambda: pick_path(out_path)
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

                    async def on_save():
                        path = out_path.value
                        if not path:
                            ui.notify("Please select a destination path", color="red")
                            return
                        dialog.close()
                        await export_images(out_path)
                        ui.notify("Export complete!", color="green")

                    ui.button("Save", icon="save").on_click(on_save).classes(
                        "bg-gray-600 text-white border-1 border-gray-500 hover:bg-gray-600 text-sm px-2"
                    ).props("flat dense size=sm")

            dialog.open()

        def pick_path(target_path):
            root = tk.Tk()
            root.withdraw()
            root.attributes("-topmost", True)
            directory = filedialog.askdirectory(title="Select directory")
            root.destroy()
            if directory:
                target_path.set_value(directory)
            return None

        def handle_save(out_path):
            pass

        def data_to_files(zta_files, export_format, out_path):
            buffers = []
            for zta_file in zta_files:
                buffers.append(zta_file.buffer)
            for buffer in buffers:
                for index, frame in enumerate(buffer):
                    print(f"Converting {out_path} to {export_format}")

                    bg = None
                    if not converter_state.transparent_background:
                        bg = converter_state.background_color
                    else:
                        bg = (0, 0, 0, 0)

                    if export_format == "PNG":
                        img = Image.frombytes(
                            "RGBA", (frame.width, frame.height), frame.pixels
                        )
                        img.save(f"{out_path}/frame_{index}.png")
                    elif export_format == "GIF":
                        # GIF conversion
                        pass
                    else:
                        print("Unsupported export format")

        async def export_images(out_path):
            ui.notify("Exporting images... (this may take a moment)", color="blue")
            # grab the current state
            await run.io_bound(
                data_to_files,
                converter_state.loaded_zta_files,
                converter_state.export_format,
                out_path.value,
            )
            ui.notify("Export complete!", color="green")

        ui.timer(0, show_export_dialog, once=True)

    # ----------------- Convert Dashboard -----------------
    with ui.row().classes("items-stretch w-full gap-0 h-full overflow-hidden"):
        # ------------------ Left column: file list and canvas ------------------
        
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
