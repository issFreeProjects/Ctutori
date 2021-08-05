#ifndef BST_NODE
#define BST_NODE

typedef struct bsTree bsTree;
struct bsTree{
    int data;           // node (key)
    bsTree* rChild;     // less than data
    bsTree* lChild;     // greater than data
    bsTree* parent;     // parent of node (foh head is NULL)
};

#endif