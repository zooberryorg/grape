from nicegui import ui
from pages.home import base

def url() -> None:
    ui.page('/')(base.home)

if __name__ == '__main__':
    url()