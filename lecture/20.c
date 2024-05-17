// right shift operator

1010111 >> 2 = 10101

// to extract last few bits, use bit mask

10101010100101010101010 & 1111 = 1010

// and operator extracts last 4 bits
// to extract last n bits, and with binary number of n ones
// typically, mask writeen in hex for ease

// hex written as:

0x1f == 15 == 11111

// extract last 5 bits

n & 0x1f

// writing numbers in octal w leading zero

074

// pointers to functions

int add10(int x) {
    return x + 10;
}

void foo() {
    int (*f)(int);

    f = &add10;

    int y = (*f){5};
}

// or

void foo() {
    int (*f)(int);

    f = add10;

    int y = f{5};
}