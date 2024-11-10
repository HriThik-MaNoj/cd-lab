#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define FAILED 0
#define SUCCESS 1

int E(), Edash(), T(), Tdash(), F();
char str[40];
char *cursor;

void main() {
    printf("Enter the string\n");
    scanf("%39s", str);  // Limit input to avoid buffer overflow
    cursor = str;
    puts("\nINPUT\t\t\t\tACTION\n");
    puts("\n----------------------------------------------\n");
   
    if (E() && *cursor == '\0') {
        puts("\n----------------------------------------------\n");
        puts("String is successfully parsed");
    } else {
        puts("\n----------------------------------------------\n");
        puts("String is not successfully parsed");
    }
}

int E() {
    printf("%-30s E->TE'\n", cursor);
    if (T()) {
        if (Edash())
            return SUCCESS;
        else
            return FAILED;
    } else {
        return FAILED;
    }
}

int Edash() {
    if (*cursor == '+') {
        printf("%-30s E'->+TE'\n", cursor);
        cursor++;
        if (T()) {
            if (Edash())
                return SUCCESS;
            else
                return FAILED;
        } else {
            return FAILED;
        }
    } else {
        printf("%-30s E'->$\n", cursor);
        return SUCCESS;
    }
}

int T() {
    printf("%-30s T->FT'\n", cursor);
    if (F()) {
        if (Tdash())
            return SUCCESS;
        else
            return FAILED;
    } else {
        return FAILED;
    }
}

int Tdash() {
    if (*cursor == '*') {
        printf("%-30s T'->*FT'\n", cursor);
        cursor++;
        if (F()) {
            if (Tdash())
                return SUCCESS;
            else
                return FAILED;
        } else {
            return FAILED;
        }
    } else {
        printf("%-30s T'->$\n", cursor);
        return SUCCESS;
    }
}

int F() {
    if (*cursor == '(') {
        printf("%-30s F->(E)\n", cursor);
        cursor++;
        if (E()) {
            if (*cursor == ')') {
                cursor++;
                return SUCCESS;
            } else {
                return FAILED;
            }
        } else {
            return FAILED;
        }
    } else if (isalpha(*cursor)) {
        printf("%-30s F->id\n", cursor);
        while (isalnum(*cursor))
            cursor++;
        return SUCCESS;
    } else {
        return FAILED;
    }
}
