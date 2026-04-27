from nicegui import ui
from templates import default
from urls import url
    
@ui.page('/')
def main_page():
    with default.frame('GrAPE'):
        pass


ui.run(native=True)