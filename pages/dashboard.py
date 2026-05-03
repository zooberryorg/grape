from nicegui import ui
from components import layout, theme
from pages.home.entry import dashboard


@ui.page("/")
def home():
    theme.apply()
    with layout.frame("GrAPE", active_item="Home", components=[dashboard]):
        pass
