import os
import sys

from nicegui import app, ui, native
from grape.home import entry
from grape.shared import theme


def get_static_path(relative: str) -> str:
    """
    Resolve the path to a static file.
    """
    if getattr(sys, "frozen", False):
        # if running as a PyInstaller executable
        base = sys._MEIPASS
    else:
        # if running as a normal Python script
        base = os.path.dirname(__file__)
    return os.path.join(base, relative)


# window config 
app.add_static_files("/grape/static", get_static_path("grape/static"))
app.native.window_args["resizable"] = True
app.native.window_args["easy_drag"] = False
app.native.window_args["draggable"] = False

# run the app
if __name__ in {"__main__", "__mp_main__"}:
    ui.run(
        native=True,
        window_size=(900, 600),
        reload=False,
        port=native.find_open_port(),
        title="GrAPE",
        reconnect_timeout=600,
    )
