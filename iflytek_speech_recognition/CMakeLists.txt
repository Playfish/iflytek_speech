cmake_minimum_required(VERSION 3.0.2)
project(iflytek_speech_recognition)

#add_compile_options(-std=c++11)
set( CMAKE_CXX_FLAGS "-std=c++11 -O0 -Wall -g -ggdb" )

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  roslib
)

# find_package(Boost REQUIRED COMPONENTS system)

link_directories(lib)
catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES geekplusbot_speed_recognition
  CATKIN_DEPENDS roscpp std_msgs roslib
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME}_node 
  src/tinyxml2.cpp
  src/linuxrec.cpp
  src/speech_recognizer.cpp
  src/asr_offline_record_sample.cpp)
# set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME node PREFIX "")
add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(${PROJECT_NAME}_node
  ${catkin_LIBRARIES}
  msc
  rt
  dl
  pthread
  asound
)

add_executable(test_xml 
  src/tinyxml2.cpp
  test/test_xml.cpp)
add_dependencies(test_xml ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(test_xml
  ${catkin_LIBRARIES}
)

install(TARGETS test_xml ${PROJECT_NAME}_node 
    RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(FILES lib/libmsc.so
        DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
)

install(DIRECTORY launch config
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h**"
  PATTERN ".svn" EXCLUDE
)

