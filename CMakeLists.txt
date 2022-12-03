cmake_minimum_required(VERSION 3.23)
project(FlappyBird)

set(CMAKE_CXX_STANDARD 14)

set(SFML_DIR "C:/Libraries/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio window REQUIRED)



add_executable(FlappyBird
        "src/FlappyBird.cpp"
        "src/Bird.cpp"
        "src/Toolbox.cpp"
        "src/Pipe.cpp"
        )

target_link_libraries(FlappyBird sfml-graphics sfml-audio sfml-window)

