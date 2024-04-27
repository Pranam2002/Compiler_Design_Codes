#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
#define MAX_LEN 100 
 
void leftFactoring(char nonTerminal, char **productions, int numProductions); 
 
int main() { 
    char nonTerminal; 
    int numProductions; 
 
    printf("Enter the non-terminal character: "); 
    scanf(" %c", &nonTerminal); 
 
    printf("Enter the number of productions: "); 
    scanf("%d", &numProductions); 
 
    char *productions[MAX_LEN]; 
    printf("Enter the productions:\n"); 
    for (int i = 0; i < numProductions; ++i) { 
        productions[i] = (char *) malloc(MAX_LEN * sizeof(char)); 
        scanf("%s", productions[i]); 
    } 
 
    leftFactoring(nonTerminal, productions, numProductions); 
 
    // Free allocated memory 
    for (int i = 0; i < numProductions; ++i) { 
        free(productions[i]); 
    } 
 
    return 0; 
} 
 
void leftFactoring(char nonTerminal, char **productions, int numProductions) { 
    printf("Original Grammar:\n"); 
    for (int i = 0; i < numProductions; ++i) { 
        printf("%c -> %s\n", nonTerminal, productions[i]); 
    } 
 
    printf("\nAfter Left Factoring:\n"); 
 
    int commonPrefixLength = 0; 
 
    // Find the common prefix length 
    while (productions[0][commonPrefixLength] == productions[1][commonPrefixLength] && 
           productions[0][commonPrefixLength] == productions[2][commonPrefixLength]) { 
        commonPrefixLength++; 
    } 
 
    // If there is a common prefix 
    if (commonPrefixLength > 0) { 
        printf("%c -> %.*s%c'\n", nonTerminal, commonPrefixLength, productions[0], nonTerminal); 
 
        // Print remaining suffixes with new non-terminal 
        for (int i = 0; i < numProductions; ++i) { 
            printf("%c' -> %s\n", nonTerminal, productions[i] + commonPrefixLength); 
        } 
    } else { 
        // No common prefix 
        for (int i = 0; i < numProductions; ++i) { 
            printf("%c -> %s\n", nonTerminal, productions[i]); 
        } 
    } 
}