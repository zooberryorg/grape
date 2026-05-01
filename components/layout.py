from contextlib import contextmanager
from nicegui import ui
import webview
import os
from components.sidebar import Sidebar
import pygetwindow as gw


def closeApp():
    gw.getWindowsWithTitle("GrAPE")[0].close()
    # os._exit(0) # forcefully exits all threads and processes, disable during dev


class WindowAPI:
    def minimize(self):
        webview.windows[0].minimize()

    def toggle_maximize(self):
        w = webview.windows[0]
        if w.maximized:
            w.restore()
        else:
            w.maximize()

    def close(self):
        webview.windows[0].destroy()

    def start_resize(self, direction):
        webview.windows[0].start_drag_resize(direction)


def closeApp():
    gw.getWindowsWithTitle("GrAPE")[0].close()
    # os._exit(0) # forcefully exits all threads and processes, disable during dev


class WindowAPI:
    def minimize(self):
        webview.windows[0].minimize()

    def toggle_maximize(self):
        w = webview.windows[0]
        if w.maximized:
            w.restore()
        else:
            w.maximize()

    def close(self):
        webview.windows[0].destroy()

    def start_resize(self, direction):
        webview.windows[0].start_drag_resize(direction)


@contextmanager
def frame(navtitle: str, active_item: str = None, components: list = None):
    """
    Context manager for GrAPE app
    """
    ui.query(".nicegui-content").classes("p-0 m-0")
    ui.query("html, body").style("height: 100%; overflow: hidden; margin: 0; padding: 0;")
    with ui.header().classes("bg-gray-800 text-white p-4 pywebview-drag-region"):
        with ui.row():
            ui.icon("photo_library").classes("text-gray-400")
            ui.space()
            ui.label(navtitle).classes("text-md")
            ui.space()
            with (
                ui.row()
                .classes("gap-2 pywebview-no-drag-region")
                .style("margin-right: -8px;")
                .props("no-wrap")
            ):
                ui.button(icon="minimize").props("flat").classes(
                    "text-gray-400 hover:text-gray-300"
                ).on_click(lambda: ui.run_javascript("window.pywebview.api.minimize()"))
                ui.button(icon="crop_square").props("flat").classes(
                    "text-gray-400 hover:text-gray-300"
                ).on_click(
                    lambda: ui.run_javascript("window.pywebview.api.toggle_maximize()")
                )
                ui.button(icon="close").props("flat").classes(
                    "text-gray-400 hover:text-gray-300"
                ).on_click(closeApp)

    # Main content area
    with ui.row().classes(
        "flex-nowrap items-stretch w-full gap-0 bg-gray-800 h-screen overflow-hidden p-0 m-0"
    ):
        # Sidebar
        Sidebar(active_item=active_item)()

        # Main content
        with (
            ui.column()
            .classes(
                "items-stretch bg-gray-700 w-full gap-1 flex-1 min-h-0 border-l "
                "border-t border-b border-gray-600 rounded-tl-lg rounded-bl-lg "
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
    with ui.footer().classes("bg-gray-800 text-white py-2 px-4 text-center"):
        with ui.row().classes("items-center justify-center"):
            ui.label("Problems").classes("text-sm text-gray-400")
            ui.label("Terminal").classes("text-sm text-gray-400")

    yield
