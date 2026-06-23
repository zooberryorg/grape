# GrAPE - the great animal project editor for Zoo Tycoon 1

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

- **Python** for the backend logic and file processing
- **NiceGUI** for the frontend interface

## Building and Running

1. Clone the repository:

   ```bash
   git clone https://github.com/zooberryorg/grape.git
   ```

2. Install dependencies:

   ```bash
   pip install -r requirements.txt
   ```

3. Run the application:
   ```bash
    python main.py
   ```

## Developers

Additional steps for developers.

Install Tailwind CLI for theme development:

```bash
npm install tailwindcss @tailwindcss/cli
```

Point the Tailwind CLI to the input.css file in the repo:

```bash
npx tailwindcss -i ./grape/static/input.css -o ./grape/static/grape.css --watch
```

Install Prettier for code formatting:

```bash
npm install --save-dev --save-exact prettier
```

Run Prettier to format code:

```bash
npx prettier . --write
```