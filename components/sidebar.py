from nicegui import ui


class Sidebar:
    menu_items = [
        {"icon": "dashboard", "label": "Home", "url": "/"},
        {"icon": "extension", "label": "Projects", "url": "/projects"},
        {"icon": "table_chart", "label": "Datasets", "url": "/datasets"},
        {"icon": "settings", "label": "Settings", "url": "/settings"},
        {"icon": "info", "label": "About", "url": "/about"},
    ]

    def __init__(self, active_item: str = "Home"):
        self.active_item = active_item

    def __call__(self):
        with ui.column().classes(
            "p-4 w-20 bg-gray-800 shrink-0 h-screen overflow-y-auto",
            remove="nicegui-content",
        ):
            for item in self.menu_items:
                btn = ui.button(icon=item["icon"]).props("flat")
                btn.classes("w-full")
                is_active = item["label"] == self.active_item
                if is_active:
                    btn.classes("bg-blue-500 text-white")
                btn.on_click(lambda url=item["url"]: ui.navigate.to(url))
