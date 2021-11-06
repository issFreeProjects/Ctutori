#include "scanner.h"
#include <stdio.h>
#include <stdlib.h>

char* lnext(int* length){
    char c = 0;
    int cursor = 0, len = BUFFER_CHUNK_SIZE;
    char* buffer = (char*)malloc(len*sizeof(char));
    while( c!='\n' && c!='\r' && c!=-1 ){
        c = getchar();
        buffer[cursor] = c;
        cursor++;
        if( cursor > len-1 ){
            len+=BUFFER_CHUNK_SIZE;
            buffer = (char*)realloc(buffer,len);
        }
    }
    buffer[cursor+1]=0;
    if(length!=NULL)
        *length = len;
    return buffer;
}

char* next(){
    return lnext(NULL);
}


void iterate(char* string, void (*func)(char)){
    for(char* i=string; *i!=0; i++)
        (*func)(*i);
}

void print_helper(char c){
    if(c!='\n')
        printf("(%c)", c);
    else printf("\n");
}