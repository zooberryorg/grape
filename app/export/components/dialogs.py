from nicegui import ui, run
from data.state import converter_state, ZtaFile
from pyzta import ZtaF
from app.export.files import quick_validate_files, signal_to_raw
import tkinter as tk
from tkinter import filedialog
from PIL import Image


def load_files():
    async def show_zta_dialog():
        with (
            ui.dialog().props("persistent") as dialog,
            ui.card().classes(
                "bg-pine-800 text-white min-w-[600px] p-4 gap-4 rounded-lg border border-gray-700"
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
                            "flex-1 bg-pine-600 text-white border-1 border-gray-500 text-sm input-field"
                        )
                    )
                    ui.button("Select Files", icon="folder_open").on_click(
                        lambda: [pick_files(zta_path, "ZTA")]
                    ).classes(
            "bg-pine-800 text-white/50 border-1 border-pine-b gap-1 " \
            "grape-button text-sm items-center justify-center hover:bg-pine-800/70 px-3"
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
                            "flex-1 bg-pine-600 text-white border-1 border-gray-500 text-sm input-field"
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
            "bg-pine-800 text-white/50 border-1 border-pine-b gap-1 " \
            "grape-button text-sm items-center justify-center hover:bg-pine-800/70 px-3"
                    ).props("flat dense size=sm")

            with ui.row().classes("gap-2 mt-4 w-full"):
                ui.space()
                ui.button("Cancel", icon="cancel").on_click(dialog.close).classes(
            "bg-pine-800 text-white/50 border-1 border-pine-b gap-1 " \
            "grape-button text-sm items-center justify-center hover:bg-pine-800/70 px-3"
                ).props("flat size=sm")
                ui.button("Load", icon="save").on_click(
                    lambda: [confirm(dialog, zta_path, pal_path)]
                ).classes(
            "bg-pine-800 text-white/50 border-1 border-pine-b gap-1 " \
            "grape-button text-sm items-center justify-center hover:bg-pine-800/70 px-3"
                ).props("flat size=sm")

        dialog.open()

    def confirm(dialog, zta, palette):
        print(f"Confirming files: {zta.value}, {palette.value}")
        if not zta.value or not palette.value:
            ui.notify("Please select both a ZTA file and a palette file", color="red")
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


def export_dialog():
    async def show_export_dialog():
        with (
            ui.dialog().props("persistent") as dialog,
            ui.card().classes(
                "bg-pine-800 text-white min-w-[600px] p-4 gap-4 rounded-lg border border-gray-700"
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
                            "flex-1 bg-pine-600 text-white border-1 border-gray-500 text-sm input-field"
                        )
                    )
                    ui.button("Select Path", icon="folder_open").on_click(
                        lambda: pick_path(out_path)
                    ).classes(
            "bg-pine-800 text-white/50 border-1 border-pine-b gap-1 " \
            "grape-button text-sm items-center justify-center hover:bg-pine-800/70 px-3"
                    ).props("flat dense size=sm")

            with ui.row().classes("gap-2 mt-4 w-full"):
                ui.space()
                ui.button("Cancel", icon="cancel").on_click(
                    lambda: [out_path.set_value(""), dialog.close()]
                ).classes(
            "bg-pine-800 text-white/50 border-1 border-pine-b gap-1 " \
            "grape-button text-sm items-center justify-center hover:bg-pine-800/70 px-3"
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
            "bg-pine-800 text-white/50 border-1 border-pine-b gap-1 " \
            "grape-button text-sm items-center justify-center hover:bg-pine-800/70 px-3"
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
