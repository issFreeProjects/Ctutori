/*
 * main.c file 
 * created at 24/7/2021
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <utils/hash.h>
#include <utils/sort.h>
#include <utils/ptrs.h>
#include <utils/mmath.h>
#include <utils/pprint.h>

#include <ds/intStack.h>
#include <ds/intLinkedList.h>
#include <ds/binarySearchTree.h>

#include <lib/libattopng.h>
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
	uint8_t* data = qrcodeST1();  // make data of smoke test qr output
	printQr( data );
	free(data);  // data was allocated
}


void code128GS1Ex()
{
	size_t barcode_length;
	char* barcode_data = code128ST( &barcode_length );  // barcode data from smoke test function - hello world -
	printCode128( barcode_length, barcode_data );
	free(barcode_data);  // data was allocated
}


void mkPngBarcodeEx()
{
	size_t barcode_length;
	char* barcode_data = code128ST( &barcode_length );  // barcode data from smoke test function!
	unsigned int BAR_LEN = 10;  // width of each bar in output png
	unsigned int H = BAR_LEN*50;  // height of png
	unsigned int W = barcode_length*BAR_LEN;	// width of png

	// inti png library (libattopng)
    libattopng_t *png = libattopng_new(W, H, PNG_PALETTE);
    uint32_t palette[] = { RGB_WHITE, RGB_BLACK };  // make palette with two colors
    libattopng_set_palette(png, palette, 2);  // set palette
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++)
            libattopng_set_pixel( png, x, y,  barcode_data[x/BAR_LEN] );
    }

    libattopng_save(png, "/tmp/barcode.png");
	free(barcode_data);
    libattopng_destroy(png);
}


void mkPngQrEx()
{
	size_t SQ_LEN = 25;  // width of each bar in output png
	size_t BOARDER = SQ_LEN*6;
	int sideLen;
	bool** qrdata = qrcodeST( &sideLen );

	unsigned int W = sideLen*SQ_LEN;
	unsigned int H = W;

	// inti library
    libattopng_t *png = libattopng_new(W+BOARDER, H+BOARDER, PNG_PALETTE);
    uint32_t palette[] = { RGB_WHITE, RGB_BLACK };
    libattopng_set_palette(png, palette, 2);
    
	for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++){
            libattopng_set_pixel(png, x+BOARDER/2, y+BOARDER/2, qrdata[x/SQ_LEN][y/SQ_LEN] );
		}
    }

	for(int i = 0; i < sideLen; i++)
		free(qrdata[i]);
	free(qrdata);
    libattopng_save(png, "/tmp/qrcode.png");
    libattopng_destroy(png);
}



void help()
{
	printf(
		"** usage:  main [head command] <opthions...>\n"
		"** use the following `head` commands and thair options:\n\n"
		"o   [ptrs]: runs ptrs usage Example - has no option\n"
		"o   [intLinkedList]: runs int linked list usage Example, options:\n"
		"                   - < >   : run basic Example,\n"
		"                   - <sort>: also runs  sorting algorithms Example\n"
		"o   [mmath]: runs mmath usage Example - has no option\n"
		"o   [hash]: runs hash usage Example - has no option\n"
		"o   [binarySearchTree]: runs binary Search Tree (bst) usage Example - has no option\n"
		"o   [intStack]: runs int stack (ist) usage Example - has no option\n"
		"o   [barcode] <option>: runs barcode Example, option is required, options:\n"
		"            - <qr>        : makes Qr Barcode\n"
		"            - <code128GS1>: makes normal Barcode - uses GS1 algorithm\n"
		"o   [png] <option>: make simple png file at /tmp, option required. options:\n"
		"        - <qr>      : makes hello world qr barcode png\n"
		"        - <barcode> : makes code128 barcode png"
	);
}


/**
 * 		int main method
 */
int main( int argc, char **argv )
{
	if( argc == 1 )
		printf("it works :) \n");
	else if( argc == 2 && strcmp(argv[1],"help")==0 )  /*** print help message ***/
		help();
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
		else if( strcmp(argv[2],"code128GS1")==0 )
			code128GS1Ex();
		else help();
		// todo: using ofsome other barcode lib ex.
	}
	else if( argc == 3 && strcmp(argv[1],"png")==0){
		if( strcmp(argv[2],"barcode")==0 )
			mkPngBarcodeEx();
		else if ( strcmp(argv[2],"qr")==0 )
			mkPngQrEx();
		else help();
	}
	else help();
	return 0;
}
