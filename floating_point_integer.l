/*Definition Section*/
%{
#include<stdio.h>
%}
/*Rule Section*/
%%
[0-9]+"."[0-9]+ {ECHO; printf("\nFloating Point Number\n");}  
[0-9]+ {ECHO; printf("\nInteger Number\n");}      
%%
/*call the yywrap function*/
int yywrap()    
{return 1;}
/*Auxiliary function*/
/*Driver function*/
int main(void)
{
/*call the yylex function.*/
yylex();
return 0;
}