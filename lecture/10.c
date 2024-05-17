/*
sentinel: an item in the list that signals end of list

too hard to make a universal sentinel for all lists

however for strings it is possible to set a sentinel. 
string sentinel: NUL terminator '\0' or 0 char

'hello' = h e l l o \0
*/

// C supports printing strings
printf("%s", 'hello world');

// Hard coded strings are read-only
char* s = "Hello, world";

// Can now write to string
char t[6];
// or
char t[6] = {'H', 'e', 'l', 'l', 'o', '\0'} // Note necessity of sentinel

// allocate string in heap
char* u = (char*)malloc(sizeof(char) * 6);
u[0] = 'H';

/*
There is another region of memory in addition to stack and heap:
RO data segment: stores hard coded data
*/

// strlen is built in but lets implement it
unsigned int strlen(char* s) {
    unsigned int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

// or 

unsigned int strlen(char* s) {
    unsigned int i = 0;
    while (s[i] != 0) { // <----- recall /0 corresponds to the 0 char
        i++;
    }
    return i;
}

// or 

unsigned int strlen(char* s) {
    unsigned int i = 0;
    while (s[i]) { // <----- 0 evals to false
        i++;
    }
    return i;
}

// or 

unsigned int strlen(char* s) {
    unsigned int i = 0;
    while (s[i++]); // need i-1 bc i++ executes even if evals to false
    return i-1;
}

// or 

unsigned int strlen(char* s) {
    char* p = s;
    while (*p) p++; // traveling pointerd
    return p - s;
}

// or

unsigned int strlen(char* s) {
    char* p = s;
    while (*p++); // traveling pointerd
    return p - s - 1;
}

/*
Important distinction

for *x -> 7

*x++ shifts pointer

(*x)++ adds to value ie now *x -> 8
*/

char* emphasize(char* s) {
    char* res = (char*)malloc(sizeof(char) * (strlen(s)) + 1); // <--- need +1 for sentinel
    unsigned int i = 0;
    while(s[i]) {
        if (s[i] == '.') {
            res[i] = '!';
        } else {
            res[i] = s[i];
        }
        i++;
    }
    res[i] = '\n';
    return res
}