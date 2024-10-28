#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int c, i = 0, j = 0;
char a[30], ac[20], act[20], stk[50];

void check() {
    strcpy(ac, "REDUCE TO E->");

    for (int z = 0; z < c; z++) {
        if (stk[z] == 'a') {
            printf("%sa", ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';
            printf("\n$%s\t%s$\t", stk, a);
            break;
        }
    }

    for (int z = 0; z < c - 2; z++) {
        if (stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'E') {
            printf("%sE+E", ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t", stk, a);
            c -= 2;
            i -= 2;
            break;
        } else if (stk[z] == 'E' && stk[z + 1] == '-' && stk[z + 2] == 'E') {
            printf("%sE-E", ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t", stk, a);
            c -= 2;
            i -= 2;
            break;
        } else if (stk[z] == 'E' && stk[z + 1] == '*' && stk[z + 2] == 'E') {
            printf("%sE*E", ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t", stk, a);
            c -= 2;
            i -= 2;
            break;
        } else if (stk[z] == 'E' && stk[z + 1] == '/' && stk[z + 2] == 'E') {
            printf("%sE/E", ac);
            stk[z] = 'E';
            stk[z + 1] = '\0';
            stk[z + 2] = '\0';
            printf("\n$%s\t%s$\t", stk, a);
            c -= 2;
            i -= 2;
            break;
        }
    }
}

int main() {
    printf("The grammar is \nE->E+E\nE->E-E\nE->E/E\nE->E*E\nE->a");
    printf("\nEnter the code\n");
    scanf("%s", a);
    c = strlen(a);
    strcpy(act, "SHIFT");
    printf("Stack\tinput\tAction\n");
    printf("\n$\t%s$\t", a);

    for (i = 0; j < c; i++, j++) {
        printf("%s", act);
        stk[i] = a[j];
        stk[i + 1] = '\0';
        a[j] = ' ';
        printf("\n$%s\t%s$\t", stk, a);
        check();
    }
    check();

    if (stk[0] == 'E' && stk[1] == '\0')
        printf("Accepted");
    else
        printf("Rejected");

    return 0;
}

