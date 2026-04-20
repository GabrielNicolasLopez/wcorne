zephyr_library()

zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/../include)

zephyr_library_sources_ifdef(CONFIG_ZMK_DISPLAY ../src/right_display_logo_overlay.c)
zephyr_library_sources_ifdef(CONFIG_ZMK_DISPLAY ../src/corne_right_logo.c)
