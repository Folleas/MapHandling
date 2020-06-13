cmake_minimum_required(VERSION 3.11)

project(bomberman)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake_find")

set(CMAKE_MODULE_PATH "/Users/Home/SFML-2.2-osx-clang-universal/cmake/Modules" ${CMAKE_MODULE_PATH})

set(SOURCE_FILES
        src/main.cpp
		)

set(EXECUTABLE_OUTPUT_PATH "${PROJECT_BINARY_DIR}")

find_package(Irrlicht)

find_package(SFML 2 COMPONENTS audio window REQUIRED)

include_directories(${SFML_INCLUDE_DIR})

include_directories(${Irrlicht_INCLUDE_DIRS})

include_directories(
        include/IndieStudio
)

add_executable(
	${PROJECT_NAME}
	${SOURCE_FILES}
	)

target_link_libraries(
	${PROJECT_NAME}
	sfml-audio sfml-window sfml-graphics sfml-system
	${CMAKE_THREAD_LIBS_INIT}
	${Irrlicht_LIBRARIES}
	)