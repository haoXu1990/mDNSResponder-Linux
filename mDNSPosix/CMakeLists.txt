cmake_minimum_required(VERSION 3.26.4)
project(zx-mdnsd)

# 设置编译选项
set(COMMONFLAGS
        "-O2"
        "-g"
        "-fno-strict-aliasing"
        "-fwrapv"
        "-D_GNU_SOURCE"
        "-DHAVE_IPV6"
        "-DNOT_HAVE_SA_LEN"
        "-DPOSIX_BUILD"
        "-DPLATFORM_NO_RLIMIT"
        "-DMDNS_DEBUGMSGS=0"
        "-DMDNS_UDS_SERVERPATH=\"/dev/socket/zx-mdnsd\""
        "-DPID_FILE=\"/dev/socket/zx-mdnsd\""
        "-DMDNS_USERNAME=\"mdnsr\""
        "-DMDNS_VERSIONSTR_NODTS=1"
        "-DTARGET_OS_LINUX"
        "-DHAVE_LINUX"
        "-DUSES_NETLINK"
        "-W"
        "-Wall"
        "-Wextra"
        "-Wno-address-of-packed-member"
        "-Wno-array-bounds"
        "-Wno-pointer-sign"
        "-Wno-unused"
        "-Wno-unused-parameter"
        "-Werror=implicit-function-declaration"
        "-Wno-expansion-to-defined"
)

# 添加源文件和头文件目录
include_directories(zx-mdnsd
        ${CMAKE_CURRENT_SOURCE_DIR}/../mDNSPosix
        ${CMAKE_CURRENT_SOURCE_DIR}/../mDNSCore
        ${CMAKE_CURRENT_SOURCE_DIR}/../mDNSShared
        ${CMAKE_CURRENT_SOURCE_DIR}/../mDNSShared/utilities
        ${CMAKE_CURRENT_SOURCE_DIR}/../DSO
        ${CMAKE_CURRENT_SOURCE_DIR}/../ServiceRegistration
)

# 添加编译选项
add_definitions(${COMMONFLAGS})

# 添加可执行文件
add_executable(zx-mdnsd
        ${CMAKE_CURRENT_SOURCE_DIR}/PosixDaemon.c
        ${CMAKE_CURRENT_SOURCE_DIR}/mDNSPosix.c
        ${CMAKE_CURRENT_SOURCE_DIR}/mDNSUNP.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../mDNSCore/DNSCommon.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../mDNSCore/mDNS.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../mDNSCore/DNSDigest.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../mDNSCore/uDNS.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../mDNSShared/uds_daemon.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../mDNSShared/mDNSDebug.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../mDNSShared/dnssd_ipc.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../mDNSShared/GenLinkedList.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../mDNSShared/ClientRequests.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../mDNSShared/dnssd_clientshim.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../mDNSShared/utilities/mdns_addr_tailq.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../mDNSShared/utilities/misc_utilities.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../mDNSShared/PlatformCommon.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../DSO/dso.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../DSO/dso-transport.c
)

# 添加共享库
add_library(mdnssd SHARED
        ${CMAKE_CURRENT_SOURCE_DIR}/../mDNSShared/dnssd_clientlib.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../mDNSShared/dnssd_clientstub.c
        ${CMAKE_CURRENT_SOURCE_DIR}/../mDNSShared/dnssd_ipc.c
)

# 添加链接的共享库
target_link_libraries(mdnssd
)

set_target_properties(mdnssd PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${TARGET_OUT})
set_target_properties(zx-mdnsd PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${TARGET_OUT})