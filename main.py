import os

from nicegui import app, ui
from app.home import entry
from app.shared import theme

app.add_static_files('/app/static', os.path.join(os.path.dirname(__file__), 'app/static'))
app.native.window_args["resizable"] = True
app.native.window_args["easy_drag"] = False
app.native.window_args["draggable"] = False
if __name__ in {"__main__", "__mp_main__"}:
    ui.run(native=True, window_size=(1000, 800))
