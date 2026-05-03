from nicegui import ui
from data.state import converter_state
import json
from pages.export.components.actionbar import actions


def canvas():
    # CANVAS
    with ui.card().classes(
        "flex flex-1 min-h-0 p-4 bg-transparent shadow-none rounded-lg w-full h-full "
        "hover:border-gray-600 transition-colors items-center justify-center"
    ):
        placeholder_visible = {"value": True}

        with ui.column().classes(
            "w-full h-full items-center justify-center gap-1"
        ) as placeholder:
            if placeholder_visible["value"]:
                ui.icon("image_not_supported").classes("text-gray-400 text-6xl")
                ui.label("No image loaded").classes("text-gray-400")

        ui.html(
            '<canvas id="zta-canvas" style="image-rendering: pixelated; display: block;"></canvas>'
        )

    last_frame_count = {"n": 0}

    def tick():
        frames = converter_state.converted_signals
        if not frames or len(frames) == last_frame_count["n"]:
            return

        last_frame_count["n"] = len(frames)
        placeholder_visible["value"] = False
        placeholder.set_visibility(False)

        width = frames[0]["width"]
        height = frames[0]["height"]

        # send all pixel arrays to JS once
        frames_json = json.dumps([f["pixels"] for f in frames])
        interval_ms = 100

        ui.run_javascript(f"""
            if (window._ztaTimer) clearInterval(window._ztaTimer);

            const canvas = document.getElementById("zta-canvas");
            canvas.width = {width};
            canvas.height = {height};
            const ctx = canvas.getContext("2d");

            const rawFrames = {frames_json};

            // convert each frame to ImageData once, up front
            const frames = rawFrames.map(pixels => {{
                const data = new Uint8ClampedArray(pixels);
                return new ImageData(data, {width}, {height});
            }});

            let idx = 0;
            window._ztaTimer = setInterval(() => {{
                ctx.putImageData(frames[idx], 0, 0);
                idx = (idx + 1) % frames.length;
            }}, {interval_ms});
        """)

    ui.timer(0.5, tick)


def canvas_display(action=None):
    with ui.column().classes("flex-1 gap-0 min-h-0 overflow-hidden"):
        actions(load=action)
        # ------------------ CANVAS CONTAINER ------------------
        with ui.card().classes(
            "flex flex-1 flex-col min-h-0 p-0 bg-transparent shadow-none rounded-lg w-full overflow-hidden object-none items-center justify-center"
        ):
            canvas()
