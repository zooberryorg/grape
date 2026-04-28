from nicegui import ui
from components import layout
from components.welcome_panel import welcome_panel


@ui.page("/")
def dashboard():
    with layout.frame("GrAPE", active_item="Dashboard", components=[welcome_panel]):
        pass
