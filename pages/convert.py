from nicegui import ui
from components import layout, theme
from pages.export.entry import dashboard


@ui.page("/convert")
def convert():
    """
    Converts ZTA files to other image formats.
    """
    theme.apply()

    with layout.frame(
        "Export ZTA graphic as new image format",
        active_item="Dashboard",
        components=[dashboard],
    ):
        pass
