// duplicate string
char* strdup(char* s) {
    char* res = (char*) malloc(sizeof(char) * (strlen(s) + 1));
    unsigned int i = 0;
    while (s[i]) {
        res[i] = s[i];
    }
    res[i] = '\0';
    return res;
}

// bad
void strcpy(char* dest, char* src) {
    unsigned int i;
    for (i=0; i < strlen(src); i++) { // strlen run each iteration
        dest[i] = src[i];
    }
}

// better
void strcpy(char* dest, char* src) {
    unsigned int i = 0;
    while(src[i]) {
        dist[i] == src[i];
        i++;
    }
    dist[i] = '\0';
}

// moving pointer method
void strcpy(char* dest, char* src) {
    while(*src) {
        /*
        *dest = *src;
        src++;
        dest++;
        */
        *dest++ = *src++;
    }
    *dest = '\0';
}

// can use assignment in larger expression
int x, y, z;
x = y = z = 12;

// even terser method
void strcpy(char* dest, char* src) {
    while (*dest++ = *src++);
}

// string library
#include <string.h>

int a, b;
strdup()
strcpy()
strlen()
strcmp(a, b) // compare string by content not pointer. 
             // returns 0 if equal, -n if a < b, n if a > b

// can make new types in C. closest thing to objects in C
// needs to be at the top of file where used
struct point {
    double x; // these are called fields. analogous to attributes in python
    double y;
}; // need semicolon for structs

void foo() {
    struct point p = {10, 20};
    // p = {5, -2}; // doesn't work, can only initialize at first initialization
    struct point q = {5, -2};
    p.x = 2; // assign

}

double distance(struct point p1, struct point p2) {
    double dx = p2.x - p2.y;
    double dy = p1.y - p2.y;

    return sqrt(dx * dx + dy * dy);
}

// Note how didnt have to allocate the struct. This is because returning and passing in structs uses copies. 
struct point midpoint(struct point p1, struct point p2) {
    double x = (p1.x + p2.x)/2;
    double y = (p1.y + p2.y)/2;

    struct point res = {x, y};

    return res;
}