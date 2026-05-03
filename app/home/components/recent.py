from nicegui import ui


def projects():
    with ui.card().classes("p-4 flex-1 gap-0 shadow-none bg-gray-600 rounded-lg"):
        ui.label("Recent projects").classes(
            "text-2xl font-bold text-center text-gray-300"
        )
        ui.label("No recent projects found").classes("text-center text-gray-400 mt-4")
