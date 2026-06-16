from nicegui import ui
from pathlib import Path


def add_style(path, type=None, shared=True):
    ui.add_head_html(
        f"""
        <link href="{path}" rel="stylesheet" {f'type="{type}"' if type else ""}>
        """,
        shared=shared,
    )


def add_inline_style_from_file(path, shared=True):
    ui.add_head_html(
        f"""
        <style>
        {Path(path).read_text()}
        </style>
        """,
        shared=shared,
    )


def add_script(path, shared=True):
    ui.add_head_html(
        f"""
        <script src="{path}"></script>
        """,
        shared=shared,
    )
