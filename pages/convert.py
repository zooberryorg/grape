from nicegui import ui
from components import layout, convert_dashboard, theme


@ui.page("/convert")
def convert():
    """
    Converts ZTA files to other image formats.
    """
    theme.apply()

    with layout.frame(
        "Export ZTA graphic as new image format",
        active_item="Dashboard",
        components=[convert_dashboard.convert_dashboard],
    ):
        pass
