typedef struct illNode illNode;

// some initialization
struct illNode* initIntLinkedList();

// not sufficient fot big lists
int illLenght(struct illNode* node);

// print
void illPrint(struct illNode* node);
void sprintILL(struct illNode* node, char *s);


// get pointer of last node
illNode* illLastNode(illNode* node);
// get pointer of node at index
illNode* illGetAtIndex(illNode* head, int index);


// add new node
void illAdd(illNode* node, int value);


void illAddToTop(illNode* node, int value);


void illAddToIndex(illNode* node, int index, int value);


void removeFirst(struct illNode* node);


void removeAtIndex(struct illNode* node, int index);


void removeLast(struct illNode* node);


int isContains(struct illNode* node, int index);