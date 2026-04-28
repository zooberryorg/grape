from nicegui import ui
from templates import default
from urls import create

@ui.page('/')
def main_page():
    with default('GrAPE'):
        pass


ui.run(native=True)