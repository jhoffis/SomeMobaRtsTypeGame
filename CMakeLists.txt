cmake_minimum_required(VERSION 3.16)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp scripts/Map.cpp scripts/Map.h scripts/engine/Window.cpp scripts/engine/Window.h scripts/engine/VulkanSetup.cpp)

find_package(Vulkan REQUIRED)
target_include_directories(${PROJECT_NAME} PUBLIC ${Vulkan_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} Vulkan::Vulkan)

add_subdirectory (${CMAKE_CURRENT_SOURCE_DIR}/Libraries/glm)
target_link_libraries(${PROJECT_NAME} glm::glm)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Libraries/glm)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Libraries/glfw-3.3.2.bin.WIN64/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Libraries/stb)

#target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/glfw-3.3.2.bin.WIN64/lib-mingw-w64/libglfw3dll.a)
target_link_libraries(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/Libraries/glfw-3.3.2.bin.WIN64/lib-mingw-w64/libglfw3.a)
