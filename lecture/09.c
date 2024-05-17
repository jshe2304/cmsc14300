double* squares_copy(double* ds, unsigned int dslen) {

    double* res = (double*)malloc(sizeof(double) * dslen);

    if (res == NULL) {
        fprintf(stderr, "squares_copy: unable to allocate result array\n"); 
        exit(1);
    }

    unsigned int i;

    for (i=0; i < dslen; i++) {
        res[i] = ds[i] * ds[i];
    }

    return res;
}

void foo() {
    double nums[] = {1, 2, 3, 4};
    double* nums_sq = squares_copy(nums, 4);
    unsigned int i;
    for (i = 0; i < 4; i++) {
        printf("%lf ", nums_sq[i]);
    }
    printf("\n");

    free(nums_sq); // every malloc needs a free
}

Test(hw3_sq, 2) {
    double nums[] = {1, 2, 3, 4};
    double nums_sq = squares_copy(nums, 4);

    cr_assert(nums_sq[0] == 1);
    cr_assert(nums_sq[3] == 16);
    
    free(nums_sq);
}

/*
How to count even numbers in an array?
Unable to append bc arrays fixed length. 
Only solution is to count evens before hand and create an array of that size 
and repass to fill the array. 
Or make evens array too big so won't run out of space. But this wastes space. 

Must trade off time vs space

Also, how can we return the length of the array for future use?
Can use external pointer for this (reslen)
*/
int* evens(int nums[], unsinged int numslen, unsigned int* reslen) {
    unsigned int nevens = 0;
    for (unsigned int i = 0; i < numslen; i++) {
        if (nums[i] % 2 == 0) {
            nevens++;
        }
    }

    int* res = (int*)malloc(sizeof(int) * nevens);
    if (res == NULL) {
        fprintf(stderr, "evens: unable to allocate result\n");
        exit(1);
    }

    unsigned int j = 0
    for (i = 0; i < numslen; i++) {
        if(nums[i] % 2 == 0) {
            res[j++] = nums[i];
        }
    }
}

void foo() {
    int ns[] = {1, 2, 3, 4};
    unsigned int nevens;
    int* es = evens(ns, 4, &nevens);

    unsigned int i;
    for (i = 0; i < nevens; i++) {
        printf("%d", es[i]);
    }

    free(es);
}

void foo() {
    double* nums = {1, 2, 3, 4};

    *nums // = [0] first element of the array
    (*nums + 2) // = nums[2] third element of the array. C automatically 
    // calculates memory shifts so 2 is not necessarily number of bytes
}