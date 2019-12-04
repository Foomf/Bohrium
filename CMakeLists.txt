cmake_minimum_required(VERSION 3.12)

# --------------------------------------------------------- #
# Project declaration                                       #
# --------------------------------------------------------- #
set(PROG_NAME Bohrium)
set(LIB_NAME Lib${PROG_NAME})
project (${PROG_NAME})

# --------------------------------------------------------- #
# C++ 17 standard                                           #
# --------------------------------------------------------- #
# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --------------------------------------------------------- #
# Sources                                           #
# --------------------------------------------------------- #
set(BOHRIUM_SRCS src/bohrium.c)
set(BOHRIUM_HDRS include/bohrium.h)

# --------------------------------------------------------- #
# Bohrium library                                             #
# --------------------------------------------------------- #
add_library(${LIB_NAME} ${BOHRIUM_SRCS} ${BOHRIUM_HDRS})

# --------------------------------------------------------- #
# Include directories                                       #
# --------------------------------------------------------- #
target_include_directories(${LIB_NAME} PUBLIC include
)

# --------------------------------------------------------- #
# Executable linking                                        #
# --------------------------------------------------------- #
set(BOHRIUM_SERVER_EXECUTABLE ON CACHE BOOL "Build Executable")
if(${BOHRIUM_SERVER_EXECUTABLE})
    add_executable(${PROG_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c)
    target_link_libraries(${PROG_NAME} ${LIB_NAME})
endif(${BOHRIUM_SERVER_EXECUTABLE})
