# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/model-view_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/model-view_autogen.dir/ParseCache.txt"
  "model-view_autogen"
  )
endif()
