include(FetchContent)
message(STATUS "Fetching stduuid")

FetchContent_Declare(stduuid
        URL https://github.com/mariusbancila/stduuid/archive/3afe7193facd5d674de709fccc44d5055e144d7a.zip
        URL_HASH SHA512=a0e1c4b889919b43290ab8c978e96c2f51782a1c7972780351c80b4a860f1c4a488a957bf832b3e38eea97a8efa1dcce632c04fbb083331e2b83f54b16e87a67

        PREFIX "${CMAKE_CURRENT_BINARY_DIR}"
        TMP_DIR "${CMAKE_CURRENT_BINARY_DIR}/tmp"
        STAMP_DIR "${CMAKE_CURRENT_BINARY_DIR}/stamp"
        DOWNLOAD_DIR "${CMAKE_CURRENT_BINARY_DIR}/dl"
        SOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/src"
        SUBBUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/build"
        INSTALL_DIR "${CMAKE_CURRENT_BINARY_DIR}/inst"
        LOG_DIR "${CMAKE_CURRENT_BINARY_DIR}/log"
        )
set(UUID_USING_CXX20_SPAN TRUE CACHE BOOL "Avoids using the bundled GSL library from stduuid" FORCE)
set(UUID_ENABLE_INSTALL TRUE CACHE BOOL
        "Install the stduuid library." FORCE)
FetchContent_MakeAvailable(stduuid)
