#include <cmath>
#include <iostream>

int factorial(int n) {
	if (n == 0)
		return 1;
	else
		return (n * factorial(n - 1));
}

double taylor_approx(double x, int order) {
	double val = 0.0;
	for (int i = 0; i <= order; i++) {
		val += pow(x, i) / factorial(i);
	}
	return val;
}

double pade_approx(double x, int p, int q) {
	double numerator = 0.0;
	double denominator = 0.0;

	for (int j = 0; j <= p; ++j) {
		numerator += (((pow(x, j) * factorial(p + q - j) * factorial(p)) /
					   (factorial(p + q) * factorial(j) * factorial(p - j))));
	}

	for (int j = 0; j <= q; ++j) {
		denominator += (((pow(-x, j) * factorial(p + q - j) * factorial(q)) /
						 (factorial(p + q) * factorial(j) * factorial(q - j))));
	}

	double val = numerator / denominator;
	return val;
}

int main() {
	int p = 4;
	int q = 4;
	double start = -10.0;

	for (int i = 0; i <= 20; ++i) {
		printf("%.2lf %.5lf %.5lf %.5lf %.5lf\n", start, exp(start), taylor_approx(start, 5),
			   taylor_approx(start, 7), pade_approx(start, p, q));
		start += 1;
	}

	return 0;
}
