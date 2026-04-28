from nicegui import app, ui
from components import theme
from pages import dashboard, convert, project

ui.add_head_html('''
    <style>
        ::-webkit-scrollbar { display: none; }
        * {
            -ms-overflow-style: none;
            scrollbar-width: none;
        }
    </style>
    ''', shared=True)
app.native.window_args['resizable'] = True
app.native.window_args['easy_drag'] = False
app.native.window_args['draggable'] = False
ui.run(native=True, frameless=True, window_size=(1000, 600))
