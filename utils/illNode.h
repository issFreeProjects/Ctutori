#ifndef ILL_NODE
#define ILL_NODE

typedef struct illNode illNode;
struct illNode{
    int data;           // at head, stors lengh of list, and for others, stors what you set
    illNode* next;      // stors pointer to the next node
    illNode* prev;      // at head, stors last node and for others, stors previous node (ptr to ...)
};

#endif