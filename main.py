from nicegui import ui
from components import layout
from pages import dashboard

  
def entrypoint():
    # start with dashboard
    dashboard()


ui.run(native=True)