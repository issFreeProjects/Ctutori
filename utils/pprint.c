#include <pprint.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

int test()
{
    return -1;
}


void printIntArr( int *arr, int size )
{
    sprintIntArr( "", arr, size );
}


void sprintIntArr( char *s, int *arr, int size )
{
    if( size > 0 ){
        printf("%s[", s);
        for( int i=0; i<size-1; i++ )
            printf("%d, ", arr[i]);
        printf("%d]\n", arr[size-1]);
    } if( size == 0 )
        printf( "%s[]", s );
}


/* display bits of an unsigned integer value */
void displayBits( unsigned value )
{
    unsigned c;
    unsigned displayMask = 1 << 31;
    
    for ( c = 1; c <= 32; c++ ) {
        putchar( value & displayMask ? '1' : '0' );
        value <<= 1; /* shift value left by 1 */
        if ( c % 4 == 0 ) { /* output a space after 8 bits */
            putchar( ' ' );
            if( c % 8 == 0 )
                putchar(' ');
        }
    }
    putchar( '\n' );
}