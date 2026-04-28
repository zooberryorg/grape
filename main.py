from nicegui import app, ui
from components import theme
from pages import dashboard, convert, project


app.on_startup(theme.apply)
ui.run(native=True, frameless=True)
