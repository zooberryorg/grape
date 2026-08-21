# APE Studio - animal project editor for Zoo Tycoon 1

A modern take on the classic [APE tool](https://zootycoon.fandom.com/wiki/APE) made by Blue Fang in 2001.

## Roadmap

- [ ] Simple UI for basic ZTA file editing
- [ ] Project management features
- [ ] Generate Zoo Tycoon INI files completely within the app
- [ ] Searchable database of all lang strings, official and unofficial
- [ ] Searchable database of all game assets, their IDs, and location
- [ ] Bulk export of ZTA files
- [ ] Image processing features for quick edits to graphics such as:
  - [ ] Sharpening
  - [ ] Color correction
  - [ ] Resizing

## Tech Stack

- **C++17** for the backend logic and file processing
- **Qt Widgets (Qt 6.8.1)** for the frontend interface

## Building and Running

*This section is incomplete.*

1. Clone the repository:

   ```bash
   git clone https://github.com/zooberryorg/ape-studio.git
   ```

## License

The source code for this project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details. Because this project is built using Qt, please note that the distributed binaries of this project are subject to the LGPLv3 license. A copy of the LGPLv3 will be included in the distributed binaries of this project.

Additionally, this project uses a modified version of the TreeNode class from the KDABLabs repository found here: https://github.com/KDABLabs/kdabtv. The original license for this class is the BSD License, which is preserved in the relevant source files.