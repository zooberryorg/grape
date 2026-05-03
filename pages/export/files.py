def signal_to_raw(pixels, width, height, channels) -> dict:
    """Convert to RGBA raw array for canvas rendering"""
    mode = {1: "L", 3: "RGB", 4: "RGBA"}.get(channels, "RGBA")
    img = Image.frombytes(mode, (width, height), bytes(pixels))
    img = img.convert("RGBA")  # canvas always needs RGBA
    return {
        "pixels": list(img.tobytes()),  # flat RGBA array
        "width": width,
        "height": height,
    }


def truncate_filename(filename, max_length=30):
    if len(filename) <= max_length:
        return filename
    else:
        return filename[: max_length // 2] + "..." + filename[-max_length // 2 :]


def quick_validate_files():
    seen = set()
    valid = []

    for zta_file in list(converter_state.loaded_zta_files):
        # if it has an extension, invalid file
        print(f"Validating file: {zta_file.location}")
        if "." in zta_file.location.split("/")[-1]:
            ui.notify(f"Invalid file skipped: {zta_file.location}", color="gray")
        elif zta_file.location in seen:
            ui.notify(f"Duplicate file skipped: {zta_file.location}", color="gray")
        else:
            seen.add(zta_file.location)
            valid.append(zta_file)
    converter_state.loaded_zta_files = valid


def refresh_file_list():
    if file_list is None:
        return
    file_list.clear()
    with file_list:
        if not converter_state.loaded_zta_files:
            ui.label("No files loaded").classes("text-gray-500")
        else:
            for zta_file in converter_state.loaded_zta_files:
                with ui.row().classes("items-center w-full"):
                    with ui.row().classes("items-center gap-2"):
                        ui.icon("image").classes("text-gray-400")
                        with ui.label(truncate_filename(zta_file.location)).classes(
                            "text-gray-300"
                        ):
                            ui.tooltip(zta_file.location).props(
                                'anchor="bottom left" self="top left"'
                            )
                    ui.space()
                    ui.button(icon="close").classes(
                        "text-gray-400 hover:text-gray-300"
                    ).props("flat dense").on_click(
                        lambda zta_file=zta_file: delete_file(zta_file)
                    )
    print("Refresh file list")


def delete_file(zta_file):
    converter_state.loaded_zta_files.remove(zta_file)
    refresh_file_list()
