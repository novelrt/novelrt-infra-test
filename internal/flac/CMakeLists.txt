include(FetchContent)
message(STATUS "Fetching FLAC...")

FetchContent_Declare(flac
        URL https://github.com/xiph/flac/releases/download/1.3.4/flac-1.3.4.tar.xz
        URL_HASH SHA256=8ff0607e75a322dd7cd6ec48f4f225471404ae2730d0ea945127b1355155e737

        PREFIX "${CMAKE_CURRENT_BINARY_DIR}"
        TMP_DIR "${CMAKE_CURRENT_BINARY_DIR}/tmp"
        STAMP_DIR "${CMAKE_CURRENT_BINARY_DIR}/stamp"
        DOWNLOAD_DIR "${CMAKE_CURRENT_BINARY_DIR}/dl"
        SOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/src"
        SUBBUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/build"
        BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/bin"
        INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/inst"
        LOG_DIR "${CMAKE_CURRENT_BINARY_DIR}/log"
)

set(BUILD_CXXLIBS OFF CACHE BOOL "" FORCE)
set(BUILD_PROGRAMS OFF CACHE BOOL "Build and install programs" FORCE)
set(BUILD_EXAMPLES OFF CACHE BOOL "Build and install examples" FORCE)
set(BUILD_TESTING OFF CACHE BOOL "Build tests" FORCE)
set(BUILD_DOCS OFF CACHE BOOL "Build documentation" FORCE)
set(INSTALL_MANPAGES OFF CACHE BOOL "" FORCE)
set(INSTALL_PKGCONFIG_MODULES OFF CACHE BOOL "" FORCE)
set(INSTALL_CMAKE_CONFIG_MODULE ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(flac)


# These warnings are outside our scope as we do not manage the libraries themselves.
# We'll silence the warnings so that output is a little cleaner.
if(NOT WIN32)
  target_compile_options(FLAC
    PRIVATE
      $<$<CXX_COMPILER_ID:GNU>:-Wno-cast-align>
      $<$<CXX_COMPILER_ID:Clang>:-Wno-cast-align>
      $<$<CXX_COMPILER_ID:AppleClang>:-Wno-cast-align>
  )
endif()
if(APPLE)
  set_target_properties(FLAC PROPERTIES NO_SONAME TRUE)
  get_target_property(FLAC_OUTPUT_NAME FLAC OUTPUT_NAME)
  target_link_options(FLAC PRIVATE -install_name @rpath/libFLAC.dylib)
endif()
set(FLAC_LIBRARY "FLAC" CACHE STRING "Set FLAC libraries" FORCE)
set(FLAC_INCLUDE_DIR "${CMAKE_CURRENT_BINARY_DIR}/src/include" CACHE STRING "Set FLAC include dirs" FORCE)
