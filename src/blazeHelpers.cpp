#include<blazeHelpers.h>
#include<random>

namespace blazehelpers {

blaze::DynamicMatrix<double> generate_random_matrix(std::size_t size)
{
    std::random_device rnd_device;
    std::mt19937 gen(rnd_device());
    std::uniform_real_distribution<double> dis(0.0, 100.0);
    blaze::DynamicMatrix<double> bigMatrix;
    bigMatrix = blaze::generate(size, size, [&](std::size_t, std::size_t){return dis(gen);});  
    return bigMatrix;
}

blaze::DynamicMatrix<double> get_inverse(const blaze::DynamicMatrix<double>& matrix)
{
    return blaze::inv(matrix);
}

}
