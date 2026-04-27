from nicegui import ui
from pages import home

def url() -> None:
    ui.page('/')(home)

if __name__ == '__main__':
    url()