/*
 * main.c file 
 * only include and use other modules
 * created at 24/7/2021
 *
 * */

#include <stdio.h>
#include <string.h>
#include <utils/ptrs.h>
#include <utils/pprint.h>
#include <utils/intLinkedList.h>
#include <utils/mmath.h>

int main( int argc, char **argv )
{
	if( argc == 1 )
		printf("it works :) \n");
	if( argc > 1 )
	{
		if(strcmp(argv[1],"ptrs")==0){  /*** Example of using pprint modlue ***/
				int arr[9] = {1,2,0,10,3,-4,-2,0,100};
				bubbleSort(arr,9);
				printIntArr(arr,9);

				sprintIntArr("cert = ", NULL, 0); printf("\n");
				printf("chert = {%d}\n",test());

				unsigned n;
				scanf("%u", &n);
				displayBits(n);
		}
		if(strcmp(argv[1],"intLinkedList")==0){  /*** Example of using int linked list ***/
				struct Node* nodePtr = initIntLinkedList();
				for(int i=0; i<1000; i++)
					addNode(nodePtr, i);
		
				for(int i=0; i<901; i++)
					removeFirst(nodePtr);
		
				removeAtIndex(nodePtr,5);
				removeAtIndex(nodePtr,5000);

				printIntLinkedList(nodePtr);
				printf( "%d,%d,  length=%d\n",
					     isContains(nodePtr,1151),
						 isContains(nodePtr,66),
						 getListLen(nodePtr) ); 
		}
		if(strcmp(argv[1],"mmath")==0){  /*** Example of using mmath ***/
			printf("a=378, b=1386 => GCD=%d , LCM=%d\n", findGCD(378,1386), mlcm(378,1386));
			printf("fibo(20)=%d", fibo(7));
		}
	}
	return 10;
}