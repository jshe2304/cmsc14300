// 2d array

// 1D array that is twice indexable
int m[3][5]; // 3 * 5 = 15 sequential spaces in memory

// 1D array of pointers to other arrays
int** m = (int**) malloc(sizeof(int*) * 3);

for (unsigned int i = 0; i < 3; i++) {
    m[i] = (int*) malloc(sizeof(int) * 5);
}

m[2][1] = 12;

/*
Note that 

> void foo(int a[])

is the same as

> void foo(int* a)

But, 

> void foo(int a[][])     <- 1d implementation

is not the same as

> void foo(int** a)       <- pointer implementation
*/

void foo(int a[][5], unsigned int nrows); // provided information about array

void foo(int** a, unsigned int nrows, unsigne dint ncols); // provide information about array into function