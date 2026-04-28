from nicegui import ui

class Sidebar():
    menu_items = [
        {'icon': 'dashboard', 'label': 'Dashboard', 'url': '/'},
        {'icon': 'puzzle', 'label': 'Projects', 'url': '/projects'},
        {'icon': 'settings', 'label': 'Settings', 'url': '/settings'},
        {'icon': 'info', 'label': 'About', 'url': '/about'},
    ]

    def __init__(self, active_item: str = 'Dashboard'):
        self.active_item = active_item

    def __call__(self):
        with ui.column().classes('p-4 w-20 bg-gray-100 shrink-0'):
            for item in self.menu_items:
                btn = ui.button(icon=item['icon']).classes('w-full')
                is_active = item['label'] == self.active_item
                if is_active:
                    btn.props('active')
                btn.on_click(lambda url=item['url']: ui.navigate_to(url))
