#include <hash.h>

int PJWhash( int h ){
    // The top 4 bits of h are all zero
    h = (h << 4);                   // shift h 4 bits left, add in ki
    int g = h & 0xf0000000;         // get the top 4 bits of h
    if (g != 0)                     // if the top 4 bits aren't zero,
        h = h ^ (g >> 24);          //   move them to the low end of h
        h = h ^ g;
    // The top 4 bits of h are again all zero
    return h;
}