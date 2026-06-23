import os
import sys

from nicegui import app, ui, native
from grape.pages.home import entry
from grape.shared import theme
from grape.shared.theme import grape_theme_apply
from grape.shared.pages import init_pages
from grape.shared.settings import STATIC_DIR

# window config
app.native.window_args["resizable"] = True
app.native.window_args["easy_drag"] = False
app.native.window_args["draggable"] = False

# run the app
if __name__ in {"__main__", "__mp_main__"}:
    init_pages()
    ui.run(
        native=True,
        window_size=(900, 600),
        reload=False,
        port=native.find_open_port(),
        title="GrAPE",
        reconnect_timeout=600,
    )
