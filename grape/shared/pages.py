from nicegui import ui
import grape.pages

with ui.sub_pages as sp:
    sp.add("/", grape.pages.home.entry)