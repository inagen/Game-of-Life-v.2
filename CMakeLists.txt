cmake_minimum_required(VERSION 3.5)
project (game_of_life)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(game_of_life main.cpp field.cpp fieldmanager.cpp renderer.cpp)

find_package(SFML COMPONENTS audio graphics window system REQUIRED)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(game_of_life ${SFML_LIBRARIES})

target_link_libraries(game_of_life sfml-graphics)