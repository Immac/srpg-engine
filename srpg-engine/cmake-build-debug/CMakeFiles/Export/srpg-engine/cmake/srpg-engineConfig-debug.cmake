#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "srpg-engine-lib" for configuration "Debug"
set_property(TARGET srpg-engine-lib APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(srpg-engine-lib PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/srpg-engine/lib/static/libsrpg-engine-lib.dll.a"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/srpg-engine/bin/libsrpg-engine-lib.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS srpg-engine-lib )
list(APPEND _IMPORT_CHECK_FILES_FOR_srpg-engine-lib "${_IMPORT_PREFIX}/srpg-engine/lib/static/libsrpg-engine-lib.dll.a" "${_IMPORT_PREFIX}/srpg-engine/bin/libsrpg-engine-lib.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
