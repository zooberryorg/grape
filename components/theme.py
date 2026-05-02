from nicegui import ui


def apply():
    ui.colors(primary="#adadad", shared=True)
    ui.add_head_html(
        """
        <style>
            ::-webkit-scrollbar { display: none; }
            * {
                -ms-overflow-style: none;
                scrollbar-width: none;
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
               
    """)
