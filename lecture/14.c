// linked list

struct intlist {
    int val;
    struct intlist* next; // this doesnt work! circular dependency!!
};

typedef unsigned long long int ullint;

// workaround

typedef struct intlist intlist; // this allows definition of pointer before struct creation

struct intlist {
    int val;
    intlist* next;
}

// add to beginning of linked list. returned value is the new head. 

intlist* prepend(int val, intlist* next) {
    intlist* res = (intlist*) malloc(sizeof(intlist));
    res -> val = val;
    res -> next = next;
    return res;
}

// [7, 13, 26]
intlist* l = prepend(7, 
                     prepend(13, 
                             prepend(26,
                                     NULL)))

// add 0 to top of stack

l = prepend(0, l)

// linked list functions

int sum(intlist* l) {
    if (l == NULL) {
        return 0;
    }

    return l -> val + sum(l -> next);
}

void square_change(intlist* l) {
    if (l == NULL) {
        return;
    }

    l -> val = l -> val * l -> val;

    squares_change(l -> next)
}

intlist* squares_copy(intlist* l) {
    if (l == NULL) {
        return NULL;
    }

    return prepend(l -> val * l -> val, squares_copy(l -> next));
}