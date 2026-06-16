from nicegui import ui
from grape.shared.state import converter_state
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
            '''
            <div style="position: relative; display: inline-block;">
                <canvas id="zta-canvas-background" style="image-rendering: pixelated; display: none;"></canvas>
                <canvas id="zta-canvas" style="image-rendering: pixelated; display: block; position: absolute; top: 0; left: 0;"></canvas>
            </div>
            '''
        )

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
            bg_json = json.dumps(
                {"pixels": frames[-1]["pixels"], "width": frames[-1]["width"], "height": frames[-1]["height"]}
            )

        frames_json = json.dumps([
            {"pixels": f["pixels"], "width": f["width"], "height": f["height"]}
            for f in (frames[:-1] if has_background else frames)
        ])

        ui.run_javascript(f"""
            if (window._ztaTimer) clearInterval(window._ztaTimer);

            // bg frame
            const bgData = {bg_json if bg_json else 'null'};
            if (bgData) {{
                const bgCanvas = document.getElementById("zta-canvas-background");
                bgCanvas.style.display = "block";
                bgCanvas.width = bgData.width;
                bgCanvas.height = bgData.height;
                const bgCtx = bgCanvas.getContext("2d");
                bgCtx.putImageData(
                    new ImageData(new Uint8ClampedArray(bgData.pixels), bgData.width, bgData.height),
                    0, 0
                );
            }}

            // ani frames
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
