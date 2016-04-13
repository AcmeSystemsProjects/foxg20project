cmake_minimum_required (VERSION 2.6)

project (fowg20project)

# macro needed in order to extend cmake macros search path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake/")


# projects
set( CMAKE_C_FLAGS  "-std=c99" )

add_executable(testhw testhw.c)
add_executable(testusb testusb.c)

# libraries
find_package (BZip2)
if (BZIP2_FOUND)
  include_directories(${BZIP_INCLUDE_DIRS})
  target_link_libraries (testhw ${BZIP2_LIBRARIES})
endif (BZIP2_FOUND)

find_package(libusb-1.0 REQUIRED)
if (LIBUSB_1_FOUND)
  include_directories(${LIBUSB_1_INCLUDE_DIRS})
  target_link_libraries (testusb ${LIBUSB_1_LIBRARIES})
  message ("libusb-1.0 FOUND")
else(LIBUSB_1_FOUND)
  message ("libusb-1.0 NOT FOUND")
endif (LIBUSB_1_FOUND)



# install target
install(TARGETS testhw	DESTINATION bin)
install(TARGETS testusb	DESTINATION bin)

# uninstall target
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)




