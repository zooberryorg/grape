from nicegui import app, ui
from pages.home import entry

app.native.window_args["resizable"] = True
app.native.window_args["easy_drag"] = False
app.native.window_args["draggable"] = False
if __name__ in {"__main__", "__mp_main__"}:
    ui.run(native=True, window_size=(1000, 800))
