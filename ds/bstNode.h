#ifndef BST_NODE
#define BST_NODE

typedef struct bstNode bstNode;
struct bstNode{
    int data;           // node (key)
    bstNode* rChild;     // less than data
    bstNode* lChild;     // greater than data
    bstNode* parent;     // parent of node (foh head is NULL)
};

#endif