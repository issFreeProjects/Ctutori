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


int getListLen(struct Node* node)
{
    int len = 0;
    while( node->next != NULL ){
        len++;
        node = node->next;
    }
    return len;
}


void pr(struct Node* n)
{
    printf("***debug=[%d,%d]", n->data, n->next);
}


void printIntLinkedList(struct Node* node)
{
    if( node == NULL )
        printf("[ NULL ]");
    if( node->next == NULL )
        printf("[]\n");
    else{
        node = node->next; // do not print default head!
        printf("[");
        while (node != NULL) {
            printf( " %d ", node->data );
            node = node->next;
        }
        printf("]\n");
    }
}


void sPrintIntLinkedList(struct Node* node, char *s)
{
    printf("%s", s);
    printIntLinkedList(node);
}


struct Node* getlastNode(struct Node* node)
{
    return node->prev;
}


struct Node* getNodeAtIndex(struct Node* node, int index)
{
    int cursor = -1;
    while( node->next != NULL && cursor != index )
    {
        cursor++;
        node = node->next;
    }
    return node;
}


void addNode(struct Node* node, int value)
{
    struct Node *newNode    = (struct Node*)malloc(sizeof(struct Node)); // allocate memory
    newNode->data           = value;  // set new node's data
    newNode->next           = NULL;   // this oe added to end => there is no next
    newNode->prev           = node->prev;  // previous node is last node (node->prev) 
    if (node->prev != NULL)  // this new node is first node
        (node->prev)->next  = newNode;
    else node->next         = newNode; // there is some other nodes
    node->prev              = newNode; // last node in new linkes list is newNode
}


void addToStart(struct Node* node, int value)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data        = value;  // set data of new node
    newNode->next        = node->next;  // set next node of new node
    newNode->prev        = node;  // previous node of newNode is head
    node->next           = newNode;  // head's next node is newNode (it's the first node)
    if( (newNode)->next != NULL )  // linkes list was empty head
        ((newNode)->next)->prev = newNode;
}


void addToIndex(struct Node* node, int index, int value)
{  // move link to index and add newNode at first
    addToStart( getNodeAtIndex(node, index), value );
}

// dont use this function outside
void removeOnlyOneNode(struct Node* node)
{  // this works only when there is one node in the list, and will remove it
   // then will free memory. 
    node->prev = NULL;
    free(node->next);
    node->next = NULL;
}

void removeFirst(struct Node* node)
{
    if( node->next != NULL ){
        if( node->next == node->prev ){ // only one node
            removeOnlyOneNode(node);
        }else { // more than one node exist
            node->next = (node->next)->next;  // head's next node is the second node in list
            free( (node->next)->prev );  // (node->next) is the second element =>
                                         // (node->next)->prev is node that we want to remove it
            (node->next)->prev = node;   // now node->next is the first node in list
                                         // so it's previous is head
        }
    }
}


void removeAtIndex(struct Node* node, int index)
{
    if( index==0 )
        removeFirst(node);
    else{
        struct Node* toRm = getNodeAtIndex(node,index); // pointer to node that we will remove it
        if( toRm->next == NULL ){  // selected node is at the end of list
            removeLast(node);
        }else{  // exist at least one node before it and one other after it
            (toRm->prev)->next = toRm->next; // next of before node is next of toRm
            (toRm->next)->prev = toRm->prev; // preious of next node is previous of toRm
        }
        toRm = NULL; // NULL and free 
        free(toRm);
    }
}


void removeLast(struct Node* node)
{
    if( node->prev != NULL ){
            // there is at least one node
            if( node->prev == node->next )  // only one node
            {
                removeOnlyOneNode(node);
            }else {   
                node->prev = (node->prev)->prev;
                free((node->prev)->next);
                (node->prev)->next = NULL;
            }
    }
}


int isContains(struct Node* node, int value)
{
    int cursor = 0;
    while( node != NULL )
    {
        cursor++;
        if(node->data == value)
            return 0;
        else node = node->next;
    }
    return -1;
}