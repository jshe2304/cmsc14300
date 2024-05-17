#include <stdio.h>

unsigned long long int factorial(unsigned int x){
    unsigned long long res = 1;
    while (x > 1) {
        res *= x--; //It is equivalent to res = res * x; x--;
    } //x-- and --x have the same purpose.  In the prefix you get the subtracted value first
    return res;
}

//Segmentation faults or segfault can occur by divinding by 0 or recursion errors.

char cmd = 'Z'; //store whatever character the user enters

/* while (cmd != 'Q') {
    printf("Enter command.");
    cmd = input();

    if (cmd == '+'){
        continue;
    }

} */

do {
    printf("Enter command.");
    cmd = input();
    if(){}
}
while (cmd != 'Q');

unsigned whatever(unsigned int x) {
    unsigned long long int res = 1;
    unsigned int i;
    for(i = x; i > 1; i--){
        res *= i;
    }
    return res

    i = x;
    while (i > 1){
        res *= i;
        i--;
    }
    return res
}

