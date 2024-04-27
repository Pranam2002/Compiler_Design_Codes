#include <stdio.h> 
#include <string.h> 
#define MAX_LINES 100 
#define MAX_LINE_LENGTH 256 
int main() { 
    char code[MAX_LINES][MAX_LINE_LENGTH]; 
    int multiLineComment = 0; 
    int lineCount = 0; 
    printf("Enter your C++ code (type 'END' to finish):\n"); 
    while (1) { 
        fgets(code[lineCount], sizeof(code[lineCount]), stdin); 
        if (strcmp(code[lineCount], "END\n") == 0) { 
            break; 
        } 
        lineCount++; 
    } 
    for (int i = 0; i < lineCount; i++) { 
        if (strstr(code[i], "//")) { 
            printf("Single-line comment found on line %d\n", i + 1); 
        } 
        if (strstr(code[i], "/*")) { 
            multiLineComment = 1; 
        } 
        if (multiLineComment && strstr(code[i], "*/")) { 
            printf("Multi-line comment found ending on line %d\n", i +1); 
            multiLineComment = 0; 
        } 
    } 
    return 0; 
} 