#ifndef MYFUNC_H
#define MYFUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int quadratic(double a, double b, double c, double* roots);
int myfunc(int b);
int fibonachi(int num);
void printStdoutMessages();

extern int val;

#endif // MYFUNC_H