#include "illNode.h"


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


// replacement
// replace two node in list n1, n2 (illNode pointer)
void illReplace(illNode* n1, illNode* n2);