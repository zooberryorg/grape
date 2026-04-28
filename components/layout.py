from contextlib import contextmanager
from nicegui import ui
from components import sidebar

@contextmanager
def frame(navtitle: str):
    """
    Context manager for GrAPE app
    """
    with ui.header().classes('bg-gray-800 text-white p-8'):
        ui.label(navtitle).classes('text-2xl font-bold absolute-center')

    # Main content area
    with ui.row().classes('flex-nowrap items-stretch w-full'):

        # Sidebar
        sidebar()

        # Main content
        with ui.column().classes('items-stretch w-full p-4'):

            # 
            with ui.card().classes('flex-1 p-4 bg-gray-200 min-h-[200px]'):
                with ui.row().classes('items-center'):
                    with ui.column().classes('flex-1'):
                        ui.button(icon='add').classes('w-10 h-10 bg-blue-500 text-white')
                        ui.button(icon='remove').classes('w-10 h-10 bg-red-500 text-white')

            with ui.card().classes('flex-1 p-4 items-stretch'):
                with ui.card().classes('p-4 bg-gray-300 flex-1'):
                    ui.label('No project loaded').classes('text-center text-gray-500')
                    ui.button('Load Project').classes('mt-4 bg-blue-500 text-white w-full')
                    ui.button('Create Project').classes('mt-2 bg-green-500 text-white w-full')

        # Footer
    with ui.footer().classes('bg-gray-800 text-white p-4 text-center'):
        with ui.row().classes('items-center justify-center'):
            ui.button(icon='help').classes('w-10 h-10 text-white')

    yield
