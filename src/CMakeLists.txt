find_package(blaze CONFIG REQUIRED)
add_library(blazeHelper blazeHelpers.cpp)
if(FORTRAN_LINK_DIRECTORIES)
  message(STATUS ${FORTRAN_LINK_DIRECTORIES})
  target_link_directories(blazeHelper PUBLIC ${FORTRAN_LINK_DIRECTORIES})
endif()

find_package(LAPACK)
find_package(BLAS)
# if(NOT BLAS_LIBRARIES) # try finding openblas, if this is unsucessfull too,
# user should set # BLAS_LIBRARIES explicitly find_library(BLAS_LIBRARIES
# openblas) endif()
message(STATUS "BLAS libraries: ${BLAS_LIBRARIES}")
message(STATUS "LAPACK libraries: ${LAPACK_LIBRARIES}")
target_link_libraries(
  blazeHelper
  PRIVATE project_options
  # link blas before lapack because some blas vendors are implementing optimized
  # lapack functions
  PUBLIC blaze::blaze ${BLAS_LIBRARIES} ${LAPACK_LIBRARIES})

target_include_directories(
  blazeHelper PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
                     $<INSTALL_INTERFACE:include> # <prefix>/include/mylib
)
