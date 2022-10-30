# Automatically generated by boost-vcpkg-helpers/generate-ports.ps1

include(vcpkg_common_functions)

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO boostorg/asio
    REF boost-1.68.0
    SHA512 287aa7b4e37e97df10d196b1b409d38c19a025c18228df1ba9bb7dc19d53c9f51b69699e71b04ddee030710e08cb9c4b34eb08f8284d3fa88a762ed6fd096dbe
    HEAD_REF master
)

include(${CURRENT_INSTALLED_DIR}/share/boost-vcpkg-helpers/boost-modular-headers.cmake)
boost_modular_headers(SOURCE_PATH ${SOURCE_PATH})
