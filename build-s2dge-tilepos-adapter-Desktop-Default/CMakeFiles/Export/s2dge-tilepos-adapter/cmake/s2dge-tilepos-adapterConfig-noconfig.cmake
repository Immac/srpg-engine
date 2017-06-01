#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "s2dge-tilepos-adapter-lib" for configuration ""
set_property(TARGET s2dge-tilepos-adapter-lib APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(s2dge-tilepos-adapter-lib PROPERTIES
  IMPORTED_IMPLIB_NOCONFIG "${_IMPORT_PREFIX}/s2dge-tilepos-adapter/lib/static/libs2dge-tilepos-adapter-lib.dll.a"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/s2dge-tilepos-adapter/bin/libs2dge-tilepos-adapter-lib.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS s2dge-tilepos-adapter-lib )
list(APPEND _IMPORT_CHECK_FILES_FOR_s2dge-tilepos-adapter-lib "${_IMPORT_PREFIX}/s2dge-tilepos-adapter/lib/static/libs2dge-tilepos-adapter-lib.dll.a" "${_IMPORT_PREFIX}/s2dge-tilepos-adapter/bin/libs2dge-tilepos-adapter-lib.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
