from contextlib import contextmanager
from nicegui import ui
from components.sidebar import Sidebar


@contextmanager
def frame(navtitle: str, active_item: str = None, components: list = None):
    """
    Context manager for GrAPE app
    """
    with ui.header().classes("bg-gray-800 text-white p-8"):
        ui.label(navtitle).classes("text-2xl font-bold absolute-center")

    # Main content area
    with ui.row().classes("flex-nowrap items-stretch w-full"):
        # Sidebar
        Sidebar(active_item=active_item)()

        # Main content
        with ui.column().classes("items-stretch w-full p-4"):
            if components:
                for component in components:
                    component()
            else:
                with ui.card().classes(
                    "flex-1 p-4 items-stretch rounded-lg bg-gray-300"
                ):
                    ui.label("Error loading content").classes(
                        "text-center text-red-500"
                    )

        # Footer
    with ui.footer().classes("bg-gray-800 text-white p-4 text-center"):
        with ui.row().classes("items-center justify-center"):
            ui.label("Problems").classes("text-sm text-gray-400")
            ui.label("Terminal").classes("text-sm text-gray-400")

    yield
