#include <stdio.h>
#include <math.h>
#include "../include/result.h"

Error result (int data_size, float *resistance, float *const p_resistance_final, float *const p_devitation)
{
   if (resistance == NULL || p_resistance_final == NULL || p_devitation == NULL)
      return ARGUMENT_POINTER_NULL;
      
   size_t index = 0;
   float resistance_final = 0,
         devitation       = 0,
         temp             = 0,
         sum              = 0;

   for (index = 0; index < data_size; index++)
      resistance_final += resistance[index];
   resistance_final /= data_size;
   
   for (index = 0; index < data_size; index++)
   {
      temp  = resistance[index] - resistance_final;
      sum  += temp * temp;
   }

   devitation = sqrt(sum) / data_size;

   *p_resistance_final = resistance_final * 1000;
   *p_devitation       = devitation * 1000;

   return NOERR;
}