cmake_minimum_required(VERSION 3.20)
project(Fill_Maze)

set(CMAKE_CXX_STANDARD 14)

# add include
set(GLEW_H /usr/local/Cellar/glew/2.2.0_1/include/GL)
set(GLFW_H /usr/local/Cellar/glfw/3.3.4/include/GLFW)
set(GLM_H /usr/local/Cellar/glm/0.9.9.8/include/glm)
include_directories(${GLEW_H} ${GLFW_H} ${GLM_H})
include_directories(${PROJECT_SOURCE_DIR}/include)

# add libraries
set(GLEW_LINK /usr/local/Cellar/glew/2.2.0_1/lib/libGLEW.2.2.0.dylib)
set(GLFW_LINK /usr/local/Cellar/glfw/3.3.4/lib/libglfw.3.3.dylib)
link_libraries(${OPENGL} ${GLEW_LINK} ${GLFW_LINK})

# add execution config
add_executable(Launch
        src/main.cpp
        src/control.cpp
        src/object.cpp
        src/gameover.cpp
        src/gameresult.cpp
        src/gamestart.cpp
        src/init.cpp
        src/laberynth.cpp
        )

# for macOS
if (APPLE)
    target_link_libraries(Launch "-framework OpenGL")
    target_link_libraries(Launch "-framework GLUT")
endif()