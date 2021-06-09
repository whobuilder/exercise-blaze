add_executable(blazeApp main.cpp)
find_package(FMT REQUIRED)

target_include_directories(
  blazeApp PUBLIC $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
                  $<INSTALL_INTERFACE:include> # <prefix>/include/mylib
)

target_link_libraries(blazeApp PRIVATE blazeHelper project_options
                                       fmt::fmt-header-only)
