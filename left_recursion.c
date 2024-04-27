#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define MAX_LEN 100 
 
void eliminateLeftRecursion(char nonTerminal, char **productions, int numProductions); 
 
int main() { 
    char nonTerminal; 
    int numProductions; 
 
    printf("Enter the non-terminal: "); 
    scanf(" %c", &nonTerminal); 
 
    printf("Enter the number of productions: "); 
    scanf("%d", &numProductions); 
 
    char *productions[MAX_LEN]; 
 
    printf("Enter the productions (one per line):\n"); 
    for (int i = 0; i < numProductions; ++i) { 
        productions[i] = malloc(MAX_LEN * sizeof(char)); 
        scanf(" %s", productions[i]); 
    } 
 
    eliminateLeftRecursion(nonTerminal, productions, numProductions); 
 
    // Free allocated memory 
    for (int i = 0; i < numProductions; ++i) { 
        free(productions[i]); 
    } 
 
    return 0; 
} 
 
void eliminateLeftRecursion(char nonTerminal, char **productions, int numProductions) { 
    printf("Original Grammar:\n"); 
    for (int i = 0; i < numProductions; ++i) { 
        printf("%c -> %s\n", nonTerminal, productions[i]); 
    } 
 
    printf("\nAfter Eliminating Left Recursion:\n"); 
 
    // Create new non-terminal for left recursive productions 
    char newNonTerminal = nonTerminal + 1; 
 
    // Print non-left recursive productions 
    for (int i = 0; i < numProductions; ++i) { 
        if (productions[i][0] != nonTerminal) { 
            printf("%c -> %s%c'\n", nonTerminal, productions[i], newNonTerminal); 
        } 
    } 
 
    // Print new productions for left recursion 
    for (int i = 0; i < numProductions; ++i) { 
        if (productions[i][0] == nonTerminal) { 
            printf("%c' -> %s%c'\n", newNonTerminal, productions[i] + 1, newNonTerminal); 
        } 
    } 
 
    // Add epsilon production for the new non-terminal 
    printf("%c' -> ε\n", newNonTerminal); 
}