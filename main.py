from nicegui import ui
from frame_core import frame

@ui.page('/')
def main_page():
    with frame('GrAPE'):
        pass


ui.run(native=True)