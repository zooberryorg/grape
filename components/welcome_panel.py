from nicegui import ui


def welcome_panel():
    with ui.card().classes('flex-1 p-4 items-stretch'):
        with ui.card().classes('p-4 bg-gray-300 flex-1'):
            ui.label('No project loaded').classes('text-center text-gray-500')
            ui.button('Load Project').classes('mt-4 bg-blue-500 text-white w-full')
            ui.button('Create Project').classes('mt-2 bg-green-500 text-white w-full')
