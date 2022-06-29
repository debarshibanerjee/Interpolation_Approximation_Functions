#include <chrono>
#include <cmath>
#include <iostream>
#include <random>

// y = sqrt(x)
// f(x) = y^2 - x = 0
// df/dy = 2y

double f(double y, double x) {
	return y * y - x;
}

double dfdy(double y, double x) {
	return 2.0 * y;
}

void nr_4(double y,
		  double x,
		  unsigned int n_points,
		  double h,
		  double x_start,
		  unsigned int max_iter) {
	/* std::mt19937_64 rng; */
	/* uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count(); */
	/* std::seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32)}; */
	/* rng.seed(ss); */
	/* std::uniform_real_distribution<double> unif(0, 1); */
	for (int j = 0; j < n_points; j++) {
		x = x_start + (j)*h;
		y = x;
		/* y = unif(rng); */
		for (int i = 0; i <= max_iter; i++) {
			y = y - f(y, x) / dfdy(y, x);
		}
		std::cout << x << "\t" << std::sqrt(x) << "\t" << y << "\t" << std::abs(std::sqrt(x) - y)
				  << std::endl;
	}
}

void nr_main(double y, double x, unsigned int n_points, double h, double x_start, double eps) {
	/* std::mt19937_64 rng; */
	/* uint64_t timeSeed = std::chrono::high_resolution_clock::now().time_since_epoch().count(); */
	/* std::seed_seq ss{uint32_t(timeSeed & 0xffffffff), uint32_t(timeSeed >> 32)}; */
	/* rng.seed(ss); */
	/* std::uniform_real_distribution<double> unif(0, 1); */
	for (int j = 0; j < n_points; j++) {
		x = x_start + (j)*h;
		double true_val = std::sqrt(x);
		y = x;
		/* y = unif(rng); */
		unsigned int iter = 0;
		double diff = std::abs(true_val - y);
		/* std::cout << x << "\t" << diff << "\t" << true_val << std::endl; */
		while (diff > eps) {
			iter += 1;
			y = y - f(y, x) / dfdy(y, x);
			diff = std::abs(true_val - y);
		}
		std::cout << x << "\t" << diff << "\t" << iter << std::endl;
	}
}

int main() {
	unsigned int n_points = 100;
	unsigned int max_iter = 4;
	unsigned int cnt = 0;
	double x;
	double y;
	double x_start = 0.2;
	double x_end = 20.2;
	double h = (x_end - x_start) / n_points;
	double eps = 1.e-14;

	nr_4(y, x, n_points, h, x_start, max_iter);
	nr_main(y, x, n_points, h, x_start, eps);

	return 0;
}

