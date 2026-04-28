from nicegui import ui
from components import layout

  
@ui.page('/')
def main_page():
    with layout.frame('GrAPE'):
        pass


ui.run(native=True)