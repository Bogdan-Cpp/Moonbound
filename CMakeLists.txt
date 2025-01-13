cmake_minimum_required(VERSION 3.10)
project(Moonbound VERSION 1.0)

set(CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR}/include)

include_directories("C:/Users/leita/Documents/SFML/SFML-3.0.0/include")
link_directories("C:/Users/leita/Documents/SFML/SFML-3.0.0/lib")

set(SFML_DIR "C:/Users/leita/Documents/SFML/SFML-3.0.0/lib/cmake/SFML")

file(GLOB_RECURSE MY_SRC src/*.cpp)
add_executable(Moonbound ${MY_SRC})

target_link_libraries(Moonbound
   sfml-graphics
   sfml-window
   sfml-system
   sfml-audio
   sfml-network
   opengl32
   winmm
   gdi32
   user32
)