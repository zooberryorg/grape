from nicegui import ui


def apply():
    ui.colors(
        primary="#adadad", 
        shared=True,
        accent_secondary="#d6b15d"
    )
    ui.add_head_html(
        """
        <link rel="stylesheet" href="/app/static/grape.css">
        <style>
            ::-webkit-scrollbar { display: none; }
            * {
                -ms-overflow-style: none;
                scrollbar-width: none;
            }
        </style>
        <style type="text/tailwindcss">
            @layer overrides {
                .grape-button.q-btn--flat::before {
                    background: transparent !important;
                    opacity: 0 !important;
                }                
                .grape-button {
                    @apply hover:!bg-red-700 hover:!border-gold-400;
                }

                .grape-button:hover {
                    @apply !bg-pine-800/70 !border-gold-400;
                }
            }
        </style>        
        """,
        shared=True,
    )

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
