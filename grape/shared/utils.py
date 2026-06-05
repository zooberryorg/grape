from nicegui import ui

def add_style(path, shared=True, type=None):
    ui.add_head_html(
        f"""
        <style src="{path}" {type if type else ''}></style>
        """,
        shared=shared
    )

def add_script(path, shared=True):
    ui.add_head_html(
        f"""
        <script src="{path}"></script>
        """,
        shared=shared
    )