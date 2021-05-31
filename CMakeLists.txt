cmake_minimum_required(VERSION 3.20)

project("GreedySnake")

set(CMAKE_CXX_STANDARD 11)

add_executable(${CMAKE_PROJECT_NAME} src/food.cc src/main.cc src/run.cc src/scene.cc src/score.cc src/snake.cc src/welcome.cc)

target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE /include)

target_link_libraries(${CMAKE_PROJECT_NAME} winmm.lib)