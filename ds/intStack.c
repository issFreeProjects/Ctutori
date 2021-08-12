#include <stdlib.h>
#include <stdio.h>
#include <intStack.h>
#include <intLinkedList.h>



illNode* initIntStack()
{
    return initIntLinkedList();
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