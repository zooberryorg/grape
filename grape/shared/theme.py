from nicegui import ui
from grape.shared.utils import add_style, add_script
from grape.shared.settings import STATIC_DIR

def apply():
    ui.query("html, body").classes("h-screen m-0 p-0 flex flex-col overflow-hidden")
    ui.query("html, body, .app").classes("bg-pine-800")
    ui.query(".q-layout").classes("h-screen")
    ui.query(".q-page-container").classes("flex flex-col flex-1 overflow-hidden h-full")
    ui.query(".q-page").classes("flex flex-col flex-1 h-100 overflow-hidden")
    ui.query(".nicegui-content").classes("flex flex-col flex-1 p-0 min-h-0")
    ui.colors(primary="#adadad", shared=True, accent_secondary="#d6b15d")
    add_style(f"{STATIC_DIR}\\grape.css")
    add_style(f"{STATIC_DIR}\\scrollbar.css")
    add_style(f"{STATIC_DIR}\\overrides.css", "text/tailwindcss")
    ui.add_css("""

        .export-select .q-field__native,
        .export-select .q-field__label,
        .q-select__dropdown-icon {
            color: #9CA3AF !important;
        }

        .export-select-popup {
            background-color: #374151 !important;
        }
        .export-select-popup .q-item {
            color: #F3F4F6 !important;
        }
        .export-select-popup .q-item:hover {
            background-color: #4B5563 !important;
        }
               
        .q-checkbox {
            margin: 0 !important;
        }
               
        .q-checkbox__bg {
            border: 0 !important;
            background-color: #4B5563 !important;
        }
               
        .q-field {
            padding: 0.5rem !important;
            border-radius: 0.50rem !important;
            border: 0 !important;
        }
        
        .q-field__control::before {
            border: 0 !important;
        }
               
        .q-field__control::after {
            border: 0 !important;
        }
               
        .q-field:hover {
            background-color: #4B5563 !important;
            transition: background-color 0.4s ease-in-out;
        }
               
        .number-input input {
            color: #9ca3af !important;
        }
        .number-input input[type=number]::-webkit-inner-spin-button,
        .number-input input[type=number]::-webkit-outer-spin-button {
            opacity: 1;
            filter: invert(1);
            cursor: pointer;
        }
        .number-input .q-field__control::before {
            border-color: #4b5563 !important;
        }
        .number-input .q-field__control::after {
            border-color: #9ca3af !important;
        }               
               
        .input-field .q-field__control {
            min-height: 20px !important;
            height: 20px !important;
            padding: 0 4px !important;
        }
        .input-field .q-field__native {
            padding: 0 !important;
            min-height: 20px !important;
            line-height: 20px !important;
        }
        .input-field .q-field__append {
            height: 20px !important;
            padding: 0 !important;
        }    
               
        .q-focus-helper {
            transition: all 0.4s ease-in-out !important;
        }
               
        .focus-button .q-focus-helper {
            background-color: var(--color-gold-400) !important;
        }
               """)
