include(FetchContent)
message(STATUS "Fetching Freetype")

FetchContent_Declare(freetype
        URL https://github.com/freetype/freetype/archive/refs/tags/VER-2-12-1.zip
        URL_HASH SHA512=3ef3e47752b7c3cd158c738d7e0194f1c9f97ac85c754b02be6ee0f7999c3c19050f713d1e975f5310a4689337463e7b54450ef62e02c3f09864f4c6b13740d9

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

set(FT_DISABLE_BZIP2 TRUE CACHE BOOL "Disable BZip2 dependency" FORCE)
set(FT_DISABLE_HARFBUZZ TRUE CACHE BOOL "Disable Harfbuzz dependency" FORCE)
set(FT_DISABLE_BROTLI TRUE CACHE BOOL "Disable Brotli dependency" FORCE)
FetchContent_MakeAvailable(freetype)
