#include "bstNode.h"

/**
 *      This is a simple implementation of binary search tree
 * 
 *                          *  *
 *                       *        *                  
 *                      *  data=A  *   
 *                      *          *
 *                       *        * 
 *                        / *  * \
 *                       /        \
 *                      /          \
 *                 *  *              *  *
 *              *        *        *        *
 *             *  data<A  *      *  data>A  *
 *             *          *      *          *
 *              *        *        *        *
 *                 *  *              *  *
 */


// some initialize, headData is value of head node
bstNode* initBSTree(int headData);

// add new node to tree
void bstAdd( bstNode* head, int value );


// search
bstNode* bstSearchByValue(bstNode* head, int value);
int bstIsExist( bstNode* head, int value );

// min and max
bstNode* bstMIN(bstNode* head);
bstNode* bstMAX(bstNode* head);



// use it for print a tree
void bstPrint(bstNode *head);