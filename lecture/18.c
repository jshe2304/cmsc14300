typedef struct inttree inttree;
struct inttree {
    int val;
    inttree *left, *right;
}

int treesum(inttree* t) {
    if (t == NULL) {
        return 0;
    }
    return t -> val + treesum(t -> left) + treesum(t -> right);
}

int treesum(inttree* t) {
    // ternary operator (3 operands)
    return (t != NULL) ? (t -> val + treesum(t -> left) + treesum(t -> right)) : 0;
}