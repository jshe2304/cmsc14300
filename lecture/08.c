double sum(double* ds, unsigned int dslen) {
    double res = 0;
    unsigned int i;

    for (i=0; i < dslen; i++) {
        res += ds[i];
    }

    return res;
}

//Alternate typing for arrays

double sum(double ds[], unsigned int dslen) {
    double res = 0;
    unsigned int i;

    for (i=0; i < dslen; i++) {
        res += ds[i];
    }

    return res;
}

void squares_change(double* ds, unsigned int dslen) {
    unsigned int i;
    for (i=0; i < lslen; i++) {
        ds[i] = ds[i] * ds[i];
    }
}

//Bad implementation!!
double* void squares_copy(double* ds, unsigned int dslen) {
    double res[dslen];

    for (i=0; i < lslen; i++) {
        ds[i] = ds[i] * ds[i];
    }

    return res; 
    // Returns pointer! Not array! Actual array
    // gets garbage collected and pointer points to nothing. 

    // Can't return *res because *res points to the first double in the array

    //This is a feature of the stack. To do this must use the heap!
}

#include <stdlib.h>

// Implementation on the heap!
double* void squares_copy(double* ds, unsigned int dslen) {

    double* res = (double*)malloc(sizeof(double) * dslen);
    // malloc: memory allocate
    // takes in number of bytes of memory needed
    // returns generic pointer void*. if malloc fails bc not enough memory, returns 0 pointer
    // therefore must typecast generic pointer to double pointer

    // sizeof: size of type
    // sizeof takes in a type. ie for double it returns 8 bytes

    if (res == NULL) { // Check if malloc failed and returned 0/NULL pointer
        fprintf(stderr, "squares_copy: unable to allocate result array\n"); 
        // File print format string. stderr is a special 'file' to display messages without buffer
        exit(1); // Quits program
    }

    unsigned int i;

    for (i=0; i < dslen; i++) {
        res[i] = ds[i] * ds[i];
    }

    return res;
}

void foo() {
    double a[] = {1, 2, 3, 4};

    double* a_sq = squares_copy(a, 4);

    unsigned int i;
    for(i = 0; i < 4; i++) {
        printf("lf ", a_sq[i]);
    }

    printf("\n");

    free(a_sq); // Frees heap memory. Recall heap allocations persist till they are freed explicitly. 
}
