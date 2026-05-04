from nicegui import ui
from data.state import converter_state
import json
from app.export.components.actionbar import actions


def canvas():
    # CANVAS
    with ui.card().classes(
        "flex flex-1 min-h-0 p-4 bg-transparent shadow-none rounded-lg w-full h-full "
        "hover:border-pine-b transition-colors items-center justify-center"
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

        with ui.html(
            '<canvas id="zta-canvas-background" style="image-rendering: pixelated; display: none;"></canvas>'
        ) as background_canvas:
            pass

    last_frame_count = {"n": 0}

    def tick():
        if not converter_state.loaded_zta_files:
            return

        frames = converter_state.loaded_zta_files[-1].signals
        has_background = converter_state.loaded_zta_files[-1].has_background_frame
        if not frames or len(frames) == last_frame_count["n"]:
            return

        last_frame_count["n"] = len(frames)
        placeholder_visible["value"] = False
        placeholder.set_visibility(False)

        bg_json = None
        if has_background:
            # Show the background frame
            background_canvas.set_style("display", "block")
            bg_json = json.dumps(
                {"pixels": frames[0]["pixels"], "width": frames[0]["width"], "height": frames[0]["height"]}
            )

        # frames object
        frames_json = json.dumps(
            [
                {"pixels": f["pixels"], "width": f["width"], "height": f["height"]}
                for f in (frames[-1:] if has_background else frames)
            ]
        )

        ui.run_javascript(f"""
            if (window._ztaTimer) clearInterval(window._ztaTimer);
            const canvas = document.getElementById("zta-canvas");
            const ctx = canvas.getContext("2d");

            const rawFrames = {frames_json};
            const frames = rawFrames.map(f => ({{
                imageData: new ImageData(new Uint8ClampedArray(f.pixels), f.width, f.height),
                width: f.width,
                height: f.height,
            }}));

            let idx = 0;
            window._ztaTimer = setInterval(() => {{
                const frame = frames[idx];
                canvas.width = frame.width;
                canvas.height = frame.height;
                ctx.putImageData(frame.imageData, 0, 0);
                idx = (idx + 1) % frames.length;
            }}, 100);
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
