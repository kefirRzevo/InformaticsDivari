#include <stdio.h>
#include "../include/global.h"
#include "../include/preparations.h"
#include "../include/select.h"
#include "../include/result.h"
#include "../include/check.h"

int main() {
   const char inputFile_path[] = "../data.txt";
   size_t data_size = 0;
   float resistance[DATA_MAX_SIZE] = {},
         resistance_final          = 0,
         deviation                 = 0,
         meanDeviation             = 0; 
   
   preparations(inputFile_path, resistance, &data_size);
   
   data_size = DataSelect(data_size, resistance);
   
   result(data_size, resistance, &resistance_final, &deviation);
   
   check(data_size, resistance, resistance_final, &meanDeviation);

   printf("%f +- %f\n"
          "%f", resistance_final, deviation, meanDeviation);
   
   return 0;
}
