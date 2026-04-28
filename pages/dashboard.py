from nicegui import ui
from components import layout, theme
from components.welcome_panel import welcome_panel


@ui.page("/")
def dashboard():
    theme.apply()
    with layout.frame("GrAPE", active_item="Dashboard", components=[welcome_panel]):
        pass
