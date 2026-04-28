from nicegui import ui
from components import layout

  
@ui.page('/')
def dashboard():
    with layout.frame('GrAPE', active_item='Dashboard'):
        pass


ui.run(native=True)