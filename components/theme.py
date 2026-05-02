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
        .export-select .q-field__control:before {
            border-color: #4B5563 !important;
            transition: none !important;
        }

        .export-select:hover .q-field__control:before {
            border-color: #6B7280 !important;
        }

        .export-select.q-field--focused .q-field__control:before {
            border-color: #4F46E5 !important;
        }

        .export-select .q-field__control {
            background-color: #374151 !important;
        }
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
               
        .q-checkbox__bg {
            border: 1px solid #4B5563 !important;
        }
               
    """)
