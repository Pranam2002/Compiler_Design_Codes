#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
 
int isKeyword(char buffer[]) { 
    char keywords[32][10] = {"auto","break","case","char","const","continue","default", 
    "do","double","else","enum","extern","float","for","goto", 
    "if","int","long","register","return","short","signed", 
    "sizeof","static","struct","switch","typedef","union", 
    "unsigned","void","volatile","while"}; 
    int i, flag = 0; 
    for(i = 0; i < 32; ++i) { 
        if(strcmp(keywords[i], buffer) == 0) { 
            flag = 1; 
            break; 
        } 
    } 
    return flag; 
} 
 
int isDelimiter(char ch) { 
    return (ch == ';'); 
} 
 
int isSpecialCharacter(char ch) { 
    return (ch == '/' || ch == '|' || ch == '{' || ch == '}' || ch == ','); 
} 
 
int isOperator(char ch) { 
    char operators[] = "+-*/%="; 
    for (int i = 0; i < 6; ++i) { 
        if (ch == operators[i]) 
            return 1; 
    } 
    return 0; 
} 
 
int main() { 
    char ch, buffer[15], delimiters[] = ";", special_characters[]="/|{},"; 
    FILE *fp; 
    int i, j = 0; 
    fp = fopen("input1.txt","r"); 
    if(fp == NULL) { 
        printf("error while opening the file\n"); 
        exit(0); 
    } 
 
    printf("Identifiers: "); 
    while((ch = fgetc(fp)) != EOF) { 
        if(isalpha(ch) || ch == '_') {  // Include underscore as a valid identifier character 
            buffer[j++] = ch; 
        } else if ((ch == ' ' || ch == '\n' || isDelimiter(ch) || isSpecialCharacter(ch) || isOperator(ch)) && (j != 
0)) { 
            buffer[j] = '\0'; 
            j = 0; 
 
            if(isKeyword(buffer) == 1) 
                printf("%s, ", buffer); 
            else 
                printf("%s, ", buffer); 
        } 
    } 
 
    rewind(fp); // Reset file pointer to the beginning 
 
    printf("\nSpecial Characters: "); 
    while((ch = fgetc(fp)) != EOF) { 
        for(i = 0; i < 5; ++i) { 
            if(isSpecialCharacter(ch)) 
                printf("%c, ", ch); 
        } 
    } 
 
    rewind(fp); // Reset file pointer to the beginning 
 
    printf("\nDelimiters: "); 
    while((ch = fgetc(fp)) != EOF) { 
        for(i = 0; i < 1; ++i) { 
            if(isDelimiter(ch)) 
                printf("%c, ", ch); 
        } 
    } 
 
    rewind(fp); // Reset file pointer to the beginning 
 
    printf("\nOperators: "); 
    while((ch = fgetc(fp)) != EOF) { 
        if (isOperator(ch)) 
            printf("%c, ", ch); 
    } 
 
    fclose(fp); 
    return 0; 
}