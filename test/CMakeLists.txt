find_package(Catch2 REQUIRED)
include(Catch)
add_library(catch_main STATIC catch_main.cpp)
target_link_libraries(catch_main PUBLIC Catch2::Catch2)

add_executable(tests tests.cpp)
target_link_libraries(tests PRIVATE blazeHelper project_options catch_main)
target_include_directories(tests PRIVATE  
  ${CMAKE_SOURCE_DIR}/include)

# automatically discover tests that are defined in catch based test files you can modify the unittests. TEST_PREFIX to
# whatever you want, or use different for different binaries
catch_discover_tests(
  tests
  TEST_PREFIX
  "unittests."
  EXTRA_ARGS
  -s
  --reporter=xml
  --out=tests.xml)

