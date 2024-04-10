### toolchain.cmake ###
# this is required
include(CMakeForceCompiler)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)


set(sysroot Y:/work/t113_linux/out/t113_i/cqlht113_linux_nand/longan/buildroot/host/usr/arm-buildroot-linux-gnueabi/sysroot)
set(CMAKE_FIND_ROOT_PATH ${sysroot})
set(CMAKE_SYSROOT ${sysroot})
INCLUDE_DIRECTORIES(${sysroot}/usr/include/)

set(toolchain D:/Linux/gcc-linaro-5.3.1-2016.05-i686-mingw32_arm-linux-gnueabi)
set(CMAKE_C_COMPILER_PREFIX arm-linux-gnueabi)
set(CMAKE_CXX_COMPILER_PREFIX arm-linux-gnueabi)
set(CMAKE_LINKER_PREFIX arm-linux-gnueabi)
set(CMAKE_C_COMPILER ${toolchain}/bin/arm-linux-gnueabi-gcc.exe)
set(CMAKE_CXX_COMPILER ${toolchain}/bin/arm-linux-gnueabi-g++.exe)
set(CMAKE_LINKER ${toolchain}/bin/arm-linux-gnueabi-ld.exe)


SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)