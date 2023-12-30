# Setup
cmake_minimum_required (VERSION 3.8)

project (FakeYoutube)

#compile my files
file(GLOB source_files CONFIGURE_DEPENDS
    "*.h"
    "*.cpp"
    "src/*.cpp"
    "src/*.h"
    #"util/*.cpp"
    #"util/*.h"
)

add_executable (${PROJECT_NAME} ${source_files} )

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()