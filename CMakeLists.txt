cmake_minimum_required(VERSION 3.10)
project(Moonbound VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)

# Căutăm SFML automat folosind find_package
find_package(SFML 2.5 REQUIRED COMPONENTS graphics window system audio network)

# Include directoarele de header SFML
include_directories(${SFML_INCLUDE_DIR})

# Găsim fișierele sursă
file(GLOB_RECURSE MY_SRC src/*.cpp)

# Creăm executabilul
add_executable(Moonbound ${MY_SRC})

# Leagă-l cu bibliotecile necesare
target_link_libraries(Moonbound
   sfml-graphics
   sfml-window
   sfml-system
   sfml-audio
   sfml-network
)