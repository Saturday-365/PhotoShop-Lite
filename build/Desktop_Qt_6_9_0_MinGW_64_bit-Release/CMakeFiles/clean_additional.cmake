# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\PhotoShop-Lite_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\PhotoShop-Lite_autogen.dir\\ParseCache.txt"
  "PhotoShop-Lite_autogen"
  )
endif()
