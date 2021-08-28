/**
 *      this is implementaion of some simple hash functions
 *      this hash functions, can be used in hash table
 *      data structure or stuff like that.
 *      remember, not all of them are cryptographic hash function
 */


/** Wikipedia:
 *      PJW hash function is a non-cryptographic hash function 
 *      created by Peter J. Weinberger of AT&T Bell Labs.
 *      PJW hash algorithm involves shifting the previous hash and 
 *      adding the current byte followed by moving the high bits
 */
int PJWhash( int h );


/**
 *      SUM2hash is a non-cryptographic hash function
 *      n is length of h in binary,
 *      Ex:    h  = a1 a2 a3 a4 (in binary) => n=4, n/2=2
 *             p1 = a1 a2,  p2 = a3 a4
 *      and for odd n:
 *      Ex:    h  = a1 a2 a3                => n=3, n/2=1
 *             p1 = a1 a2,  p2 = a3
 *      returns p1 + p2 (integer sum)
 */
int SUM2hash( int h );


/**
 *      SUMPOW2hash is a non-cryptographic hash function
 *      runs hash = SUM2hash(hash) as long as hash>SUM2hash
 *      returns hash.
 */
int SUMPOW2hash( int h, int MAX_VALUE );