from nicegui import ui
from components import canvas, convert_actions


def convert_dashboard():
    with ui.row().classes("items-stretch w-full gap-1 h-screen"):
        with ui.column().classes("flex-1 gap-0"):
            convert_actions.convert_actions()
            canvas.canvas()
            ui.label("Imported files").classes("text-gray-400 mx-5 mt-[-2]").props("dense")
            with ui.column().classes("p-4 mx-4 mt-4 w-full bg-gray-800 border-1 border-gray-600 min-h-[100px] shadow-none rounded-lg"):
                for filename in ["file1.zta", "file2.zta", "file3.zta", "file4.zta"]:
                    with ui.row().classes("items-center w-full"):
                        with ui.row().classes("items-center gap-2"):
                            ui.icon("image").classes("text-gray-400")
                            ui.label(filename).classes("text-gray-300")
                        ui.space()
                        ui.button(icon="close").classes(
                            "text-gray-400 hover:text-gray-300"
                        ).props("flat dense")
                
        with ui.column().classes(
            "shrink-0 p-4 ml-8 min-w-[300px] h-full bg-gray-800 border-l border-gray-600 gap-4"
        ):
            ui.button("Export", icon="save").classes(
                "bg-blue-600 w-full text-white"
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
                slider = ui.slider(min=0, max=100, value=50).props("dense").classes("px-4")
                ui.label().bind_text_from(slider, 'value').classes("text-gray-400")
            with ui.column().classes(
                "p-2 bg-transparent border-1 w-full border-gray-600 rounded-sm gap-2 flex-nowrap "
            ):
                ui.label("Advanced").classes("text-gray-400")
                ui.checkbox("Interlaced").classes("text-gray-400").props("dense")
                ui.checkbox("Optimize").classes("text-gray-400").props("dense")
