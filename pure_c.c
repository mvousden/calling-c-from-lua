/* Here is a C source file that defines a C function, and can be compiled and
   executed independently of Lua. */

#include <stdio.h>

int say_hello_from_c()
{
    printf("Hello from C!\n");
    return 0;
}

int main(int argc, char** argv)
{
    say_hello_from_c();
    return 0;
}
