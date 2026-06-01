cmake_minimum_required(VERSION 3.16)

project(HistoryMerge VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Quick Qml)

qt_standard_project_setup(REQUIRES 6.10)

qt_add_executable(HistoryMerge
    MANUAL_FINALIZATION
    main.cpp
    GameBoardModel.h
    GameBoardModel.cpp
)

qt_add_qml_module(HistoryMerge
    URI HistoryMerge
    VERSION 1.0
    QML_FILES
        Main.qml
)

if(ANDROID)
    set_target_properties(HistoryMerge PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY
            "${CMAKE_BINARY_DIR}/android-build-HistoryMerge/libs/${ANDROID_ABI}"
    )
endif()

set_target_properties(HistoryMerge PROPERTIES
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(HistoryMerge
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Quick
        Qt6::Qml
)

install(TARGETS HistoryMerge
    RUNTIME DESTINATION .
    LIBRARY DESTINATION .
    BUNDLE DESTINATION .
)

qt_finalize_executable(HistoryMerge)