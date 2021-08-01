typedef struct Node Node;

// some initialization
struct Node* initIntLinkedList();

// not sufficient fot big lists
int getListLen(struct Node* node);

// print
void printIntLinkedList(struct Node* node);
void sPrintIntLinkedList(struct Node* node, char *s);
void pr(struct Node* n);


// get pointer of last node
struct Node* getlastNode(struct Node* node);


// add new node
void addNode(struct Node* node, int value);


void addToStart(struct Node* node, int value);


void addToIndex(struct Node* node, int index, int value);


void removeFirst(struct Node* node);


void removeAtIndex(struct Node* node, int index);


void removeLast(struct Node* node);


int isContains(struct Node* node, int index);