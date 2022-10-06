cmake_minimum_required(VERSION 3.16.0)
project(NearestPlane CXX)

include(CMake/Utils.cmake)

include(CMake/GlobalSettingsInclude.cmake OPTIONAL)

set(Header_Files
    "Haversine.h"
    "Structs.h"
    "Plane.h"
	"JSONHandling.h"
)

set(Source_Files
    "Haversine.cpp"
    "NearestPlane.cpp"
    "Plane.cpp"
	"JSONHandling.cpp"
)
source_group("Source Files" FILES ${Source_Files})
set(ALL_FILES
    ${Header_Files}
    ${Source_Files}
)

add_executable(${PROJECT_NAME} ${ALL_FILES})