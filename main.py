from nicegui import app, ui
from pages import dashboard, convert, project

app.native.window_args["resizable"] = True
app.native.window_args["easy_drag"] = False
app.native.window_args["draggable"] = False
ui.run(native=True, frameless=True, window_size=(1000, 800))
