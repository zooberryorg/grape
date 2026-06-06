from nicegui import ui
from grape.pages.export import entry
from grape.pages.home import entry


class Sidebar:
    menu_items = [
        {"icon": "dashboard", "label": "Home", "url": "/"},
        # {"icon": "extension", "label": "Projects", "url": "/projects"},
        # {"icon": "table_chart", "label": "Datasets", "url": "/datasets"},
        # {"icon": "settings", "label": "Settings", "url": "/settings"},
        # {"icon": "info", "label": "About", "url": "/about"},
    ]

    def __init__(self, active_item: str = "Home"):
        self.active_item = active_item

    def __call__(self):
        with ui.column().classes(
            "p-4 w-20 bg-pine-800 shrink-0 h-screen overflow-y-auto",
            remove="nicegui-content",
        ):
            for item in self.menu_items:
                btn = ui.button(icon=item["icon"]).props("flat")
                btn.classes("w-full")
                is_active = item["label"] == self.active_item
                if is_active:
                    btn.classes("bg-gold-400 text-gold-700")
                    btn.props("color='accent_secondary'")
                btn.on_click(lambda url=item["url"]: ui.navigate.to(url))
