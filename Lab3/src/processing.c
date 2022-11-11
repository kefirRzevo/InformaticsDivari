#include "../include/processing.h"


static float coordinates_to_float (struct coordinates Ship)
{
	float Num = 0;
	
	Num = (float)Ship.degree + (( (float)Ship.minute + ( (float)Ship.second / 60)) / 60); 

	return Num;
}


static float find_k (struct position first, struct position second)
{
	float N1x = coordinates_to_float(first.latitude),
          N1y = coordinates_to_float(first.longitude), 
          N2x = coordinates_to_float(second.latitude),
          N2y = coordinates_to_float(second.longitude); 
    
    float k = (N1x - N2x) / (N1y - N2y);
	
	return k;
}


static int find_max_min(float Mas[4], int param)
{
	int i = 0, pos = 0;
	float Max = Mas[0], 
          Min = Mas[0];

	if (param >= 0)
	{
		for (i = 1; i < 4; i++)
			if ( Max < Mas[i] )
			{
				Max = Mas[i];
				pos = i;
			}	
	}
	else 
	{
		for (i = 1; i < 4; i++)
			if (Min > Mas[i])
			{
				Min = Mas[i];
				pos = i;
			}
	}

	return pos;
}


static void danger_identification(int N, float* slopes, int *danger)
{
	int i = 0, Min = 0, Max = 0;

	for (i = 0; i < N; i++)
	{
		Min = find_max_min(&slopes[i * N], -1);
		Max = find_max_min(&slopes[i * N], 1);
		
		if (Max == 0 || Min == 0)
			danger[i] = 0;
		else 
			danger[i] = 1; 		
	}
}




static void matrix_of_slopes(int N, struct position *ship, struct fig triangle, struct position port, float* slopes)
{
	int i = 0;
	float apex1 = 0,
		  apex2 = 0,
		  apex3 = 0;

	for (i = 0; i < N; i++)	
	{
		slopes[i * N + 0] = find_k(port, ship[i]);
		slopes[i * N + 1] = find_k(triangle.apex1, ship[i]);
		slopes[i * N + 2] = find_k(triangle.apex2, ship[i]);
		slopes[i * N + 3] = find_k(triangle.apex3, ship[i]);
	}
}


void make_danger_array(int N, struct position* ship, struct fig* triangle, struct position* port, int** danger)
{
	float* slopes = (float* ) calloc(4 * N, sizeof(float));
	assert(slopes);

    *danger = (int* ) calloc(N, sizeof(int));
    assert(danger);

    matrix_of_slopes(N, ship, *triangle, *port, slopes);
    danger_identification(N, slopes, *danger);

    free(slopes);
}
