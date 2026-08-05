%{
#include <stdio.h>

int keywordCount=0;
int identifierCount=0;
int numberCount=0;
int operatorCount=0;
int delimiterCount=0;
int commentCount=0;
int totalTokens=0;
%}

%%

"//".* {
    commentCount++;
    totalTokens++;
    printf("COMMENT: %s\n", yytext);
}

"int"|"float"|"char"|"double"|"void"|"if"|"else"|"while"|"for"|"return"|"do"|"break"|"continue"|"switch"|"case"|"default" {
    keywordCount++;
    totalTokens++;
    printf("KEYWORD: %s\n", yytext);
}

[a-zA-Z_][a-zA-Z0-9_]* {
    identifierCount++;
    totalTokens++;
    printf("IDENTIFIER: %s\n", yytext);
}

[0-9]+ {
    numberCount++;
    totalTokens++;
    printf("NUMBER: %s\n", yytext);
}

"=="|"!="|"<="|">="|"="|"+"|"-"|"*"|"/"|"<"|">" {
    operatorCount++;
    totalTokens++;
    printf("OPERATOR: %s\n", yytext);
}

"{"|"}"|"("|")"|";"|","|"["|"]" {
    delimiterCount++;
    totalTokens++;
    printf("DELIMITER: %s\n", yytext);
}

[ \t\n]+ ;

. {
    printf("UNKNOWN: %s\n", yytext);
}

%%

int main()
{
    yylex();

    printf("\n===== TOKEN SUMMARY =====\n");
    printf("Keywords    : %d\n", keywordCount);
    printf("Identifiers : %d\n", identifierCount);
    printf("Numbers     : %d\n", numberCount);
    printf("Operators   : %d\n", operatorCount);
    printf("Delimiters  : %d\n", delimiterCount);
    printf("Comments    : %d\n", commentCount);
    printf("Total       : %d\n", totalTokens);

    return 0;
}

int yywrap()
{
    return 1;
}