from nicegui import ui
from PIL import Image
from data.state import converter_state

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


def delete_file(zta_file):
    converter_state.loaded_zta_files.remove(zta_file)
