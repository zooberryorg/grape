from nicegui import ui
from components import canvas, convert_actions


def convert_dashboard():
    ui.add_css("""
        .export-select .q-field__control:before {
            border-color: #4B5563 !important;
            transition: none !important;
        }

        .export-select:hover .q-field__control:before {
            border-color: #6B7280 !important;
        }

        .export-select.q-field--focused .q-field__control:before {
            border-color: #4F46E5 !important;
        }

        .export-select .q-field__control {
            background-color: #374151 !important;
        }
        .export-select .q-field__native,
        .export-select .q-field__label,
        .q-select__dropdown-icon {
            color: #9CA3AF !important;
        }

        .export-select-popup {
            background-color: #374151 !important;
        }
        .export-select-popup .q-item {
            color: #F3F4F6 !important;
        }
        .export-select-popup .q-item:hover {
            background-color: #4B5563 !important;
        }
    """)
    with ui.row().classes("items-stretch w-full gap-1 h-screen"):
        with ui.column().classes("flex-1 gap-0"):
            convert_actions.convert_actions()
            canvas.canvas()
            ui.label("Imported files").classes("text-gray-400 mx-5 mt-[-2]").props("dense")
            with ui.column().classes("p-4 mx-4 mt-4 w-full bg-gray-800 border-1 border-gray-600 min-h-[100px] shadow-none rounded-lg"):
                with ui.list().props("dense separator").classes("w-full"):
                    with ui.item().classes("text-gray-300 w-full"):
                        with ui.item_section().props('avatar'):
                            ui.icon("image").classes("text-gray-400")
                        with ui.item_section():
                            ui.label("file1.zta").classes("text-gray-300")
                        with ui.item_section().props("side"):
                            ui.button(icon="close").classes(
                                "text-gray-400 hover:text-gray-300"
                            ).props("flat dense")
                with ui.list().props("dense separator").classes("w-full"):
                    with ui.item().classes("text-gray-300 w-full"):
                        with ui.item_section().props('avatar'):
                            ui.icon("image").classes("text-gray-400")
                        with ui.item_section():
                            ui.label("file2.zta").classes("text-gray-300")
                        with ui.item_section().props("side"):
                            ui.button(icon="close").classes(
                                "text-gray-400 hover:text-gray-300"
                            ).props("flat dense")
                with ui.list().props("dense separator").classes("w-full"):
                    with ui.item().classes("text-gray-300 w-full"):
                        with ui.item_section().props('avatar'):
                            ui.icon("image").classes("text-gray-400")
                        with ui.item_section():
                            ui.label("file3.zta").classes("text-gray-300")
                        with ui.item_section().props("side"):
                            ui.button(icon="close").classes(
                                "text-gray-400 hover:text-gray-300"
                            ).props("flat dense")
                with ui.list().props("dense separator").classes("w-full"):
                    with ui.item().classes("text-gray-300 w-full"):
                        with ui.item_section().props('avatar'):
                            ui.icon("image").classes("text-gray-400")
                        with ui.item_section():
                            ui.label("file4.zta").classes("text-gray-300")
                        with ui.item_section().props("side"):
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
