from nicegui import ui


def canvas():
    with ui.card().classes(
        "w-full flex-1 p-4 m-4 bg-gray-800 border-1 border-gray-600 min-h-[300px] max-h-[300px] shadow-none rounded-lg"
    ):
        with ui.row().classes("items-center"):
            with ui.column().classes("flex-1"):
                pass
