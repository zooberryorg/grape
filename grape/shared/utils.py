from nicegui import ui

def add_style(path):
    ui.add_html(
        f"""
        <style src="{path}"></style>
        """,
    )