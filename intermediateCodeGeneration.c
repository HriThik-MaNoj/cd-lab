#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int i = 0, j = 0, no = 0, tmpch = 90;
char str[100], left[15], right[15];

void findopr();
void explore();
void fleft(int);
void fright(int);

struct exp {
    int pos;
    char op;
} k[15];

int main() {
    printf("\t\tINTERMEDIATE CODE GENERATION\n\n");
    printf("Enter the Expression: ");
    scanf("%s", str);
    printf("The intermediate code:\n");
    findopr();
    explore();
    return 0;
}

void findopr() {
    // First handle high precedence operators (/, *)
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '/') {
            k[j].pos = i;
            k[j++].op = '/';
        }
    }
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '*') {
            k[j].pos = i;
            k[j++].op = '*';
        }
    }
    // Then handle low precedence operators (+, -)
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '+') {
            k[j].pos = i;
            k[j++].op = '+';
        }
    }
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-') {
            k[j].pos = i;
            k[j++].op = '-';
        }
    }
}

void explore() {
    i = 0;
    while (i < j) {
        fleft(k[i].pos);
        fright(k[i].pos);
        str[k[i].pos] = tmpch--; // Replace operator with a temporary variable
        printf("\t%c := %s %c %s\n", str[k[i].pos], left, k[i].op, right);
        i++;
    }

    fright(-1);
    if (no == 0) {
        fleft(strlen(str));
        printf("\t%s := %s\n", right, left);
        exit(0);
    }

    printf("\t%s := %c\n", right, str[k[--i].pos]);
}

void fleft(int x) {
    int w = 0, flag = 0;
    x--;
    while (x != -1 && str[x] != '+' && str[x] != '*' && str[x] != '=' && str[x] != '\0' &&
           str[x] != '-' && str[x] != '/' && str[x] != ':') {
        if (str[x] != '$' && flag == 0) {
            left[w++] = str[x];
            left[w] = '\0';
            str[x] = '$';
            flag = 1;
        }
        x--;
    }
}

void fright(int x) {
    int w = 0, flag = 0;
    x++;
    while (x != -1 && str[x] != '+' && str[x] != '*' && str[x] != '\0' && str[x] != '=' &&
           str[x] != ':' && str[x] != '-' && str[x] != '/') {
        if (str[x] != '$' && flag == 0) {
            right[w++] = str[x];
            right[w] = '\0';
            str[x] = '$';
            flag = 1;
        }
        x++;
    }
}
