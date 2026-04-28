from nicegui import ui


def convert_actions():
    with ui.row().classes("gap-2 ml-4 mt-4"):
        ui.button("Load ZTA...").classes(
            "bg-gray-600 text-white border-1 border-gray-500 hover:bg-gray-600"
        ).props("flat")
