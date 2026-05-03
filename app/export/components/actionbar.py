from nicegui import ui


def actions(load: None):
    with ui.row().classes("gap-2 p-2 border-b border-gray-600 bg-slate-700 w-full"):
        ui.button("Open", icon="folder_open").classes(
            "bg-pine-400 text-white border-1 border-gray-500 hover:bg-pine-400 text-sm"
        ).props("flat size=sm").on_click(lambda: load())
