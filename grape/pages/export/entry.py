from nicegui import ui

from grape.pages.export.components.canvas import canvas_display
from grape.pages.export.components.settings import (
    background_options,
    export_button,
    select_export_format,
    compression_slider,
    advanced_options,
)
from grape.pages.export.components.dialogs import load_files
from grape.shared.theme import grape_theme_apply
from grape.shared.layout import base


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


def run():
    """
    Converts ZTA files to other image formats.
    """
    grape_theme_apply()

    with base.frame(
        "Export ZTA graphic as new image format",
        active_item="Home",
        components=[dashboard],
    ):
        pass
