project(libgui_test)

add_executable(libgui_test
    main.cpp
)

target_link_libraries(libgui_test X11)
