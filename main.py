from nicegui import ui
from components import theme
from pages import dashboard


ui.add_css
  
def entrypoint():
    # start with dashboard
    theme.apply()
    dashboard()


ui.run(native=True)