%{
#include<stdio.h>
int flag=0;
%}
%%
[a-z . 0-9]+@[a-z]+".com"|".in" {flag=1;}
%%
int main()
{
yyin = fopen("input.txt","r");
yylex();
if(flag==1)
printf("Valid Email Id\n");
else
printf("Not Valid Email Id\n");
}
int yywrap()
{
return 1;
}