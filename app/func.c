#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int myfunc(int b)
{
    char *buffer = malloc(sizeof(char) * 1000);
    buffer[0] = b + 4;
    // здесь должен ругаться sonarcloud, т.к. утечка памяти
    return buffer[0];
}

int val;

int fibonachi(int num)
{
    int prev = 1;
    int next = 1;

    if (num < 0)
        return 0;

    if (num <= 2)
        return num;

    int i = 2;
    while (i < num)
    {
        next += prev;
        prev = next - prev;
        i++;
    }

    return next;
}

void printStdoutMessages()
{
    printf("This is a test message from func.c\n");
    printf("Do not disturb\n");
}

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