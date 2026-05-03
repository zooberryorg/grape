from data.state import converter_state


def update_transparent_background(checked):
    converter_state.transparent_background = checked


def update_background_color(color):
    converter_state.background_color = color
    print(f"Background color: {converter_state.background_color}")


def update_export_format(format):
    converter_state.export_format = format
    print(f"Export format: {converter_state.export_format}")


def update_dpi(dpi):
    converter_state.dpi = dpi
    print(f"DPI: {converter_state.dpi}")


def update_bitdepth(bitdepth):
    converter_state.bitdepth = bitdepth
    print(f"Bit depth: {converter_state.bitdepth}")


def update_optimize(optimize):
    converter_state.optimize = optimize
    print(f"Optimized: {converter_state.optimize}")


def update_interlace(interlace):
    converter_state.interlace = interlace
    print(f"Interlaced: {converter_state.interlace}")


def update_compression(compression):
    converter_state.compression_level = compression
    print(f"Compression: {converter_state.compression_level}")
