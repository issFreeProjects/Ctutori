#include <binarySearchTree.h>
#include <stdio.h>
#include <stdlib.h>



bsTree* initBSTree(int headData)
{
    bsTree* head = (bsTree*)malloc(sizeof(bsTree));
    head->data = headData;
    head->lChild = NULL;
    head->rChild = NULL;
    head->parent = NULL;
    return head;
}


void bstAdd( bsTree* head, int value )
{
    bsTree* newNode = (bsTree*)malloc(sizeof(bsTree));
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


// internal method
int _print_t(bsTree *tree, int is_left, int offset, int depth, char s[20][255])
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
void bstPrint(bsTree *head)
{
    char s[30][255];
    for (int i = 0; i < 20; i++)
        sprintf(s[i], "%80s", " ");

    _print_t(head, 0, 0, 0, s);

    for (int i = 0; i < 20; i++)
        printf("%s\n", s[i]);
}