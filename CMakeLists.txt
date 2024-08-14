cmake_minimum_required(VERSION 3.16)

project(ray-framework VERSION 0.1.0)


set(HEADER_FILES 
    game/game.h
    cimgui/cimgui_impl.h
    cimgui/cimgui.h
    raylib/raygui.h
    raylib/raylib.h
    raylib/raymath.h
    raylib/rlgl.h
)

set(SRC_FILES
    src/framework/main.c
)

add_library(ray-framework
    ${SRC_FILES}
)


target_include_directories(ray-framework
    PUBLIC
        include
)

find_package(OpenGL REQUIRED)
target_link_libraries(ray-framework
    PUBLIC
        ${CMAKE_SOURCE_DIR}/lib/cimgui/cimgui.lib
        ${CMAKE_SOURCE_DIR}/lib/raylib/raylib.lib
        ${OPENGL_gl_LIBRARY}
        winmm.lib
)

# Create game executable

add_executable(ray-game
    src/game/game.c
)

target_link_libraries(ray-game ray-framework)

# install(TARGETS ray-framework DESTINATION lib)
# install(TARGETS ray-game DESTINATION bin)