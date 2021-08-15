/*
 *	this is implementation of some 2d linear algebra operations
 *	vector: it's just 2d <numeric> array
 *                      _         _
 *                      │  arr[0] │
 *	arr => Vector = │         │
 *                      │  arr[1] │
 *                      `         `
 *	matrix: it's just 4d <numeric> array
 *                       _                  _
 *                       │  arr[0]   arr[2] │
 *	arr => Matrix =  │                  │
 *                       │  arr[1]   arr[3] │
 *                       `                  `
 **/

// here is some types, set them by following guide
// if you need double vectors and matrixes -> set all TYPE(s) = double.
// if you need unsigned int vectors and matrixes -> set TYPE = unsigned int
//      so you will need integer determinant -> set TYPE2 = int  (determinant is not unsigned when the matrix is unsigned integer)
//      and need double value inverse matrix -> set TYPE3 = double
// if you need int matrix -> set TYPE=int; TYPE2=int; TYPE3=double
#define TYPE  unsigned int
#define TYPE2 int
#define TYPE3 double



// returns determinant value and arr is matrix
TYPE2 det2d( TYPE* arr );

// myltiply all entries in constant coff
// put len=2 for vectors and len=4 for matrixes
void m2d( TYPE3* arr, TYPE3 coff, TYPE3* result , unsigned int len);


// finds reverse of arr matrix
void inv2d( TYPE* arr, TYPE3* result );

// arr=[x y] , matrix=[a c; b d]   =>   result = arr * matrix = [ax+cy, bx+dy]
void prod2d( TYPE2* arr, TYPE3* matrix, TYPE3* result );

// returns dot product, arr1 . arr2 = arr1 * tr(arr2)
TYPE2 dotprod2d( TYPE* arr1, TYPE* arr2 );

// returns dot product, arr1 . arr2 = arr1 * tr(arr2)
TYPE2 dotprod2d( TYPE* arr1, TYPE* arr2 );

// returns dot product, arr1 . arr2 = arr1 * tr(arr2)
TYPE2 dotprod2d( TYPE* arr1, TYPE* arr2 );

// result is: coff1 * arr1 + coff2 * arr2
void linearComp( TYPE* arr1, TYPE coff1, TYPE* arr2, TYPE coff2, TYPE* result );