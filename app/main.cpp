#include <iostream>
#include <blazeHelpers.h>
#include <fmt/format.h>
#include <fmt/ostream.h>
#include <fmt/chrono.h>
#include <chrono>
int main()
{
    auto start = std::chrono::steady_clock::now();
    auto big_matrix = blazehelpers::generate_random_matrix(15);
    auto inv_matrix = blazehelpers::get_inverse(big_matrix);
    auto mean = blaze::mean(big_matrix);
    fmt::print("mean value {:.3f}\n", mean);
    blaze::DynamicMatrix<double> unity = big_matrix * inv_matrix;
    auto m = blaze::sum(unity);
    fmt::print("sum {:.3f}\n", m);
    auto end = std::chrono::steady_clock::now();
    fmt::print("finished in {}\n", std::chrono::duration_cast<std::chrono::milliseconds>(end - start));
}
