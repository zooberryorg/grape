from nicegui import ui
from components import layout, canvas


@ui.page("/convert")
def convert():
    """
    Converts ZTA files to other image formats.
    """

    with layout.frame("GrAPE", active_item="Dashboard", components=[canvas.canvas]):
        pass
