typedef struct illNode illNode;

// some initialization
illNode* initIntLinkedList();

// not sufficient fot big lists
int illLenght(illNode* node);

// print
void illPrint(illNode* node);
void sprintILL(illNode* node, char *s);


// get pointer of last node
illNode* illLastNode(illNode* node);
// get pointer of node at index
illNode* illGetAtIndex(illNode* head, int index);


// add new node
void illAdd(illNode* node, int value);


void illAddToTop(illNode* node, int value);


void illAddToIndex(illNode* node, int index, int value);


void illRmTop(illNode* node);


void illRmAtIndex(illNode* node, int index);


void illRmLast(illNode* node);


int illContains(illNode* node, int index);