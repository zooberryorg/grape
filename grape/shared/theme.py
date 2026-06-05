from nicegui import ui
from grape.shared.utils import add_style, add_script
from grape.shared.settings import STATIC_DIR

def grape_theme_apply():
    ui.query("html, body").classes("h-screen m-0 p-0 flex flex-col overflow-hidden")
    ui.query("html, body, .app").classes("bg-pine-800")
    ui.query(".q-layout").classes("h-screen")
    ui.query(".q-page-container").classes("flex flex-col flex-1 overflow-hidden h-full")
    ui.query(".q-page").classes("flex flex-col flex-1 h-100 overflow-hidden")
    ui.query(".nicegui-content").classes("flex flex-col flex-1 p-0 min-h-0")
    ui.colors(primary="#adadad", shared=True, accent_secondary="#d6b15d")
    add_style(f"{STATIC_DIR}\\grape.css")
    add_style(f"{STATIC_DIR}\\scrollbar.css")
    add_style(f"{STATIC_DIR}\\overrides.css", "text/tailwindcss")
