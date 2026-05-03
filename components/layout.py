from contextlib import contextmanager
from nicegui import ui
from components.sidebar import Sidebar


@contextmanager
def frame(navtitle: str, active_item: str = None, components: list = None):
    """
    Context manager for GrAPE app
    """
    ui.query("html, body").classes("h-screen m-0 p-0 flex flex-col overflow-hidden")
    ui.query("html, body, .app").classes("bg-gray-900")
    ui.query(".q-layout").classes("h-screen")
    ui.query(".q-page-container").classes("flex flex-col flex-1 overflow-hidden h-full")
    ui.query(".q-page").classes("flex flex-col flex-1 h-100 overflow-hidden")
    ui.query(".nicegui-content").classes("flex flex-col flex-1 p-0 min-h-0")
    # Sidebar and content area
    with ui.row().classes(
        "flex-nowrap items-stretch w-full gap-0 bg-gray-800 flex-1 h-full overflow-hidden p-0 m-0"
    ):
        Sidebar(active_item=active_item)()
        # Main content area
        with ui.column().classes(
            "flex-nowrap items-stretch w-full gap-0 bg-gray-800 overflow-hidden p-0 m-0 flex-1 min-h-0"
        ):
            with ui.row().classes(
                "bg-gray-800 text-white p-2 pywebview-drag-region items-center"
            ):
                with ui.row():
                    ui.icon("photo_library").classes("text-gray-400 mt-1")
                    ui.label(navtitle).classes("text-md")
                    ui.space()

            # Main content
            with (
                ui.column()
                .classes(
                    "items-stretch bg-gray-700 w-full gap-1 flex-1 min-h-0 border-l "
                    "border-t border-b border-gray-600 rounded-tl-lg rounded-bl-lg "
                    "rounded-tr-none rounded-br-none overflow-y-auto w-full"
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
            with ui.row().classes(
                "bg-gray-800 text-white py-2 px-4 text-center w-full"
            ):
                with ui.row().classes("items-center justify-center"):
                    ui.label("Problems").classes("text-sm text-gray-400")
                    ui.label("Terminal").classes("text-sm text-gray-400")

        yield
