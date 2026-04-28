from nicegui import ui


def canvas():
    with ui.card().classes("flex-1 p-4 bg-gray-200 min-h-[200px]"):
        with ui.row().classes("items-center"):
            with ui.column().classes("flex-1"):
                ui.button(icon="add").classes("w-10 h-10 bg-blue-500 text-white")
                ui.button(icon="remove").classes("w-10 h-10 bg-red-500 text-white")
