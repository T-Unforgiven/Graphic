#include"Func.h"
#include <cmath>


double sinc(double x) {
	return x == 0 ? 1 : sin(x) / x;
}

double Gaus(double x) {
	double exp = 2.7182818284;
	double a = pow(exp, -pow(x, 2)/2);
	return a;
}

double polynom4(double x) {
	return pow(x, 4) + pow(x, 3) * 3 - pow(x, 2) * 6.5 + 9 * x - 27.3;
}

double prikoltan(double x) {
	return sin(pow(x,2) + 4*x -2);
}

double multicos(double x) {
	return 3*cos(pow(x, 2));
}