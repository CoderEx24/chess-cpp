cmake_minimum_required(VERSION 3.10)

project(chess-cpp VERSION 0.1)

find_package(CppUTest REQUIRED)

set(CMAKE_CXX_COMPILER clang++)
set(TEST_SOURCE_DIR "${PROJECT_SOURCE_DIR}/tests")
set(PROJECT_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include")
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

add_executable(debug
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

add_executable(tests 
	${PROJECT_SOURCE_DIR}/core/pawn.cpp
	${PROJECT_SOURCE_DIR}/core/rook.cpp
	${PROJECT_SOURCE_DIR}/core/knight.cpp
	${PROJECT_SOURCE_DIR}/core/bishop.cpp
	${PROJECT_SOURCE_DIR}/core/queen.cpp
	${PROJECT_SOURCE_DIR}/core/king.cpp
	${PROJECT_SOURCE_DIR}/core/grid.cpp
	${TEST_SOURCE_DIR}/test_pawn.cpp
	${TEST_SOURCE_DIR}/test_rook.cpp
	${TEST_SOURCE_DIR}/test_bishop.cpp
	${TEST_SOURCE_DIR}/test_knight.cpp
	${TEST_SOURCE_DIR}/test_queen.cpp
	${TEST_SOURCE_DIR}/test_king.cpp
	${TEST_SOURCE_DIR}/test_grid.cpp
	${TEST_SOURCE_DIR}/test_main.cpp
)

target_link_libraries(tests PUBLIC
	CppUTest
	CppUTestExt
)

target_include_directories(tests PUBLIC
	/usr/include
	/usr/local/include
	${PROJECT_INCLUDE_DIR}
)

target_include_directories(tests PUBLIC
	-g
	-include /usr/local/include/CppUTest/MemoryLeakDetectorNewMacros.h
	)

target_include_directories(chess PUBLIC
	/usr/include
	/usr/local/include
	${PROJECT_INCLUDE_DIR}
)

target_compile_options(chess PUBLIC
	-OO
)

target_include_directories(debug PRIVATE
	/usr/include
	/usr/local/include
	${PROJECT_INCLUDE_DIR}
)

target_compile_options(debug PRIVATE
	-g
)
