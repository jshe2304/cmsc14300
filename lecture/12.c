struct point {
    double x, y;
};

void foo() {
    struct point p;
    p.x = 3;
    struct point* q = (struct point*) malloc(sizeof(struct point));
    (*q).x = 12;

    q->x = 12; // idiomatic
}

struct point* point_new(double x, double y) {
    struct point* res = (struct point*) malloc(sizeof(struct point));

    if (res == NULL) {
        fprintf(stderr, "point_new: unable to allocate\n");
        exit(1);
    }

    res -> x = x; // res is a pointer so must use arrow
    res -> y = y;

    return res;
}

void point_free(struct point* p) {
    // structs may have nested allocations so sometimes may be necessary to have
    // a more complex free function to free nested allocations. 
    free(p);
}

void point_show(struct point* p) {
    printf("(%lf, %lf)", p -> x, p -> y);
}

struct point p, q;
p = q; // C copies the whole struct for you

struct point *p = point_new(1, 2);
struct point *q = point_new(3, 4);
p = q; // pointer point to same thing. 

struct point* point_copy(struct point* p) {
    return point_new(p -> x, p -> y);
}

struct circle {
    struct point center;
    double radius;
};

void foo() {
    struct circle c;
    c.center.x = 7;
    c.center.y = 7;
    c.radius = 10;

    // or

    struct circle c = {{7, 7}, 10};

    // or

    struct circle* c = (struct circle*) malloc(sizeof(struct circle));
    c -> center.x = 7;
    c -> center.y = 7;
    c -> radius = 10;

    // or

    struct circle* c = (struct circle*) malloc(sizeof(struct circle));
    c -> center = point_new(6, 7);
    c -> center -> x = 7;
    c -> radius = 10;

    // or

    struct circle c;
    c.center = point_new(6, 7)
    c.center -> x = 7;
    c.radius = 10;
}


struct point ps[] = {{1, 2}, {3, 4}};
ps[1].x = 12;
struct point* ps2 = (struct point*) malloc(sizeof(struct point) * 10);
ps[5] y = 100;