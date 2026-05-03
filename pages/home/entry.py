from nicegui import ui
from pages.home.components.navigation import (
    start_navigation,
    quick_action_navigation,
    about_navigation
)
from pages.home.components.recent import projects
from components import layout, theme

def dashboard():
    with ui.column().classes(
        "flex-1 p-4 items-stretch shadow-none min-h-0 overflow-y-auto"
    ):
        with ui.card().classes("p-4 flex-1 gap-0 shadow-none bg-transparent"):
            ui.label("GrAPE").classes(
                "text-2xl font-bold text-center text-gray-300"
            )
            ui.label("The great animal project editor for Zoo Tycoon").classes(
                "text-center text-gray-400"
            )
            start_navigation()
            quick_action_navigation()
            about_navigation()

        with ui.row():
            projects()

@ui.page("/")
def home():
    theme.apply()
    with layout.frame("GrAPE", active_item="Home", components=[dashboard]):
        pass