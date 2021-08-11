/*
 * main.c file 
 * created at 24/7/2021
 *
 * */

#include <stdio.h>
#include <string.h>

#include <utils/hash.h>
#include <utils/sort.h>
#include <utils/ptrs.h>
#include <utils/mmath.h>
#include <utils/pprint.h>

#include <ds/intStack.h>
#include <ds/intLinkedList.h>
#include <ds/binarySearchTree.h>

#include <lib/libQrcodegen.h>


/**
 * 		Example functions
 * 		you can lean using modules by them
 * 		almost all useful functions of modules is here!
 */
void ptrsEx()
{
	// using bubbleSort method for arrays
	int arr[9] = {1,2,0,10,3,-4,-2,0,100};
	bubbleSort(arr,9);
	printIntArr(arr,9);
	sprintIntArr("cert = ", NULL, 0); printf("\n");
	// using displayBits method
	unsigned n;
	scanf("%u", &n);
	displayBits(n);
}


void intLinkedListEx()
{   // how to use intLinkedList without sorting functions
	illNode* nodePtr = initIntLinkedList();
	for(int i=0; i<1000; i++)
		illAdd(nodePtr, i);
	for(int i=0; i<901; i++)
		illRmTop(nodePtr);
		
	illRmAtIndex(nodePtr,5);
	illRmAtIndex(nodePtr,5000);

	illPrint(nodePtr);
	printf( "%d,%d,  length=%d\n",
		    illContains(nodePtr,1151),
			illContains(nodePtr,66),
			illLenght(nodePtr) );
	illFree(nodePtr);
}


void intLinkedList_sortEx()
{   // how to use sorting functions in intLinkedList module
	illNode* nodePtr = initIntLinkedList();
	for(int i=0; i<50; i++)
		illAdd(nodePtr, i);
				
	illPrint(nodePtr);
	illBubbleSort(nodePtr);
	illPrint(nodePtr);
	illFree(nodePtr);
}


void mmathEx()
{   // how to use mmath module
	printf("a=378, b=1386 => GCD=%d , LCM=%d\n", findGCD(378,1386), mlcm(378,1386));
	printf("fibo(20)=%d", fibo(7));
}


void hashEx()
{
	for( int i=0; i<=20; i++ ){
		printf("PJWhash(%i)=%d , ", i, PJWhash(i));
	if( i%5 == 0 )
		printf("\n");
	}
}


void binarySearchTreeEx()
{
	bstNode* myBST = initBSTree(5);
	printf("adding nodes to bst: ");
	for(int i=0; i<30; i++){
		printf("%d, ", (5*i+13)%19+1);
		bstAdd(myBST,  (5*i+13)%19+1);
	}
	printf("\n");
	bstPrint(myBST);
	printf("address of 5,12 and existance of -5 are: %d, %d, %d\n", 
		bstSearchByValue(myBST,5), bstSearchByValue(myBST,12), bstIsExist(myBST, -5));

	printf("min=%d , max=%d\n", bstMIN(myBST)->data, bstMAX(myBST)->data);
}


void intStackEx()
{
	illNode* head = initIntStack();
}


/**
 * 		int main method
 */
int main( int argc, char **argv )
{
	if( argc == 1 )
		printf("it works :) \n");
	if( argc == 2 && strcmp(argv[1],"ptrs")==0 )  /*** Example of using ptrs modlue ***/
		ptrsEx();

	if( argc == 2 && strcmp(argv[1],"intLinkedList")==0 )  /*** Example of using int linked list ***/
		intLinkedListEx();

	if( argc == 3 && strcmp(argv[1],"intLinkedList")==0 
				  && strcmp(argv[2],"sort")==0 )  /*** Example of using int linked list + sorting algorithms ***/
		intLinkedList_sortEx();

	if( argc == 2 && strcmp(argv[1],"mmath")==0 )  /*** Example of using mmath ***/
		mmathEx();
	
	if( argc == 2 && strcmp(argv[1],"hash")==0 )  /*** Example of using hash ***/
		hashEx();
	
	if( argc == 2 && strcmp(argv[1],"binarySearchTree")==0)
		binarySearchTreeEx();
	
	if( argc == 2 && strcmp(argv[1],"intStack")==0)
		intStackEx();
	return 0;
}