#include "bstree.h"

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
bsTree* initBSTree(int headData);


// use it for print a tree
void bstPrint(bsTree *head);