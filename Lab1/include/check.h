#ifndef CHECK_H
#define CHECK_H

#include "global.h"

Error check(const size_t data_size,
            const float *const resistance, const float resistance_final, float *const p_meanDeviation);

#endif // CHECK_H

