#include <binarySearchTree.h>
#include <stdio.h>
#include <stdlib.h>



bstNode* initBSTree(int headData)
{
    bstNode* head = (bstNode*)malloc(sizeof(bstNode));
    head->data = headData;
    head->lChild = NULL;
    head->rChild = NULL;
    head->parent = NULL;
    return head;
}


void bstAdd( bstNode* head, int value )
{
    bstNode* newNode = (bstNode*)malloc(sizeof(bstNode));
    newNode->data = value;
    newNode->lChild = NULL;
    newNode->rChild = NULL;
    
    while (1)
    {
       if( head->data > value ){
           if( head->lChild != NULL )
                head = head->lChild;
            else{
                newNode->parent = head;
                 head->lChild = newNode;
                 break;
            }
       }else if (head->data < value){
             if( head->rChild != NULL )
                head = head->rChild;
            else {
                newNode->parent = head;
                head->rChild = newNode;
                break;
            }
       } else break;
    }
}


bstNode* bstSearchByValue( bstNode* head, int value )
{
    while( head != NULL )
    {
        if( head->data == value )
            return head;
        else if( head->data > value )
            head = head->lChild;
        else head = head->rChild;
    }
    return NULL;
}


int bstIsExist( bstNode* head, int value )
{
    if( bstSearchByValue(head,value) != NULL )
        return 0;
    else return -1;
}


bstNode* bstMAX(bstNode* head)
{
    while ( head->rChild != NULL )
        head = head->rChild;
    return head;
}   


bstNode* bstMIN(bstNode* head)
{
    while ( head->lChild != NULL )
        head = head->lChild;
    return head;
}


// internal method
int _print_t(bstNode *tree, int is_left, int offset, int depth, char s[20][255])
{
    char b[20];
    int width = 5;

    if (!tree) return 0;

    sprintf(b, "(%03d)", tree->data);

    int left  = _print_t(tree->lChild,  1, offset,                depth + 1, s);
    int right = _print_t(tree->rChild, 0, offset + left + width, depth + 1, s);

#ifdef COMPACT
    for (int i = 0; i < width; i++)
        s[depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[depth - 1][offset + left + width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[depth - 1][offset - width/2 + i] = '-';

        s[depth - 1][offset + left + width/2] = '.';
    }
#else
    for (int i = 0; i < width; i++)
        s[2 * depth][offset + left + i] = b[i];

    if (depth && is_left) {

        for (int i = 0; i < width + right; i++)
            s[2 * depth - 1][offset + left + width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset + left + width + right + width/2] = '+';

    } else if (depth && !is_left) {

        for (int i = 0; i < left + width; i++)
            s[2 * depth - 1][offset - width/2 + i] = '-';

        s[2 * depth - 1][offset + left + width/2] = '+';
        s[2 * depth - 1][offset - width/2 - 1] = '+';
    }
#endif

    return left + width + right;
}


// print bst
void bstPrint(bstNode *head)
{
    char s[30][255];
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    _print_t(head, 0, 0, 0, s);

    for (int i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}