#include <hash.h>

int PJWhash( int h ){
    // The top 4 bits of h are all zero
    h = (h << 4);                   // shift h 4 bits left, add in ki
    int g = h & 0xf0000000;         // get the top 4 bits of h
    if (g != 0)                     // if the top 4 bits aren't zero,
        h = h ^ (g >> 24);          //   move them to the low end of h
        h = h ^ g;
    // The top 4 bits of h are again all zero
    return ( h & 127 );
}


int SUM2hash( int h ){
    unsigned int n = 0;
    for(int h2=h; h2!=0; h2=h2/2)
        n++;
    n = n/2;
    int p1=h>>n, p2=((h>>n)<<n)^h;
    return p1 + p2;
}


int SUMPOW2hash( int h, int MAX_VALUE )
{
    int hash = SUM2hash(h);
    while( hash > MAX_VALUE )
        hash = SUM2hash(hash);
    return hash;
}