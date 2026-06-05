from nicegui import ui


def actions(load: None):
    with ui.row().classes("gap-2 p-2 border-b border-pine-b bg-pine-deep w-full"):
        ui.button("Open", icon="folder_open").classes(
            "bg-pine-800 text-white/50 border-1 border-pine-b gap-1 "
            "grape-button text-sm items-center justify-center hover:bg-pine-800/70"
        ).props("flat size=sm no-ripple").on_click(lambda: load())
