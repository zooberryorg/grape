from contextlib import contextmanager
from nicegui import ui
from components.sidebar import Sidebar


@contextmanager
def frame(navtitle: str, active_item: str = None, components: list = None):
    """
    Context manager for GrAPE app
    """
    ui.query(".nicegui-content").classes("p-0 m-0")
    with ui.header().classes("bg-gray-800 text-white p-4"):
        ui.label(navtitle).classes("text-md absolute-center")

    # Main content area
    with ui.row().classes(
        "flex-nowrap items-stretch w-full gap-0 bg-gray-800 h-screen overflow-y-auto p-0 m-0"
    ):
        # Sidebar
        Sidebar(active_item=active_item)()

        # Main content
        with (
            ui.column()
            .classes(
                "items-stretch bg-gray-700 w-full gap-1 h-screen border-l "
                "border-t border-gray-600 rounded-tl-lg rounded-bl-lg "
                "rounded-tr-none rounded-br-none overflow-y-auto"
            )
            .props("square")
        ):
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
    with ui.footer().classes(
        "bg-gray-800 text-white py-2 px-4 text-center border-t border-gray-600"
    ):
        with ui.row().classes("items-center justify-center"):
            ui.label("Problems").classes("text-sm text-gray-400")
            ui.label("Terminal").classes("text-sm text-gray-400")

    yield
