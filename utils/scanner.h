/**
 *      use scanner for reading string from STDIN
 *      length of each chunk equals BUFFER_CHUNK_SIZE-1
 *  
 *      input: "abcdefghijklmno"
 *      memory:
 * 
 *              │ a | b | c | d | e | f | g | h | i |    | j | k | l | m | n | o | \0 | ? | ? |
 *              ───────────────────────────────────    ────────────────────────────────────
 *                              chunk 1                                     chunk2
 */
#define BUFFER_CHUNK_SIZE 11

// returns char array of input and sets length=(input's length)
char* lnext(int* length);
// only returns char array of input
char* next();

// iterates on string characters and run func for each one
void iterate(char* string, void (*func)(char));
// just for testing iterate function
void print_helper(char c);