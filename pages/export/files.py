

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

def load_files():
    async def show_zta_dialog():
        with (
            ui.dialog().props("persistent") as dialog,
            ui.card().classes(
                "bg-gray-800 text-white min-w-[600px] p-4 gap-4 rounded-lg border border-gray-700"
            ),
        ):
            ui.label("Load ZTA files from your computer").classes("text-lg")

            with ui.column().classes("gap-2 w-full"):
                ui.label("ZTA File").classes("text-gray-400")

                with ui.row().classes("gap-2 w-full items-stretch items-center"):
                    zta_path = (
                        ui.input(placeholder="No file selected")
                        .props(
                            "readonly dense outlined dark clearable hide-bottom-space size=sm"
                        )
                        .classes(
                            "flex-1 bg-gray-700 text-white border-1 border-gray-500 text-sm input-field"
                        )
                    )
                    ui.button("Select Files", icon="folder_open").on_click(
                        lambda: [pick_files(zta_path, "ZTA")]
                    ).classes(
                        "bg-gray-600 text-white border-1 border-gray-500 hover:bg-gray-600 text-sm px-2"
                    ).props("flat dense size=sm")

            with ui.column().classes("gap-2 w-full"):
                ui.label("Palette File").classes("text-gray-400")

                with ui.row().classes("gap-2 w-full items-stretch items-center"):
                    pal_path = (
                        ui.input(placeholder="No file selected")
                        .props(
                            "readonly dense outlined dark clearable hide-bottom-space size=sm"
                        )
                        .classes(
                            "flex-1 bg-gray-700 text-white border-1 border-gray-500 text-sm input-field"
                        )
                    )
                    ui.button("Select Files", icon="folder_open").on_click(
                        lambda: [
                            pick_files(
                                pal_path,
                                "Palette",
                                required_types=[("Palette files", "*.pal")],
                            )
                        ]
                    ).classes(
                        "bg-gray-600 text-white border-1 border-gray-500 hover:bg-gray-600 text-sm px-2"
                    ).props("flat dense size=sm")

            with ui.row().classes("gap-2 mt-4 w-full"):
                ui.space()
                ui.button("Cancel", icon="cancel").on_click(dialog.close).classes(
                    "bg-gray-600 text-white border-1 border-gray-500 hover:bg-gray-600 text-sm"
                ).props("flat size=sm")
                ui.button("Load", icon="save").on_click(
                    lambda: [confirm(dialog, zta_path, pal_path)]
                ).classes(
                    "bg-gray-600 text-white border-1 border-gray-500 hover:bg-gray-600 text-sm"
                ).props("flat size=sm")

        dialog.open()

    def confirm(dialog, zta, palette):
        print(f"Confirming files: {zta.value}, {palette.value}")
        if not zta.value or not palette.value:
            ui.notify(
                "Please select both a ZTA file and a palette file", color="red"
            )
            return

        zta_location = zta.value
        pal_location = palette.value

        # convert tuple to string (get first item)
        converter_state.loaded_zta_files.append(
            ZtaFile(
                location=zta_location,
                buffer=b"",
                palette_location=pal_location,
                palette_buffer=b"",
            )
        )
        dialog.close()
        quick_validate_files()
        ztaf = ZtaF()
        zta_obj = ztaf.load(zta_location, 0, pal_location)
        if zta_obj:
            buffer = ztaf.get_frame_buffer()
            converter_state.loaded_zta_files[-1].buffer = buffer
            converter_state.converted_signals = [
                signal_to_raw(
                    signal.pixels, signal.width, signal.height, signal.channels
                )
                for signal in buffer
            ]
            converter_state.current_frame_index = 0
        else:
            ui.notify("Error loading ZTA file", color="gray")
        refresh_file_list()

    def pick_files(target_input, filetype, required_types=[]):
        root = tk.Tk()
        root.withdraw()  # hides window
        root.attributes("-topmost", True)  # brings to front
        root.focus_force()  # focuses window
        filetypes = required_types if required_types else [("All files", "*.*")]
        path = filedialog.askopenfilename(
            title=f"Select {filetype} file", filetypes=filetypes
        )
        root.destroy()
        if path:
            target_input.value = path

    ui.timer(0, show_zta_dialog, once=True)
