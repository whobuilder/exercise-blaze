cmake_minimum_required (VERSION 3.0.2)

if(FORTRAN_LINK_DIRECTORIES)
    message(STATUS ${FORTRAN_LINK_DIRECTORIES})
    link_directories(${FORTRAN_LINK_DIRECTORIES})
endif()
project(exercise-blaze)
find_package(FMT REQUIRED)
find_package(blaze REQUIRED)
add_executable(firstExample FirstExample.cpp)

target_link_libraries(firstExample fmt::fmt-header-only blaze::blaze)
find_library(LAPACK_LIBRARIES lapack)
target_link_libraries(firstExample ${LAPACK_LIBRARIES})
