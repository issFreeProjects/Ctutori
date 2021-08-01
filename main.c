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
		}
		if(strcmp(argv[1],"mmath")==0){  /*** Example of using mmath ***/
			printf("a=378, b=1386 => GCD=%d , LCM=%d\n", findGCD(378,1386), mlcm(378,1386));
			printf("fibo(20)=%d", fibo(7));
		}
	}
	return 10;
}