from nicegui import ui


def convert_actions(load: None):
    with ui.row().classes("gap-2 p-3 border-b border-gray-600 w-full"):
        ui.button("Load Files...", icon="folder_open").classes(
            "bg-gray-600 text-white border-1 border-gray-500 hover:bg-gray-600"
        ).props("flat").on_click(lambda: load())
