from dataclasses import dataclass, field


@dataclass
class AppState:
    """
    Holds app state
    """

    zta_file: str = ""
    converted_image: str = ""
    export_format: str = "PNG"


class ZtaFile:
    """
    Represents a ZTA file with its location, buffer, and palette information.
    """

    def __init__(
        self, location: str, buffer: bytes, palette_location: str, palette_buffer: bytes
    ):
        self.location = location
        self.buffer = buffer
        self.palette_location = palette_location


@dataclass
class ZtaToImageState(AppState):
    """
    State specific to ZTA to image conversion
    """

    quality: int = 50
    transparent_background: bool = True
    background_color: str = "#ffffff"
    interlaced: bool = False
    optimize: bool = False
    loaded_zta_files: list[ZtaFile] = field(default_factory=list)
    export_format_options: list[str] = field(default_factory=lambda: ["PNG", "GIF"])
    has_converted_image: bool = False
    converted_signals: list[str] = field(default_factory=list)
    current_frame_index: int = 0


converter_state = ZtaToImageState()
