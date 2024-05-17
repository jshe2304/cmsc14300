struct point {
    double x, y;
};

struct circle {
    struct point center;
    double radius;
};

struct square {
    struct point topleft;
    double side;
};

struct rectangle {
    struct point topleft;
    double width, height;
};

struct shape {
    struct circle c;
    struct square s;
    struct rectangle r;

    char type; // type = 'R' <- rectangle
};

/*
shape in memory 

circle   square  rectangle
_________________________
| x | y | x | y | x | y |
|___|___|___|___|___|___|
|   r   |   s   | h | w |
|_______|_______|___|___|

*/

// how can we store what type of shape it is?

enum shape_tag {
    CIRCLE, SQUARE, RECTANGLE;
}

struct shape {
    struct circle c;
    struct square s;
    struct rectangle r;

    enum shape_tag tage; // type = 'R' <- rectangle
};

// how can we get around having to allocate memory for 3 different shapes?

union shape { // allocates enough memory to store the largest attribute, in this case the rectangle
    struct circle c;
    struct square s;
    struct rectangle r;
};


// one shape and one tag

struct tagged_shape {
    union shape u;
    enum shape_tag tag;
}

struct tagged_shape shp;
shp.u.r.topleft.x = 10;
shp.u.r.topleft.y = 20;
shp.u.r.width = 5;
shp.u.r.height = 3;
shp.tag = RECTANGLE;

double shape_area(struct tagged_shape s) {
    switch (s.tag) {
        case CIRCLE:
            return M_PI * s.u.c.radius * s.u.c.radius;
        case SQUARE:
            return s.u.s.side * s.u.s.side;
        case RECTANGLE;
            return s.u.r.width * s.u.r.height;
        default:
            fprintf(stderr, 'shape_area: invalid shape tag\n');
            exit(1);
    }
}