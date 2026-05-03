from data.state import converter_state
from nicegui import ui

@ui.refreshable
def background_options():
    """
    Ask user if they want a transparent background or a solid background on export.
    """
    is_disabled = converter_state.transparent_background
    disable_cls = (
        "opacity-60 cursor-not-allowed pointer-events-none" if is_disabled else ""
    )

    with (
        ui.card()
        .classes(f"bg-transparent shadow-none w-full p-0 {disable_cls}")
        .props("dense")
    ):
        with ui.column().classes(
            "bg-transparent w-full border-gray-600 rounded-sm gap-2 flex-nowrap text-sm"
        ):
            with ui.row().classes(
                f"items-center w-full bg-transparent {disable_cls}"
            ):
                ui.label("Pick background color").classes(
                    f"text-gray-400 text-sm {disable_cls}"
                ).props("dense size=sm")
                with (
                    ui.button(icon="colorize")
                    .props(f"dense size=sm {'disable' if is_disabled else ''}")
                    .classes(disable_cls) as button
                ):
                    ui.color_picker(
                        on_pick=lambda e: button.classes(f"!bg-[{e.color}]")
                    ).props("flat dense size=sm")
