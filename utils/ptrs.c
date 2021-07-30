#include <ptrs.h>


/* sort an array of integers using bubble sort algorithm */
void bubbleSort( int *array, int size )
{
	int pass; /* pass counter */
	int j; /* comparison counter */

	for ( pass = 0; pass < size - 1; pass++ ) {
		for ( j = 0; j < size - 1; j++ ) {
			if ( array[ j ] > array[ j + 1 ] ) {
				//swap( &array[ j ], &array[ j + 1 ] );
				int hold     = array[ j ];
				array[ j ]   = array[ j+1 ];
				array[ j+1 ] = hold;
			}
		}
	}
}


void swap( int *element1Ptr, int *element2Ptr )
{
	int hold = *element1Ptr;
	*element1Ptr = *element2Ptr;
	*element2Ptr = hold;
}
