#include <catch2/catch.hpp>
#include <blazeHelpers.h>
#include <iostream>

TEST_CASE("Inverse matrix is computed correctly", "[inverse]")
{
    constexpr std::size_t matrix_size = 50;
    auto big_matrix = blazehelpers::generate_random_matrix(matrix_size);
    auto inv_matrix = blazehelpers::get_inverse(big_matrix);
    auto unity = big_matrix * inv_matrix;
    auto unity_sum = blaze::sum(unity);
    REQUIRE(unity_sum == Approx(matrix_size));
}
