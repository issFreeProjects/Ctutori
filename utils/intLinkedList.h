typedef struct illNode illNode;

// some initialization
struct illNode* initIntLinkedList();

// not sufficient fot big lists
int illLenght(struct illNode* node);

// print
void printIntLinkedList(struct illNode* node);
void sPrintIntLinkedList(struct illNode* node, char *s);
void pr(struct illNode* n);


// get pointer of last node
struct illNode* getlastNode(struct illNode* node);


// add new node
void addNode(struct illNode* node, int value);


void addToStart(struct illNode* node, int value);


void addToIndex(struct illNode* node, int index, int value);


void removeFirst(struct illNode* node);


void removeAtIndex(struct illNode* node, int index);


void removeLast(struct illNode* node);


int isContains(struct illNode* node, int index);