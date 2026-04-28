from nicegui import ui
from data.state import converter_state

def canvas():
    with ui.card().classes(
        "w-full flex-1 p-4 m-4 bg-gray-800 border-1 border-gray-600 "
        "min-h-[300px] max-h-[300px] shadow-none rounded-lg"
    ):
        with ui.column().classes("flex-1 items-center justify-center h-full"):
            img = (
                ui.image()
                .classes("max-h-full max-w-full")
                .style("image-rendering: pixelated; display: none;")
            )
            placeholder = ui.label("No image loaded").classes("text-gray-400")
    def tick():
        frames = converter_state.converted_signals
        if not frames:
            return
        placeholder.set_visibility(False)
        img.set_visibility(True)
        img.style("display: block;")
        img.set_source(frames[converter_state.current_frame_index])
        converter_state.current_frame_index = (
            converter_state.current_frame_index + 1
        ) % len(frames)

    ui.timer(0.1, tick)
    return img
