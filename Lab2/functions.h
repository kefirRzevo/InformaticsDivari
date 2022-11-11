//part_1
int experiment (double *radioactivity, double *time, double start_time, double end_time, double step, const double betta);
void add_noise (double *radioactivity, int N);

//part_2
double nonlinear_equation (double *radioactivity, double *time, int N, double precision, double interval1, double interval2);
double model(double *radioactivity, double *time, int N, double point);
double linear_equation (double *radioactivity, double *time, int N);

//part_3
double precision_analysis (double *radioactivity, double *time, int N, double precision, double interval1, double interval2);
double dev_exp(double *radioactivity, double *time, int M, double decay_time);
double dev_linear(double *radioaktivity, double *time, int M, double decay_rate);