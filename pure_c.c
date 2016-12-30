/* Here is a C source file that defines a C function, and can be compiled and
   executed independently of Lua. Compilation:

   gcc -Wall -o pure_c pure_c.c -lm
*/

#include "math.h"
#include <stdio.h>
#include <stdlib.h>

int say_hello_from_c()
{
    printf("Hello from C!\n");
    return 0;
}

double norm(double* components, int count)
/* Simple function to compute and return the 2-norm of an n-dimensional vector
   with count elements. */
{
    int index;
    double total;
    for(index=0; index<count; index++)
    {
        total += components[index] * components[index];
    }
    return pow(total, 0.5);
}

int main(int argc, char** argv)
{
    int count;
    double* components;
    double computedNorm;

    count = 5;
    components = calloc(count, sizeof(double));
    components[0] = 0.1;
    components[1] = 0.2;
    components[2] = 0.3;
    components[3] = 0.4;
    components[4] = 0.5;
    computedNorm = norm(components, count);

    say_hello_from_c();
    printf("Norm of vector: %f\n", computedNorm);

    free(components);
    return 0;
}
