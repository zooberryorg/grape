from nicegui import ui
from components import layout, convert_dashboard


@ui.page("/convert")
def convert():
    """
    Converts ZTA files to other image formats.
    """

    with layout.frame(
        "Export ZTA graphic",
        active_item="Dashboard",
        components=[convert_dashboard.convert_dashboard],
    ):
        pass
