typedef struct illNode illNode;
struct illNode{
    int data;           // at head, stors lengh of list, and for others, stors what you set
    illNode* next;      // stors pointer to the next node
    illNode* prev;      // at head, stors last node and for others, stors previous node (ptr to ...)
};


// some initialization
illNode* initIntLinkedList();
// returns length of list (node->data)
int illLenght(illNode* node);
// get pointer of last node
illNode* illLastNode(illNode* node);
// get pointer of node at index
illNode* illGetAtIndex(illNode* head, int index);


// add new node at end
void illAdd(illNode* node, int value);
// add new node at top of list
void illAddToTop(illNode* node, int value);
// add new node at index,     ex:  0  1     index          n
//                      old list:  {} {}    {i}            {}
//                      new list:  {} {}    {newNode}{i}   {}
void illAddToIndex(illNode* node, int index, int value);


// remove first lists node
void illRmTop(illNode* node);
// remove lists node at index
void illRmAtIndex(illNode* node, int index);
// remove last node in list
void illRmLast(illNode* node);


// returns 0 if value contains in list
// returns -1 eles
int illContains(illNode* node, int value);


// print illNode like [a1, a2, ..., an]
void illPrint(illNode* head);
// print char *s before illPrint(illNode* head)
void sprintILL(illNode* head, char *s);