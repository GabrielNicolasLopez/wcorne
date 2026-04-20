zephyr_library()

zephyr_include_directories(${CMAKE_CURRENT_LIST_DIR}/../include)

if(CONFIG_SHIELD_CORNE_RIGHT AND CONFIG_ZMK_DISPLAY)
  zephyr_library_sources(../src/right_display_logo_overlay.c)
  zephyr_library_sources(../src/corne_right_logo.c)
endif()
