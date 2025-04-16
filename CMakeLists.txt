cmake_minimum_required(VERSION 3.10)
project(Moonbound VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system audio network)

include_directories(${SFML_INCLUDE_DIR})

file(GLOB_RECURSE MY_SRC src/*.cpp)

add_executable(Moonbound ${MY_SRC})

target_link_libraries(Moonbound
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
    sfml-network
)

if(EXISTS "${CMAKE_SOURCE_DIR}/assets")
    
    add_custom_command(TARGET Moonbound POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_SOURCE_DIR}/assets" $<TARGET_FILE_DIR:Moonbound>/assets
        COMMENT "Copying assets directory"
    )

    install(DIRECTORY "${CMAKE_SOURCE_DIR}/assets/"
            DESTINATION "share/${PROJECT_NAME}"
            PATTERN ".gitignore" EXCLUDE
    )
else()
    message(WARNING "Assets directory not found at ${CMAKE_SOURCE_DIR}/assets")
endif()

if(WIN32)
    set_target_properties(Moonbound PROPERTIES
        WIN32_EXECUTABLE_ICON "${CMAKE_SOURCE_DIR}/assets/icon.ico"
    )
endif()

install(TARGETS Moonbound DESTINATION "bin")