

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

