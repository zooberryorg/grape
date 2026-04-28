from nicegui import ui


def canvas():
    with ui.card().classes(
        "w-full flex-1 p-4 m-4 bg-gray-800 border-1 border-gray-600 "
        "min-h-[300px] max-h-[300px] shadow-none rounded-lg"
    ):
        with ui.column().classes("flex-1 items-center justify-center h-full"):
            img = (
                ui.image()
                .classes("max-h-full max-w-full")
                .style("image-rendering: pixelated; display: none;")
            )
            ui.label("No image loaded").classes("text-gray-400")
    return img
