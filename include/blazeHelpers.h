#ifndef _BLAZEHELPER_BLAZEHELPERS_H_
#define _BLAZEHELPER_BLAZEHELPERS_H_
#include <blaze/Math.h>

namespace blazehelpers{

    blaze::DynamicMatrix<double> generate_random_matrix(std::size_t size);
    blaze::DynamicMatrix<double> get_inverse(const blaze::DynamicMatrix<double>& matrix);

} // end of blazehelpers

#endif // _BLAZEHELPER_BLAZEHELPERS_H_
