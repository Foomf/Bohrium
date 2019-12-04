cmake_minimum_required(VERSION 3.12)

# --------------------------------------------------------- #
# Project declaration                                       #
# --------------------------------------------------------- #
set(PROG_NAME Bohrium)
set(LIB_NAME Lib${PROG_NAME})
project (${PROG_NAME})

# --------------------------------------------------------- #
# Sources                                                   #
# --------------------------------------------------------- #
set(BOHRIUM_SRCS 
    src/bohrium.c
    src/guid.c
    src/plugin.c
)

set(BOHRIUM_HDRS
    include/bohrium.h
    include/guid.h
    include/plugin.h
)

# --------------------------------------------------------- #
# Bohrium library                                           #
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

# --------------------------------------------------------- #
# Set compile options                                       #
# --------------------------------------------------------- #
if(MSVC)
  target_compile_options(${LIB_NAME} PRIVATE /W4 /WX)
else()
  target_compile_options(${LIB_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()

# --------------------------------------------------------- #
# C11 standard                                              #
# --------------------------------------------------------- #
set_property(TARGET ${LIB_NAME} PROPERTY C_STANDARD 11)
set_property(TARGET ${LIB_NAME} PROPERTY C_STANDARD_REQUIRED ON)

# --------------------------------------------------------- #
# Libraries                                                 #
# --------------------------------------------------------- #
if(MINGW)
  add_compile_definitions(_SSIZE_T_)
endif()
add_subdirectory(lib/zip)
target_link_libraries(${LIB_NAME} PUBLIC zip)