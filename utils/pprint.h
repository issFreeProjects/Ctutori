#include "../ds/illNode.h"

int test();
// print an int array like [1, 2, 3]
void printIntArr( int *arr, int size);
// print *s[1,2,3]
void sprintIntArr( char *s, int *arr, int size );

// display like: `65535 = 00000000 00000000 11111111 11111111`
void displayBits( unsigned value );

/*
 *      use this functions to print illNode
 */
// print illNode like [a1, a2, ..., an]
void illPrint(illNode* head);
// print char *s before illPrint(illNode* head)
void sprintILL(illNode* head, char *s);