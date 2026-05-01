from nicegui import ui
from data.state import converter_state
import json

def canvas():
    with ui.card().style("display: block;").classes(
        "p-4 my-4 bg-gray-800 shadow-none rounded-lg mx-auto w-fit"
    ):
        placeholder = ui.label("No image loaded").classes("text-gray-400")
        ui.html('<canvas id="zta-canvas" style="image-rendering: pixelated; display: block;"></canvas>')

    last_frame_count = {'n': 0}

    def tick():
        frames = converter_state.converted_signals
        if not frames or len(frames) == last_frame_count['n']:
            return

        last_frame_count['n'] = len(frames)
        placeholder.set_visibility(False)

        width = frames[0]['width']
        height = frames[0]['height']

        # send all pixel arrays to JS once
        frames_json = json.dumps([f['pixels'] for f in frames])
        interval_ms = 100

        ui.run_javascript(f'''
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
        ''')

    ui.timer(0.5, tick)