#include <stdio.h>

/*
Pointers
*/

void foo() {
    int i = 7;
    int* p = &i; //pointer to i

    int j = i; // or
    int j = *p; // dereferencing
}

int a = 7, b = 7, c = 13;
int *ap = &a, *bp = &b, *cp = &c;

/*
print(a, b, c) -> 7, 7, 13
print(ap, bp, cp) -> 10, 20, 30

a == b  -> True
a == c -> False
b == c -> False

ap == bp -> False
ap == cp -> False
bp == cp -> False

*ap == *bp -> True
*/

void swap(int i, int j) {
    int temp = i;
    i = j;
    j = i;
}

void swap() {

}

void foo() {
    int a = 7, b = 13;
    swap(a, b); 
    /* This fails bc function makes copies of int arguments. 
    function maintains local variables i, j which are filled with a, b values */
}