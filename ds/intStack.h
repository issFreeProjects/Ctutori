#include "illNode.h"
// default stack length
#define stackLength 10


/**
 *      this is simple stack implementation
 *      and, it's compatable with intLinkedList => you can use ill methodes
 *      for Ex:  use illPrint to print the stack like [a1, a2, ..., an].
 * 
 *      use following function to initialize stack and take a apointer to it
 *      then, you can use pop, push, peek functions.
 */
illNode* initIntStack();


// removes an element from the top of the stack
void istPop( illNode* head );

// adds an element to the top of the stack, if length of stack < (default stack length) = 10
// otherwise will delete last node of stack, and then push it
void istPush( illNode* head, int value );


// returns a pointer to the element on the top of the stack
illNode* istPeek( illNode* head );