// how to optimize storage of values that do not fit the entire data type

// ie HDR10: r, g, b: 0-1023
// we are thus wasting bits since no datatype embodies this range
struct rgb10 {
    unsigned short r, g, b; // inefficient! short: 0-65535. 37.5% of memory wasted
}

// how do we do this?

// first, some operators in C

&& // and operator
|| // or operator
! // not operator
& // bitwise and operator. important! distinct from address operator!
| // bitwise or operator
~ // bitwise not operator. only one operand
<< n // bit shift left by n places