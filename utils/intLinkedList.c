#include <intLinkedList.h>
#include <pprint.h>
#include <stdio.h>
#include <stdlib.h>

/* 
       head         second         third
        |             |             |
        |             |             |
    +---+---+     +---+---+     +----+----+
    | 1  | o----->| 2 | o-----> |  # |  # |
    +---+---+     +---+---+     +----+----+      */

struct Node {
    int data;
    struct Node* next;  // stors pointer to the next node
    struct Node* prev;  // at head, stors last node and for others, stors previous node (ptr to ...)
};


struct Node* initIntLinkedList()
{
    struct Node* head = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 0;
    head->next = NULL;
    head->prev = NULL;
    return head;
}


int getListLen(struct Node* head)
{
    int len = 0;
    while( head->next != NULL ){
        len++;
        head = head->next;
    }
    return len;
}


void pr(struct Node* head)
{
    printf("***debug=[%d,%d]", head->data, head->next);
}


void printIntLinkedList(struct Node* head)
{
    if( head == NULL )
        printf("[ NULL ]");
    if( head->next == NULL )
        printf("[]\n");
    else{
        head = head->next; // do not print default head!
        printf("[");
        while (head != NULL) {
            printf( " %d ", head->data );
            head = head->next;
        }
        printf("]\n");
    }
}


void sPrintIntLinkedList(struct Node* head, char *s)
{
    printf("%s", s);
    printIntLinkedList(head);
}


struct Node* getlastNode(struct Node* head)
{
    return head->prev;
}


struct Node* getNodeAtIndex(struct Node* head, int index)
{
    int cursor = -1;
    while( head->next != NULL && cursor != index )
    {
        cursor++;
        head = head->next;
    }
    return head;
}


void addNode(struct Node* head, int value)
{
    struct Node *newNode    = (struct Node*)malloc(sizeof(struct Node)); // allocate memory
    newNode->data           = value;  // set new node's data
    newNode->next           = NULL;   // this oe added to end => there is no next
    newNode->prev           = head->prev;  // previous node is last node (head->prev) 
    if (head->prev != NULL)  // this new node is first node
        (head->prev)->next  = newNode;
    else head->next         = newNode; // there is some other nodes
    head->prev              = newNode; // last node in new linkes list is newNode
}


void addToStart(struct Node* head, int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data        = value;  // set data of new node
    newNode->next        = head->next;  // set next node of new node
    newNode->prev        = head;  // previous node of newNode is head
    head->next           = newNode;  // head's next node is newNode (it's the first node)
    if( (newNode)->next != NULL )  // linkes list was empty head
        ((newNode)->next)->prev = newNode;
}


void addToIndex(struct Node* head, int index, int value)
{  // move link to index and add newNode at first
    addToStart( getNodeAtIndex(head, index), value );
}

// dont use this function outside
void removeOnlyOneNode(struct Node* head)
{  // this works only when there is one node in the list, and will remove it
   // then will free memory. 
    head->prev = NULL;
    free(head->next);
    head->next = NULL;
}

void removeFirst(struct Node* head)
{
    if( head->next != NULL ){
        if( head->next == head->prev ){ // only one node
            removeOnlyOneNode(head);
        }else { // more than one node exist
            head->next = (head->next)->next;  // head's next node is the second node in list
            free( (head->next)->prev );  // (head->next) is the second element =>
                                         // (head->next)->prev is node that we want to remove it
            (head->next)->prev = head; // now head->next is the first node in list so it's previous is the head
        }
    }
}


void removeAtIndex(struct Node* head, int index)
{
    if( index==0 )
        removeFirst(head);
    else{
        struct Node* toRm = getNodeAtIndex(head,index); // pointer to node that we will remove it
        if( toRm->next == NULL ){  // selected node is at the end of list
            removeLast(head);
        }else{  // exist at least one node before it and one other after it
            (toRm->prev)->next = toRm->next; // next of before node is next of toRm
            (toRm->next)->prev = toRm->prev; // preious of next node is previous of toRm
        }
        toRm = NULL; // NULL and free 
        free(toRm);
    }
}


void removeLast(struct Node* head)
{
    if( head->prev != NULL ){
            // there is at least one node
            if( head->prev == head->next )  // only one node
            {
                removeOnlyOneNode(head);
            }else {   
                head->prev = (head->prev)->prev;
                free((head->prev)->next);
                (head->prev)->next = NULL;
            }
    }
}


int isContains(struct Node* head, int value)
{
    int cursor = 0;
    while( head != NULL )
    {
        cursor++;
        if(head->data == value)
            return 0;
        else head = head->next;
    }
    return -1;
}