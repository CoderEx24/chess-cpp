cmake_minimum_required(VERSION 3.10)

project(chess-cpp VERSION 0.1)

find_package(SFML REQUIRED system window graphics network audio)

set(CMAKE_CXX_COMPILER clang++)
set(PROJECT_SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")

add_executable(chess 
	${PROJECT_SOURCE_DIR}/core/pawn.cpp
	${PROJECT_SOURCE_DIR}/core/rook.cpp
	${PROJECT_SOURCE_DIR}/core/knight.cpp
	${PROJECT_SOURCE_DIR}/core/bishop.cpp
	${PROJECT_SOURCE_DIR}/core/queen.cpp
	${PROJECT_SOURCE_DIR}/core/king.cpp
	${PROJECT_SOURCE_DIR}/core/grid.cpp
	${PROJECT_SOURCE_DIR}/ui/grid_renderer.cpp
	${PROJECT_SOURCE_DIR}/ui/main_window.cpp
)

target_link_libraries(chess PUBLIC
	${SFML_LIBRARIES}
)

target_include_directories(chess PUBLIC
	/usr/include
	/usr/local/include
	${PROJECT_SOURCE_DIR}/include
)


