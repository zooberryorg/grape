from nicegui import ui

with ui.header().classes('bg-gray-800 text-white p-8'):
    ui.label('GrAPE').classes('text-2xl font-bold absolute-center')

with ui.row().classes('flex-nowrap items-stretch w-full'):

    with ui.column().classes('p-4 w-20 bg-gray-100 shrink-0'):
        ui.button(icon='dashboard').classes('w-full')
        ui.button(icon='settings').classes('w-full')
        ui.button(icon='info').classes('w-full')

    with ui.column().classes('items-stretch w-full p-4'):

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

ui.run(native=True)