from data.state import converter_state
from nicegui import ui
from grape.pages.export.components.dialogs import export_dialog
from grape.pages.export.events import (
    update_compression,
    update_transparent_background,
    update_bitdepth,
    update_optimize,
    update_dpi,
    update_interlace,
)


def color_picker(is_disabled, disable_cls):
    ui.label("Pick background color").classes(
        f"text-gray-400 text-sm {disable_cls}"
    ).props("dense size=sm")
    with (
        ui.button(icon="colorize")
        .props(f"dense size=sm {'disable' if is_disabled else ''}")
        .classes(disable_cls) as button
    ):
        ui.color_picker(on_pick=lambda e: button.classes(f"!bg-[{e.color}]")).props(
            "flat dense size=sm"
        )


@ui.refreshable
def background_options():
    """
    Ask user if they want a transparent background or a solid background on export.
    """
    with (
        ui.expansion()
        .classes("text-gray-400 rounded-lg bg-pine-600 w-full hover:rounded-lg")
        .props("dense rounded") as expansion
    ):
        with expansion.add_slot("header"):
            with ui.row().classes("items-center w-full gap-0"):
                ui.checkbox(
                    value=True,
                    on_change=lambda e: [
                        update_transparent_background(e.value),
                        background_options.refresh(),
                    ],
                ).props("dense size=sm")
                ui.label("Transparent Background").classes("ml-2 mr-2")

        is_disabled = converter_state.transparent_background
        disable_cls = (
            "opacity-60 cursor-not-allowed pointer-events-none" if is_disabled else ""
        )

        with ui.row().classes(f"items-center w-full bg-transparent {disable_cls}"):
            color_picker(is_disabled, disable_cls)


def export_button():
    ui.button("Export", icon="save", on_click=lambda: export_dialog()).classes(
        "bg-gold-400 text-pine-800 border-1 border-pine-b gap-1 focus-button"
        "grape-button text-sm items-center justify-center hover:bg-pine-800/70 px-3 w-full"
    ).props("flat size=sm color=None")


def select_export_format():
    ui.select(options=["PNG", "GIF"], value="PNG", label="Export Format").classes(
        "w-full bg-pine-600 text-gray-400 export-select"
    ).props('dense rounded input-class="text-sm" label-class="text-sm"')


def compression_slider():
    with ui.column().classes("p-2 w-full bg-pine-600 rounded-lg gap-2 flex-nowrap "):
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


def advanced_options():
    with (
        ui.expansion()
        .classes("text-gray-400 rounded-lg bg-pine-600 w-full hover:rounded-lg")
        .props("dense rounded") as expansion
    ):
        with expansion.add_slot("header"):
            with ui.row().classes("items-center w-full gap-0"):
                ui.label("Advanced").classes("text-gray-400")
        ui.checkbox(
            "Interlaced", on_change=lambda e: update_interlace(e.value)
        ).classes("text-gray-400 text-sm").props('dense size=sm label-class="text-sm"')
        ui.checkbox("Optimize", on_change=lambda e: update_optimize(e.value)).classes(
            "text-gray-400 text-sm"
        ).props('dense size=sm label-class="text-sm"')
        ui.select(
            options=["8", "16", "24"],
            value="8",
            label="Bit Depth",
            on_change=lambda e: update_bitdepth(e.value),
        ).classes("w-full bg-pine-400 text-gray-400 export-select").props(
            'dense rounded input-class="text-sm" label-class="text-sm"'
        )
        ui.number(
            value=72, label="DPI", on_change=lambda e: update_dpi(e.value)
        ).classes("number-input w-full bg-pine-400").props("""
                dense
                label-color='grey-6'
                input-class='text-gray-400'
            """)
