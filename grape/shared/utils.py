from nicegui import ui

def add_style(path):
    ui.add_html(
        f"""
        <style src="{path}"></style>
        """,
    )

def add_script(path):
    ui.add_html(
        f"""
        <script src="{path}"></script>
        """,
    )