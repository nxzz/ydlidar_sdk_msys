
add_definitions(-std=c++11) # Use C++11
include_directories(include)
include_directories(src)

IF (WIN32)
add_definitions(-std=c++11 -DUNICODE -D_USE_MATH_DEFINES)
FILE(GLOB SDK_SRC 
  "src/*.cpp"
  "src/*.h"
  "src/impl/windows/*.cpp"
  "src/impl/windows/*.h"
)
	
ELSE()
FILE(GLOB SDK_SRC 
  "src/*.cpp"
  "src/*.h"
  "src/impl/unix/*.cpp"
  "src/impl/unix/*.h"
)

	
ENDIF()

add_subdirectory(samples)

add_library(ydlidar_driver SHARED ${SDK_SRC})
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
IF (WIN32)
target_link_libraries(ydlidar_driver)
ELSE()
target_link_libraries(ydlidar_driver rt pthread)
ENDIF()                    
