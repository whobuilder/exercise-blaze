#include <iostream>
#include <blazeHelpers.h>
#include <fmt/format.h>
#include <fmt/ostream.h>
#include <fmt/chrono.h>
#include <chrono>

double get_s_i_minus_one(){
    return 1;
}

double get_s_i(){
    return 2;
}

double get_s_i_plus_one(){
    return 3;
}

void fill_inner_nodes(blaze::DynamicMatrix<double> &m){
    for (std::size_t i = 1UL; i<(m.rows()-1); ++i){
        std::size_t j =0;
        std::generate(m.begin(i),m.end(i),[&j, i](){
                double val =0;
                if(i==j) val= get_s_i();
                if((i-1)==j) val= get_s_i_minus_one();
                if((i+1)==j) val= get_s_i_plus_one();
                ++j;
                return val;
                });
    }
}
int main()
{
    blaze::DynamicMatrix<double>my_matrix(5,5);
    //my_matrix =blaze::generate(5UL, 5UL, [](std::size_t i, std::size_t j){
    //        if (i == 0) return 0.0;
    //        if (i == 4) return 0.0;
    //        if (i==j) {
    //            return get_s_i();
    //        } else if(i ==(j-1)){
    //            return get_s_i_minus_one();
    //        } else if(i ==(j+1)) {
    //            return get_s_i_plus_one();
    //        }
    //        return 0.0;
    //        });
    fill_inner_nodes(my_matrix);
    fmt::print("{}\n",my_matrix);
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
