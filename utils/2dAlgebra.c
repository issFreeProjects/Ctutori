#include <stdbool.h>
#include "2dAlgebra.h"



TYPE2 det2d( TYPE* arr )
{
	return arr[0]*arr[3]-arr[2]*arr[1];
}


void m2d( TYPE3* arr, TYPE3 coff, TYPE3* result , unsigned int len)
{
	for(int i=0; i<len; i++)
		result[i] = coff * (arr[i]*1.0);
}


void inv2d( TYPE* arr, TYPE3* result )
{
	TYPE3 det = det2d(arr);
	if( det == 0 )
		return;
	result[0] = 1.0*arr[3];    result[3] = 1.0*arr[0];
	result[2] = -1*(1.0*arr[2]); result[1] = -1*(1.0*arr[1]);
    m2d( result, 1/det, result, 4);  // arr is matrix => len=4	
}


void prod2d( TYPE2* arr, TYPE3* matrix, TYPE3* result )
{
	result[0] = (1.0*arr[0])*matrix[0] + (1.0*arr[1])*matrix[1];
	result[1] = (1.0*arr[0])*matrix[2] + (1.0*arr[1])*matrix[3];
}


TYPE2 dotprod2d( TYPE* arr1, TYPE* arr2 )
{
	return arr1[0]*arr2[0] + arr1[1]*arr2[1];
}


bool isOrth2d( TYPE* arr1, TYPE* arr2 )
{
	return (dotprod2d(arr1,arr2) == 0) ? 1 : 0;
}


void p2d( TYPE* arr1, TYPE* arr2, TYPE* result )
{
	result[0] = arr1[0] + arr2[0];
	result[1] = arr1[1] + arr2[1];
}


void linearComp( TYPE* arr1, TYPE coff1, TYPE* arr2, TYPE coff2, TYPE* result )
{
	result[0] = arr1[0]*coff1 + arr2[0]*coff2;
	result[1] = arr1[1]*coff1 + arr2[1]*coff2;
}