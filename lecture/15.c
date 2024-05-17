// linked list implementation from last lecture:

typedef struct intlist intlist;
struct intlist {
    int val;
    intlist* next;
}

intlist* prepend(int val, intlist* next) {
    intlist* res = (intlist*) malloc(sizeof(intlist));
    res -> val = val;
    res -> next = next;
    return res;
}

// find all evens in linked list

intlist* evens(intlist* l) {
    if (l == NULL) {
        return NULL;
    }
    if (l -> val % 2 == 0) {
        return prepend(l -> val, evens(l -> next));
    }
    return evens(l -> next);
}

// freeing linked lists

void free_list(intlist* l) {
    if (l == NULL) {
        return;
    }
    free_list(l -> next)
    free(l);
}

int sum(intlist* l) {
    int res = 0;
    
    while (l != NULL) {
        res += l -> val;
        l = l -> next;
    }

    return res;
}

// free using iteration

void free_list(intlist* l) {
    while (l) {
        intlist* temp = l -> next;
        free(l);
        l = temp;
    }
}

intlist squares_copy(intlist* l) {
    intlist *head, *tail;

    if (l == NULL) {
        return NULL;
    }

    head = prepend(l -> val * l -> val, NULL);

    tail = head;
    l = l -> next;

    while (l) {
        tail -> next = prepend(l -> val * l -> val, NULL);
        tail = tail -> next;
        l = l -> next;
    }
    return head;
}