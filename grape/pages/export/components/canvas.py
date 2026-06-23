from nicegui import ui
from grape.shared.state import converter_state as state
import json
from grape.pages.export.components.actionbar import actions


def canvas():
    # ------------- main canvas bg container -------------
    with ui.card().classes(
        "flex flex-1 min-h-0 p-4 bg-transparent shadow-none rounded-lg w-full h-full "
        "hover:border-pine-b transition-colors items-center justify-center"
    ):
        # ------------ centered placeholder when no image is loaded ------------
        placeholder_visible = {"value": True}
        with ui.column().classes(
            "w-full h-full items-center justify-center gap-1"
        ) as placeholder:
            if placeholder_visible["value"]:
                ui.icon("image_not_supported").classes("text-gray-400 text-6xl")
                ui.label("No image loaded").classes("text-gray-400")

        ui.html(
            '<canvas id="zta-canvas" style="image-rendering: pixelated;"></canvas>'
        ).classes("w-full h-full")

    last_frame_count = {"n": 0}

    def tick():
        if not state.zta_files:
            return
        zta = state.zta_files[-1]
        frames = zta.signals
        if not frames or len(frames) == last_frame_count["n"]:
            return
        last_frame_count["n"] = len(frames)
        placeholder.set_visibility(False)

        has_bg = zta.has_background_frame
        body = frames[:-1] if has_bg else frames
        bg = frames[-1] if has_bg else None
        pick = lambda f: {
            "pixels": f["pixels"],
            "width": f["width"],
            "height": f["height"],
        }

        payload = {
            "regular": [pick(f) for f in body],
            "shadow": [],
            "background": pick(bg) if bg else None,
        }
        ui.run_javascript(f"window.editor.loadStack({json.dumps(payload)})")

    ui.timer(0.5, tick)


def canvas_display(action=None):
    with ui.column().classes("flex-1 gap-0 min-h-0 overflow-hidden"):
        actions(load=action)
        # ------------------ CANVAS CONTAINER ------------------
        with ui.card().classes(
            "flex flex-1 flex-col min-h-0 p-0 bg-transparent shadow-none rounded-lg w-full overflow-hidden object-none items-center justify-center"
        ):
            canvas()
