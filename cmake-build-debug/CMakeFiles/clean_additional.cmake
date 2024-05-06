# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "src\\app\\Blueteeth_autogen"
  "src\\app\\CMakeFiles\\Blueteeth_autogen.dir\\AutogenUsed.txt"
  "src\\app\\CMakeFiles\\Blueteeth_autogen.dir\\ParseCache.txt"
  )
endif()
