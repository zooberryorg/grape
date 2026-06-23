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
        self,
        location: str,
        buffer: bytes,
        palette_location: str,
        palette_buffer: bytes,
        has_background_frame: bool = False,
        signals: list = None,
    ):
        self.location = location
        self.buffer = buffer
        self.palette_location = palette_location
        self.has_background_frame = has_background_frame
        self.signals = signals if signals is not None else []


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
    zta_files: list[ZtaFile] = field(default_factory=list)
    export_format_options: list[str] = field(default_factory=lambda: ["PNG", "GIF"])
    has_converted_image: bool = False
    current_frame_index: int = 0
    bit_depth: str = "8"
    compression_level: int = 0


converter_state = ZtaToImageState()
