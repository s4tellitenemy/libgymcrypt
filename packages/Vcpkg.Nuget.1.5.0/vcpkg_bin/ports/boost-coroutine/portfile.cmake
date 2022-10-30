# Automatically generated by boost-vcpkg-helpers/generate-ports.ps1

include(vcpkg_common_functions)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO boostorg/coroutine
    REF boost-1.68.0
    SHA512 47edf91ffdcd4ec8acb98b54f7baa19f280b4d865a6810ee26bbb13cc8f9233e8bbeb8771fa796e2b2fef393352981b737c7987da31095ef65f48f62a8a2d092
    HEAD_REF master
)

include(${CURRENT_INSTALLED_DIR}/share/boost-build/boost-modular-build.cmake)
boost_modular_build(SOURCE_PATH ${SOURCE_PATH})
include(${CURRENT_INSTALLED_DIR}/share/boost-vcpkg-helpers/boost-modular-headers.cmake)
boost_modular_headers(SOURCE_PATH ${SOURCE_PATH})