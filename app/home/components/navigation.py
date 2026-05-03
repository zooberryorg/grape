from nicegui import ui


def start_navigation():
    ui.label("Start").classes("text-center text-gray-400 mt-4 font-bold")
    with ui.column().classes("gap-0"):
        ui.button("New project...", icon="add").props("flat no-caps").classes("h-10")
        ui.button("Load project...", icon="folder_open").props("flat no-caps").classes(
            "h-10"
        )


def quick_action_navigation():
    ui.label("Quick actions").classes("text-center text-gray-400 mt-4 font-bold")
    with ui.column().classes("gap-0"):
        # ui.button("Resourcer scanner", icon="search").props("flat no-caps").classes(
        #     "h-10"
        # )
        ui.button("Convert ZTA files", icon="file_upload").props(
            "flat no-caps"
        ).classes("h-10").on_click(lambda: ui.navigate.to("/convert"))
        # ui.button("ZTA graphic quick edit", icon="image").props("flat no-caps").classes(
        #     "h-10"
        # )
        # ui.button("Open string table manager", icon="table_view").props(
        #     "flat no-caps"
        # ).classes("h-10")
        # ui.button("Zoo file explorer", icon="folder").props("flat no-caps").classes(
        #     "h-10"
        # )
        # ui.button("ZTD combiner", icon="merge_type").props("flat no-caps").classes(
        #     "h-10"
        # )


def about_navigation():
    ui.label("GrAPE").classes("text-center text-gray-400 mt-4 font-bold")
    with ui.column().classes("gap-0"):
        ui.button("Report a bug", icon="bug_report").props("flat no-caps").classes(
            "h-10"
        )
        ui.button("GrAPE documentation", icon="help").props("flat no-caps").classes(
            "h-10"
        )
        ui.button("About GrAPE", icon="info").props("flat no-caps").classes("h-10")
