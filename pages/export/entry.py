from nicegui import ui
import asyncio
import base64
from pyzta import ZtaF

from export.components.canvas import canvas_display
from export.components.settings import background_options
from export.components.dialogs import export_dialog

def convert_dashboard():
    # ------------------- UI State -------------------
    canvas_image = None

    # ------------------ Event handlers ------------------

    # ----------------- Convert Dashboard -----------------
    with ui.row().classes("items-stretch w-full gap-0 h-full overflow-hidden"):
        # ------------------ Left column: file list and canvas ------------------
        canvas_display()

        # ------------------ Right column: export options ------------------
        with ui.column().classes(
            "shrink-0 p-2 min-w-[300px] min-h-0 overflow-y-auto bg-gray-800 border-l border-gray-600 gap-2 text-sm"
        ):
            ui.button("Export", icon="save", on_click=lambda: export_dialog()).classes(
                "bg-gray-600 text-white border-1 border-gray-500 hover:bg-gray-600 text-sm w-full"
            ).props("flat size=sm")

            ui.select(
                options=["PNG", "GIF"], value="PNG", label="Export Format"
            ).classes("w-full bg-gray-700 text-gray-400 export-select").props(
                'dense rounded input-class="text-sm" label-class="text-sm"'
            )
            # if transparency off, choose color
            with (
                ui.expansion()
                .classes("text-gray-400 rounded-lg bg-gray-700 w-full hover:rounded-lg")
                .props("dense rounded") as expansion
            ):
                with expansion.add_slot("header"):
                    with ui.row().classes("items-center w-full gap-0"):
                        check = ui.checkbox(
                            value=True,
                            on_change=lambda e: update_transparent_background(e.value),
                        ).props("dense size=sm")
                        ui.label("Transparent Background").classes("ml-2 mr-2")

                background_options()

            # png export options
            # quality slider for png
            with ui.column().classes(
                "p-2 w-full bg-gray-700 rounded-lg gap-2 flex-nowrap "
            ):
                with ui.row().classes("items-center w-full gap-0"):
                    ui.label("Compression").classes("text-gray-400 mr-2")
                    ui.icon("info").classes("text-gray-400").tooltip(
                        "Higher values mean better compression but slower encoding"
                    ).props("dense size=xs")
                slider = (
                    ui.slider(
                        min=0,
                        max=9,
                        value=0,
                        on_change=lambda e: update_compression(e.value),
                    )
                    .props("dense")
                    .classes("px-4")
                )
                ui.label().bind_text_from(slider, "value").classes("text-gray-400")
            with (
                ui.expansion()
                .classes("text-gray-400 rounded-lg bg-gray-700 w-full hover:rounded-lg")
                .props("dense rounded") as expansion
            ):
                with expansion.add_slot("header"):
                    with ui.row().classes("items-center w-full gap-0"):
                        ui.label("Advanced").classes("text-gray-400")
                ui.checkbox(
                    "Interlaced", on_change=lambda e: update_interlace(e.value)
                ).classes("text-gray-400 text-sm").props(
                    'dense size=sm label-class="text-sm"'
                )
                ui.checkbox(
                    "Optimize", on_change=lambda e: update_optimize(e.value)
                ).classes("text-gray-400 text-sm").props(
                    'dense size=sm label-class="text-sm"'
                )
                ui.select(
                    options=["8", "16", "24"],
                    value="8",
                    label="Bit Depth",
                    on_change=lambda e: update_bitdepth(e.value),
                ).classes("w-full bg-gray-600 text-gray-400 export-select").props(
                    'dense rounded input-class="text-sm" label-class="text-sm"'
                )
                ui.number(
                    value=72, label="DPI", on_change=lambda e: update_dpi(e.value)
                ).classes("number-input w-full bg-gray-600").props("""
                        dense
                        label-color='grey-6'
                        input-class='text-gray-400'
                    """)
