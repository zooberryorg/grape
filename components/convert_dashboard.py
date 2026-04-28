from nicegui import ui, run
from components import canvas, convert_actions
import tkinter as tk
from tkinter import filedialog
import asyncio

from data.state import ZtaFile, converter_state


def convert_dashboard():
    # ------------------- UI State -------------------
    file_list = None

    # ------------------ Event handlers ------------------
    def load_files():
        async def show_zta_dialog():
            with ui.dialog() as dialog, ui.card().classes("bg-gray-800 text-white"):
                ui.label("Load ZTA files from your computer").classes("text-lg")
                zta_path = ui.input(placeholder="No file selected").props("readonly dense outlined dark clearable")
                ui.button("Select Files", icon="folder_open").on_click(
                    lambda: [pick_files(zta_path), dialog.close()]
                ).classes("mt-4 bg-gray-600 hover:bg-gray-700")

            dialog.open()

        def confirm(dialog, zta, palette):
            if not zta or not palette:
                ui.notify("Please select both a ZTA file and a palette file", color="red")
                return
            converter_state.loaded_zta_files.append(
                ZtaFile(location=zta.value, buffer=b"", palette_location=palette.value, palette_buffer=b"")
            )
            dialog.close()
            quick_validate_files()
            refresh_file_list()

        def pick_files(target_input):
            root = tk.Tk()
            root.withdraw()  # hides window
            root.attributes("-topmost", True)  # brings to front
            root.focus_force()  # focuses window
            filetypes = [("All files", "*.*")]
            path = filedialog.askopenfilenames(title="Select ZTA files", filetypes=filetypes)
            root.destroy()
            if path:
                target_input.value = path
        
        ui.timer(0, show_zta_dialog, once=True)


    def refresh_canvas():
        file_list.clear()
        with file_list:
            for zta_file in converter_state.loaded_zta_files:
                with ui.item():
                    with ui.item_section():
                        ui.label(zta_file.location)

        print("Refresh canvas")

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
            if "." in zta_file.location.split("/")[-1]:
                ui.notify(f"Invalid file skipped: {zta_file.location}", color="gray")
            elif zta_file.location in seen:
                ui.notify(f"Duplicate file skipped: {zta_file.location}", color="gray")
            else:
                seen.add(zta_file.location)
                valid.append(zta_file)
        converter_state.loaded_zta_files = valid

    def refresh_file_list():
        file_list.clear()
        with file_list:
            if not converter_state.loaded_zta_files:
                ui.label("No files loaded").classes("text-gray-500")
            else:
                for zta_file in converter_state.loaded_zta_files:
                    with ui.row().classes("items-center w-full"):
                        with ui.row().classes("items-center gap-2"):
                            ui.icon("image").classes("text-gray-400")
                            with ui.label(truncate_filename(zta_file.location)).classes("text-gray-300"):
                                ui.tooltip(zta_file.location).props('anchor="bottom left" self="top left"')
                        ui.space()
                        ui.button(icon="close").classes(
                            "text-gray-400 hover:text-gray-300"
                        ).props("flat dense").on_click(lambda zta_file=zta_file: delete_file(zta_file))
        print("Refresh file list")

    def delete_file(zta_file):
        converter_state.loaded_zta_files.remove(zta_file)
        refresh_file_list()

    async def export_image():
        ui.notify("Exporting image... (this may take a moment)", color="blue")
        # await run.io_bound(export_files, converter_state.loaded_zta_files, converter_state.export_format)
        ui.notify("Export complete!", color="green")

    # ----------------- Convert Dashboard -----------------
    with ui.row().classes("items-stretch w-full gap-1 h-screen"):
        with ui.column().classes("flex-1 gap-0"):
            convert_actions.convert_actions(load=load_files)
            # ------------------ Canvas area ------------------
            canvas.canvas()

            # ------------------ File list ------------------
            ui.label("Imported files").classes("text-gray-400 mx-5 mt-[-2]").props(
                "dense"
            )
            with ui.column().classes(
                "p-4 mx-4 mt-4 w-full bg-gray-800 border-1 border-gray-600 h-full shadow-none rounded-lg"
            ):
                file_list = ui.list().classes("w-full")

        with ui.column().classes(
            "shrink-0 p-4 ml-8 min-w-[300px] h-full bg-gray-800 border-l border-gray-600 gap-4"
        ):
            ui.button("Export", icon="save").classes("w-full text-white").props("flat")
            ui.select(
                options=["PNG", "GIF"], value="PNG", label="Export Format"
            ).classes("w-full bg-gray-700 text-gray-400 export-select").props(
                "dense outlined"
            )
            # if transparency off, choose color
            with ui.column().classes(
                "p-2 bg-transparent border-1 w-full border-gray-600 rounded-sm gap-2 flex-nowrap "
            ):
                with ui.row().classes("items-center w-full"):
                    ui.label("Pick background color").classes("text-gray-400")
                    ui.space()
                    with ui.button(icon="colorize") as button:
                        ui.color_picker(
                            on_pick=lambda e: button.classes(f"!bg-[{e.color}]")
                        ).props("flat dense")
                ui.switch("Transparent Background", value=True).classes(
                    "text-gray-400"
                ).props("dense")

            # png export options
            # quality slider for png
            with ui.column().classes(
                "p-2 bg-transparent border-1 w-full border-gray-600 rounded-sm gap-2 flex-nowrap "
            ):
                ui.label("Quality").classes("text-gray-400")
                slider = (
                    ui.slider(min=0, max=100, value=50).props("dense").classes("px-4")
                )
                ui.label().bind_text_from(slider, "value").classes("text-gray-400")
            with ui.column().classes(
                "p-2 bg-transparent border-1 w-full border-gray-600 rounded-sm gap-2 flex-nowrap "
            ):
                ui.label("Advanced").classes("text-gray-400")
                ui.checkbox("Interlaced").classes("text-gray-400").props("dense")
                ui.checkbox("Optimize").classes("text-gray-400").props("dense")
