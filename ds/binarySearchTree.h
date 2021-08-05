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


// use it for print a tree
void bstPrint(bstNode *head);