cmake_minimum_required(VERSION 3.14)
project(storyboard_player)

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_INCLUDE ./include)

include_directories(${PROJECT_INCLUDE})

add_library(glad SHARED ./src/glad/glad.c)
add_library(stb_image SHARED ./src/stb_image/stb_image.cpp)

add_executable(storyboard_player src/main.cpp src/shader/Shader.cpp src/shader/Shader.h src/shader/SpriteShader.cpp src/shader/SpriteShader.h src/osb/Sprite.cpp src/osb/Sprite.h)

target_link_libraries(storyboard_player glad)
target_link_libraries(storyboard_player stb_image)
target_link_libraries(storyboard_player GLEW)
target_link_libraries(storyboard_player glfw3)
target_link_libraries(storyboard_player GL)
target_link_libraries(storyboard_player X11)
target_link_libraries(storyboard_player pthread)
target_link_libraries(storyboard_player Xrandr)
target_link_libraries(storyboard_player Xi)
target_link_libraries(storyboard_player Xxf86vm)
target_link_libraries(storyboard_player Xinerama)
target_link_libraries(storyboard_player Xcursor)
target_link_libraries(storyboard_player rt)
target_link_libraries(storyboard_player m)
target_link_libraries(storyboard_player dl)