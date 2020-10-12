#include <math.h>
#include <stdio.h>
#include <string.h>

double map(double arg, double start_src, double stop_src, double start_dst, double stop_dst) {
	double output;
	double e1 = start_dst;
	double e2 = stop_dst - start_dst;
	double e3 = arg - start_src;
	double e4 = stop_src - start_src;
	output = e1 + e2 * (e3 / e4);

	char *mess = "";
	if (isinf(output)) {
		mess = "infinity";
	} else if((output != output) || isnan(output)) {
		mess = "NaN";
	}
	if(strlen(mess) > 0)
		printf("map(%f, %f, %f, %f, %f) result is %s\n",arg,start_src,stop_src,start_dst,stop_dst,mess); 
	return (output);
}


int map_int(int arg, int start_src, int stop_src, int start_dst, int stop_dst) {
	double res = map((double)arg, (double)start_src, (double)stop_src, (double)start_dst, (double)stop_dst);
	return ((int)res);
}

int main() {
	float res_float = map(3.0f, 0.0f, 10.0f, 0.0f, 100.0f);
	int res_int = map_int(3, 0, 10, 0, 100);
	printf("map: %f\n", res_float);
	printf("map int: %i\n", res_int);
}