cmake_minimum_required(VERSION 3.28)
project(HangmanSFML CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SFML_BUILD_NETWORK OFF)
set(SPDLOG_USE_STD_FORMAT ON)
set(TGUI_BACKEND SFML_GRAPHICS)

include(FetchContent)
FetchContent_Declare(SFML URL https://github.com/SFML/SFML/archive/refs/tags/3.1.0.tar.gz)
FetchContent_Declare(JSON URL https://github.com/nlohmann/json/releases/download/v3.12.0/json.tar.xz)
FetchContent_Declare(TGUI URL https://github.com/texus/TGUI/archive/refs/tags/v1.12.1.tar.gz)
FetchContent_MakeAvailable(SFML JSON TGUI)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS Source/*.cpp)
add_executable(HangmanSFML ${SOURCES})

add_custom_command(TARGET HangmanSFML POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/Content
    $<TARGET_FILE_DIR:HangmanSFML>/Content
)

target_include_directories(HangmanSFML PRIVATE Include)
target_compile_features(HangmanSFML PRIVATE cxx_std_20)
target_compile_options(HangmanSFML PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/W4>
    $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra>
    $<$<CXX_COMPILER_ID:Clang>:-Wall -Wextra>)
target_link_libraries(HangmanSFML PRIVATE 
	SFML::Graphics 
	SFML::Audio 
	nlohmann_json::nlohmann_json 
        TGUI::TGUI)