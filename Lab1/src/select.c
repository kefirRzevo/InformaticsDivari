#include <stdio.h>
#include <math.h>

void MasOut (float *a, int Size)
{
   if(a == NULL)
      return;
   
   int i = 0;
   
   for(i = 0; i < Size; i++)
      printf("%.5lf  ", a[i]);
   printf("\n");
}

float Averange(int M, float R[])
{
   if(R == NULL)
      return 0;
   
   float Sum = 0;
   int i = 0;
   
   for (i = 0; i < M; i++)
      Sum += R[i];
   
   return Sum/M;
}

void DeletEl(float R[], int M)
{
   if(R == NULL)
      return;
   int i = 0;
   
   for (i = 1; i <= M; i++)
      R[i - 1] = R[i];
   
   R[M - 1] = 0;
}

int DataSelect(int M, float R[])
{
   if(R == NULL)
      return 0;
   
   int i = 0;
   float averange = Averange(M, R), a = 0;
   
   //MasOut(R, M);
   for (i = 0; i < M; i++)
      if((a = fabs((R[i] - averange)/averange)) > 0.03)
      {
         DeletEl(&(R[i]), M - i);
         M--;
      }
   
   return M;
}
