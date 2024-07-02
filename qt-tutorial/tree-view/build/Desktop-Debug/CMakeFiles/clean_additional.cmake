# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/tree-view_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/tree-view_autogen.dir/ParseCache.txt"
  "tree-view_autogen"
  )
endif()
