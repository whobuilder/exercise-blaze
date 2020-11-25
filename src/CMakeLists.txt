find_package(blaze)
add_library(blazeHelper blazeHelpers.cpp)
if(FORTRAN_LINK_DIRECTORIES)
    message(STATUS ${FORTRAN_LINK_DIRECTORIES})
    target_link_directories(blazeHelper PUBLIC ${FORTRAN_LINK_DIRECTORIES})
endif()

find_library(LAPACK_LIBRARIES lapack)
target_link_libraries(
  blazeHelper
  PRIVATE 
          project_options
          project_warnings
  PUBLIC
          blaze::blaze
          ${LAPACK_LIBRARIES}
)

target_include_directories(blazeHelper PUBLIC
  $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>  # <prefix>/include/mylib
)
