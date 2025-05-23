
#ifndef LEXERDEF_H
#define LEXERDEF_H
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// rename TK to TK
enum TK
{
    TK_ERROR,
    TK_ID,
    TK_NUM,
    TK_END,
    TK_WHILE,
    TK_UNION,
    TK_ENDUNION,
    TK_DEFINETYPE,
    TK_AS,
    TK_TYPE,
    TK_MAIN,
    TK_ASSIGNOP,
    TK_COMMENT,
    TK_FIELDID,
    TK_GLOBAL,
    TK_PARAMETER,
    TK_MUL,
    TK_DIV,
    TK_CALL,
    TK_RECORD,
    TK_GT,
    TK_GE,
    TK_LIST,
    TK_SQL,
    TK_SQR,
    TK_INPUT,
    TK_ENDIF,
    TK_READ,
    TK_WRITE,
    TK_RETURN,
    TK_OUTPUT,
    TK_ENDRECORD,
    TK_ELSE,
    TK_AND,
    TK_OR,
    TK_NOT,
    TK_LT,
    TK_LE,
    TK_EQ,
    TK_INT,
    TK_REAL,
    TK_COMMA,
    TK_SEM,
    TK_COLON,
    TK_DOT,
    TK_ENDWHILE,
    TK_OP,
    TK_CL,
    TK_IF,
    TK_THEN,
    TK_PLUS,
    TK_MINUS,
    TK_RNUM,
    TK_FUNID,
    TK_RUID,
    TK_WITH,
    TK_PARAMETERS,
    TK_NE
};

typedef enum TK TK;

struct returnTK
{
    TK t;
    char *lexeme;
    int line;
    int flag;
};
typedef struct returnTK returnTK;
#endif