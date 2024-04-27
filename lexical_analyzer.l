%{
int COMMENT = 0;
%}

identifier [a-zA-Z][a-zA-Z0-9]*

%x COMMENT_MODE

%%

<INITIAL>#.* {
    printf("\n%s is a Preprocessor Directive", yytext);
}

<INITIAL>int|float|main|if|else|printf|scanf|for|char|getch|while {
    printf("\n%s is a Keyword", yytext);
}

<INITIAL>"/*" {
    BEGIN(COMMENT_MODE);
}

<COMMENT_MODE>"*/" {
    BEGIN(INITIAL);
}

<INITIAL>{identifier}\( {
    printf("\nFunction:\t%s", yytext);
}

<INITIAL>\{ {
    printf("\nBlock Begins");
}

<INITIAL>\} {
    printf("\nBlock Ends");
}

<INITIAL>{identifier}(\[[0-9]*\])? {
    printf("\n%s is an Identifier", yytext);
}

<INITIAL>\"(\\.|[^"\\])*\" {
    printf("\n%s is a String", yytext);
}

<INITIAL>[0-9]+ {
    printf("\n%s is a Number", yytext);
}

<INITIAL>\)(\;)? {
    ECHO;
    printf("\n");
}

<INITIAL>= {
    printf("\n%s is an Assignment Operator", yytext);
}

<INITIAL><=|>=|<|== {
    printf("\n%s is a Relational Operator", yytext);
}

.|\n

%%

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file;
        file = fopen(argv[1], "r");
        if (!file) {
            printf("\nCould not open the file: %s", argv[1]);
            exit(1);
        }
        yyin = file;
    }

    yylex();

    printf("\n\n");
    return 0;
}

int yywrap() {
    return 1;
}
