from nicegui import ui


def content() -> None:
    ui.label(
        "Welcome to GrAPE, the great animal project editor for Zoo Tycoon"
    ).classes("text-2xl font-bold text-center mt-8")
