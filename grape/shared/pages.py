from nicegui import ui
from grape.pages import home, export

def init_pages():
    with ui.sub_pages() as sp:
        sp.add("/", home.entry.run)
        sp.add("/convert", export.entry.run)