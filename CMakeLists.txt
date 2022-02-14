cmake_minimum_required(VERSION 3.22.2)
project(QTreeR
        VERSION 0.0.1
        DESCRIPTION "QTree thing"
        LANGUAGES CXX)


add_executable(QTreeR src/main.cpp
    src/App.cpp
    src/GameEngine.cpp
    src/Drawables/Square.cpp
    src/Broadcast/Broadcast.cpp
    src/EntitySystem/Entity.cpp
)

target_link_libraries(QTreeR X11)

target_compile_features(QTreeR PRIVATE cxx_std_23)
target_include_directories(QTreeR PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
