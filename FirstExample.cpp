#include <iostream>
#include <random>
#include <blaze/Math.h>
#include <fmt/format.h>
#include <fmt/ostream.h>
#include <fmt/chrono.h>
#include <chrono>
using blaze::StaticVector;
using blaze::DynamicVector;
using blaze::DynamicMatrix;
int main()
{
    auto start = std::chrono::steady_clock::now();
//    StaticVector<int, 3UL> a{ 4, -2, 5};
//
//    DynamicVector<int> b( 3UL );
//    b[0] = 4;
//    b[1] = -1;
//    b[2] = 3;
//
//    DynamicVector<int> c = a + b;
//
//    fmt::print("c =\n{} \n", c);
//    DynamicMatrix<int> A ( 2UL, 3UL, 0);
//
//    A(0, 0) = 1;
//    A(0, 2) = 4;
//    A(1, 1) = -2;
//    DynamicVector<int> y = A * b;
//
//    fmt::print("y=\n{}\n", y);
//    fmt::print("{}X\n{}=\n{}", A, b, y);
//    blaze::StaticVector<double,3> mathVec{1,2,3};
//    blaze::StaticMatrix<double,3,3> mathMatrix {{1,2,0},{0,1,4},{0,7,1}};
//    auto secVec = mathVec*2;
//    fmt::print("vector:\n{}\n",secVec);
//    auto multip = blaze::trans(secVec) * mathMatrix;
//    fmt::print("vector:\n{}\n",multip);
    std::random_device rnd_device;
    std::mt19937 gen(rnd_device());
    std::uniform_real_distribution<double> dis(0.0, 100.0);
    blaze::DynamicMatrix<double> bigMatrix;
    bigMatrix = blaze::generate(1000UL, 1000UL, [&](std::size_t i, std::size_t j){return dis(gen);});  
    auto invMatrix = blaze::inv(bigMatrix);
    auto mean = blaze::mean(bigMatrix);
    fmt::print("mean value {:.3f}\n", mean);
    blaze::DynamicMatrix<double> unity = bigMatrix * invMatrix;
    auto m = blaze::sum(unity);
    fmt::print("sum {:.3f}\n", m);
    auto end = std::chrono::steady_clock::now();
    fmt::print("finished in {}\n", std::chrono::duration_cast<std::chrono::milliseconds>(end- start));
}
