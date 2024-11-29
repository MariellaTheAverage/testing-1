#include "main.h"
#include <math.h>

int quadratic(double a, double b, double c, double* roots) {
    double disc = b * b - 4 * a * c;

    if (disc < 0) {
	roots[0] = roots[1] = 0.0;
	return 0;
    } else {
        if (disc == 0) {
            roots[0] = -b / (2 * a);
            roots[1] = roots[0];  
        } else {
            roots[0] = (-b + sqrt(disc)) / (2 * a);
            roots[1] = (-b - sqrt(disc)) / (2 * a);
        }

        return 1;
    }
}