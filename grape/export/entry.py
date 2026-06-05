from nicegui import ui

from grape.export.components.canvas import canvas_display
from grape.export.components.settings import (
    background_options,
    export_button,
    select_export_format,
    compression_slider,
    advanced_options,
)
from grape.export.components.dialogs import load_files
from grape.shared import theme
from grape.shared import layout


def dashboard():
    # ----------------- Convert Dashboard -----------------
    with ui.row().classes("items-stretch w-full gap-0 h-full overflow-hidden"):
        # ------------------ Left column: file list and canvas ------------------
        canvas_display(load_files)

        # ------------------ Right column: export options ------------------
        with ui.column().classes(
            "shrink-0 p-2 min-w-[300px] min-h-0 overflow-y-auto bg-pine-800 border-l border-pine-b gap-2 text-sm"
        ):
            export_button()
            # select_export_format()
            # # if transparency off, choose color
            # background_options()

            # # png export options
            # # quality slider for png
            # compression_slider()
            # advanced_options()


@ui.page("/convert")
def convert():
    """
    Converts ZTA files to other image formats.
    """
    theme.apply()

    with layout.frame(
        "Export ZTA graphic as new image format",
        active_item="Home",
        components=[dashboard],
    ):
        pass
