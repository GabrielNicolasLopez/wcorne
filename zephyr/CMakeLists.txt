zephyr_library()

zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/../include)

zephyr_library_sources_ifdef(CONFIG_ZMK_DISPLAY_STATUS_SCREEN_CUSTOM ../src/right_display_screen.c)
zephyr_library_sources_ifdef(CONFIG_ZMK_DISPLAY_STATUS_SCREEN_CUSTOM ../src/corne_right_logo.c)
