#include <stdio.h>
#include <stdlib.h>

unsigned long long int factorial(unsigned int x) {
    if (x == 0) return 1;
    return x * factorial(x - 1);
}

int main(int argc, char** argv) {
    unsigned long long n = factorial(atoi(argv[1]));
    printf("%llu\n", n);
    printf("%c\n", 130);
    return 0;
}