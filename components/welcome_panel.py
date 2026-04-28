from nicegui import ui


def welcome_panel():
    with ui.card().classes('flex-1 p-4 items-stretch'):
        with ui.card().classes('p-4 bg-gray-300 flex-1'):
            ui.label('GrAPE').classes('text-2xl font-bold text-center text-gray-700')
            ui.label('The great animal project editor for Zoo Tycoon').classes('text-center text-gray-500')
            ui.label('Start').classes('text-center text-gray-500 mt-4 font-bold')
            with ui.column():
                ui.button('New project...', icon='add').props('flat no-caps').classes('h-10')
                ui.button('Load project...', icon='folder_open').props('flat no-caps').classes('h-10')
            ui.label('Quick actions').classes('text-center text-gray-500 mt-4 font-bold')
            with ui.row().classes('items-center justify-center'):
                ui.button('Batch convert ZTA files', icon='file_upload').props('flat no-caps').classes('h-10')
