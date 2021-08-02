#include "illNode.h"

/**
 * 
 *      this is intLinkedList (briefly ill) header file
 *      and this module uses illNode struct and implements simple and fast linked list
 *      Ex:  
 *           head               first         second                    end
 *           |                  |             |                         |
 *           |                  |             |                         |
 *           +-------------+    +--------+    +--------+                +-----------+
 *           | data=length |    | data=# |    | data=# |                | data=#    |
 *           +-------------+    +--------+    +--------+                +-----------+
 *           | next -------|--> | next --|--> | next --|--------------> | next=NULL |
 *           +-------------+    +--------+    +--------+                +-----------+
 *      -----|------- prev | <--|-- prev | <--|-- prev | <--------------|----- prev | <------      
 *      |    +-------------+    +--------+    +--------+                +-----------+       |
 *      |                                                                                   |
 *      |------------------------------------------------------------------------------------
 * 
 *      you can use any of following functions on illNode struct
 */


// some initialization
illNode* initIntLinkedList();
// returns length of list (node->data)
int illLenght(illNode* node);
// get pointer of last node
illNode* illLastNode(illNode* node);
// get pointer of node at index
illNode* illGetAtIndex(illNode* head, int index);
// get data (int) of node at index in list
int illData(illNode* head, int index);


// add new node at end
void illAdd(illNode* node, int value);
// add new node at top of list
void illAddToTop(illNode* node, int value);
// add new node at index,     ex:  0  1     index          n
//                      old list:  {} {}    {i}            {}
//                      new list:  {} {}    {newNode}{i}   {}
void illAddToIndex(illNode* node, int index, int value);


// remove first lists node
void illRmTop(illNode* node);
// remove lists node at index
void illRmAtIndex(illNode* node, int index);
// remove last node in list
void illRmLast(illNode* node);


// returns 0 if value contains in list
// returns -1 eles
int illContains(illNode* node, int value);


// replacement
// replace two node in list n1, n2 (illNode pointer)
void illReplace(illNode* n1, illNode* n2);
// replace by index (data at index i1 and i2 will replace)
void illReplaceIndex(illNode* head, int i1, int i2);


/**
 *      here is some printing methods
 */
// print illNode like [a1, a2, ..., an]
void illPrint(illNode* head);
// print char *s before illPrint(illNode* head)
void sprintILL(illNode* head, char *s);



/**
 *      here is some sorting algorithms for this datastructure
 */

// Bubble sort sorting algorithm - pass head of illNode struct
void illBubbleSort(illNode* head);