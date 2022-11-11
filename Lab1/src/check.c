#include <stdio.h>
#include "../include/check.h"

Error check(const size_t data_size,
            const float *const resistance, const float resistance_final, float *const p_meanDeviation)
{
   if (resistance == NULL || p_meanDeviation == NULL)
      return ARGUMENT_POINTER_NULL;

   size_t index = 0;
   float sum = 0;

   for (index = 0; index < data_size; index++)
      sum += resistance[index];

   *p_meanDeviation = (sum * 1000 - data_size * resistance_final) / data_size;
   
   return NOERR;
}