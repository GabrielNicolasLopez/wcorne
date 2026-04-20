zephyr_library()

# Only build custom screen sources when ZMK custom status screen is enabled.
zephyr_library_sources_ifdef(CONFIG_ZMK_DISPLAY_STATUS_SCREEN_CUSTOM src/right_display_screen.c)
zephyr_library_sources_ifdef(CONFIG_ZMK_DISPLAY_STATUS_SCREEN_CUSTOM src/corne_right_logo.c)

