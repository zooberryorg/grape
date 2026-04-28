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
        root = tk.Tk()
        root.withdraw()  # hides window
        root.attributes("-topmost", True)  # brings to front
        root.focus_force()  # focuses window
        filetypes = [("All files", "*.*")]
        paths = filedialog.askopenfilenames(title="Select ZTA files", filetypes=filetypes)
        for path in paths:
            converter_state.loaded_zta_files.append(ZtaFile(location=path, buffer=b"", palette_location="", palette_buffer=b""))
        print("Selected files:", paths)
        quick_validate_files()
        refresh_file_list()

    def refresh_canvas():
        file_list.clear()
        with file_list:
            for zta_file in converter_state.loaded_zta_files:
                with ui.item():
                    with ui.item_section(): ui.label(zta_file.location)
        
        print("Refresh canvas")

    def quick_validate_files():
        for zta_file in list(converter_state.loaded_zta_files):
            # if it has an extension, invalid file
            if "." in zta_file.location.split("/")[-1]:
                converter_state.loaded_zta_files.remove(zta_file)
                ui.notify(f"Invalid file skipped: {zta_file.location}", color="red")
            # if it already exists in the list, skip
            elif any(zta_file.location == existing.location for existing in converter_state.loaded_zta_files if existing != zta_file):
                converter_state.loaded_zta_files.remove(zta_file)
                ui.notify(f"Duplicate file skipped: {zta_file.location}", color="orange")

    def refresh_file_list():
        file_list.clear()
        with file_list:
            for zta_file in converter_state.loaded_zta_files:
                with ui.row().classes("items-center w-full"):
                    with ui.row().classes("items-center gap-2"):
                        ui.icon("image").classes("text-gray-400")
                        ui.label(zta_file.location).classes("text-gray-300")
                    ui.space()
                    ui.button(icon="close").classes(
                        "text-gray-400 hover:text-gray-300"
                    ).props("flat dense")
        print("Refresh file list")

    async def export_image():
        ui.notify("Exporting image... (this may take a moment)", color="blue")
        #await run.io_bound(export_files, converter_state.loaded_zta_files, converter_state.export_format)
        ui.notify("Export complete!", color="green")
    # ----------------- Convert Dashboard -----------------
    with ui.row().classes("items-stretch w-full gap-1 h-screen"):
        with ui.column().classes("flex-1 gap-0"):
            convert_actions.convert_actions(load=load_files)
            canvas.canvas()
            ui.label("Imported files").classes("text-gray-400 mx-5 mt-[-2]").props(
                "dense"
            )
            with ui.column().classes(
                "p-4 mx-4 mt-4 w-full bg-gray-800 border-1 border-gray-600 min-h-[100px] shadow-none rounded-lg"
            ):
                file_list = ui.list().classes("w-full")

        with ui.column().classes(
            "shrink-0 p-4 ml-8 min-w-[300px] h-full bg-gray-800 border-l border-gray-600 gap-4"
        ):
            ui.button("Export", icon="save").classes(
                "w-full text-white"
            ).props("flat")
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
