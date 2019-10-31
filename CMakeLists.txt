project(libgui_test)

add_executable(libgui_test
    String/String.cpp
    String/StringBuilder.cpp
    String/StringView.cpp
    main.cpp
)

target_link_libraries(libgui_test X11)

include_directories(libgui_test "./String")
