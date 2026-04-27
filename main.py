from nicegui import ui

with ui.header().classes('bg-gray-800 text-white'):
    ui.label('GrAPE').classes('text-2xl font-bold')

with ui.row().classes('flex-nowrap h-screen flex flex-row'):

    with ui.column().classes('p-4 max-w-[80px] bg-gray-100'):
        ui.button(icon='dashboard').classes('w-full')
        ui.button(icon='settings').classes('w-full')
        ui.button(icon='info').classes('w-full')

    with ui.card().classes('w-full'):
        ui.label('GrAPE').classes('text-2xl font-bold')

ui.run(native=True)