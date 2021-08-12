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
#include <lib/libBarcode128GS1.h>

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
	illNode* stack_h = initIntStack();	// init stack head
	for( int i=0; i<15; i++ )
		istPush( stack_h, i+1 );
	istPop( stack_h );
	sprintILL( stack_h ,"stack: " );
	printf( "Peek(stack) = %d\n", istPeek(stack_h)->data );
}


void qrcodeEx()
{
	const char *text = "Hello World!";  // text to decode into qr
	enum qrcodegen_Ecc errCorLvl = qrcodegen_Ecc_LOW;  // Error correction level
	 // Make and print the QR Code symbol
    uint8_t qrcode[qrcodegen_BUFFER_LEN_MAX];
    uint8_t tempBuffer[qrcodegen_BUFFER_LEN_MAX];
    bool ok = qrcodegen_encodeText(text, tempBuffer, qrcode, errCorLvl,
    qrcodegen_VERSION_MIN, qrcodegen_VERSION_MAX, qrcodegen_Mask_AUTO, true);
    if (ok)
    	printQr(qrcode);
}


void code128GS1Ex()
{
	const char *str = "hello";
    size_t barcode_length = code128_estimate_len(str);
    char barcode_data[barcode_length];
    barcode_length = code128_encode_gs1(str, barcode_data, barcode_length);
    /* barcode_length is now the actual number of "bars". */
	
	printCode128( barcode_length, barcode_data );
}


void help()
{
	printf(
		" help usage:  main [head command] <opthions...>\n"
		" use following head commands and thair options:\n\n"
		"o   [ptrs]: runs ptrs usage Example - has no option\n"
		"o   [intLinkedList]: runs int linked list usage Example, options:\n"
		"                   - < >   : run basic Example,\n"
		"                   - <sort>: also runs  sorting algorithms Example\n"
		"o   [mmath]: runs mmath usage Example - has no option\n"
		"o   [hash]: runs hash usage Example - has no option\n"
		"o   [binarySearchTree]: runs binary Search Tree (bst) usage Example - has no option\n"
		"o   [intStack]: runs int stack (ist) usage Example - has no option\n"
		"o   [barcode] <option>: option is expected, options:\n"
		"            - <qr>        : makes Qr Barcode\n"
		"            - <code128GS1>: makes normal Barcode - uses GS1 algorithm\n"
	);
}


/**
 * 		int main method
 */
int main( int argc, char **argv )
{
	if( argc == 1 )
		printf("it works :) \n");
	else if( argc == 2 && strcmp(argv[1],"ptrs")==0 )  /*** Example of using ptrs modlue ***/
		ptrsEx();

	else if( argc == 2 && strcmp(argv[1],"intLinkedList")==0 )  /*** Example of using int linked list ***/
		intLinkedListEx();

	else if( argc == 3 && strcmp(argv[1],"intLinkedList")==0 
				  && strcmp(argv[2],"sort")==0 )  /*** Example of using int linked list + sorting algorithms ***/
		intLinkedList_sortEx();

	else if( argc == 2 && strcmp(argv[1],"mmath")==0 )  /*** Example of using mmath ***/
		mmathEx();
	
	else if( argc == 2 && strcmp(argv[1],"hash")==0 )  /*** Example of using hash ***/
		hashEx();
	
	else if( argc == 2 && strcmp(argv[1],"binarySearchTree")==0)
		binarySearchTreeEx();
	
	else if( argc == 2 && strcmp(argv[1],"intStack")==0)
		intStackEx();

	else if( argc == 3 && strcmp(argv[1],"barcode")==0){  /*** Examples of using barcode libraries ***/
		if( strcmp(argv[2],"qr")==0 )            /*** Ex of using libQrcodegen lib            ***/
			qrcodeEx();
		if( strcmp(argv[2],"code128GS1")==0 )
			code128GS1Ex();
		// todo: using ofsome other barcode lib ex.
	}
	else help();
	return 0;
}
