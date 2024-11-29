#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char *argv[])
{

    if (argc - 1 != 3)
    {
        printf("Provide 3 arguments (%d given)!\n", argc-1);
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);

    double roots[2];

    int rootcnt = quadratic(a, b, c, roots);

    if (rootcnt == 0)
    {
        printf("No real roots\n");
    }
    else if (roots[0] == roots[1])
    {
        printf("1 unique root: %.2f\n", roots[0]);
    }
    else
    {
        printf("2 roots: %.2f and %.2f\n", roots[0], roots[1]);
    }
    return 0;
}