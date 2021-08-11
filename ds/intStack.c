#include <stdlib.h>
#include <intStack.h>
#include <intLinkedList.h>

// default stack length
#define stackLength 10


illNode* initIntStack()
{
    illNode* head  = (illNode*)malloc(sizeof(illNode));
    head->data     = 0;
    head->next     = NULL;
    head->prev     = NULL;
    return head;
}

void istPop( illNode* head )
{
    illRmTop(head);
}

void istPush( illNode* head, int value )
{
    if( illLenght(head) >= stackLength ){
        illRmLast(head);  
    }
    illAddToTop(head,value);
}

illNode* istPeek( illNode* head )
{
    return head->next;
}