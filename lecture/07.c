void foo(){
    int i = 7;
    int* p = &i; //Ampersand asks c for the location of i

    int j = *p; //"dereferencing"(*), give me the same as j = i, just p is location
    //reinitializing i doesn't change the value of j

    int a = 7, b = 7, c = 13;
    int *ap = &a, *bp = &b, *cp = &c;
    //a == b is true but no other comparison will be true as they're either storing different adresses or numbers
    //*ap == *bp is true because you are dereferencing the variables
}

void swap(int *i, int *j){
    /* int temp = i;
    i = j;
    j = temp; */
    int temp = *i;
    *i = *j;
    *j = temp;
}

void bar (){
    int a = 7, b = 13;
    swap(&a, &b);
}

void vector_add (double x1, double y1, double x2, double y2, double *xr, double *yr) {
    *xr = x1 + x2;
    *yr = y1 + y2;//Let's you return multiple values. Output parameters.
}

void baz(){
    double x, y;
    vector_add(10, 20, 1, 2, &x, &y);
    printf("%lf %lf\n", x, y);
}

/*
Arrays have to be the same type and have a fixed length. They're stored sequentially,
and have very fast indexing. CS uses 0 based indexing because of pointer calculations
in arrays.
*/

void bat(){
    double a[4] = {12.5, -24, 8.2, 63.7};//C can count so the legnth is optional
    //You're not allowed to change the entire array at once after initializing
    a[1] = 7;
    double q = a[0]//You can't do negative index, slice, or know the length
}
