#include <stdio.h>
#include "../include/preparations.h"

Error preparations(const char *const inputFile_path, float *const resistance, size_t *const p_data_size)
{
   if (inputFile_path == NULL)
      return INPUT_PATH_NULL;
   
   if (p_data_size == NULL)
      return ARGUMENT_POINTER_NULL;
   
   FILE *const inputFile = fopen(inputFile_path, "r");
  
   if (inputFile == NULL)
      return INPUT_FILE_NOT_OPENED;
   
   float voltage[DATA_MAX_SIZE],
         current[DATA_MAX_SIZE];
   size_t data_size = 0,
          index     = 0;

   while (fscanf(inputFile,"%f%*c%f", voltage + data_size, current + data_size) == 2)
      data_size++;
   
   for (index = 0; index < data_size; index++)
      resistance[index] = voltage[index] / current[index];
   
   *p_data_size = data_size;
   
   return NOERR;
}