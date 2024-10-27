#include<stdio.h>
#include<ctype.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int i, j, m, n;
char a[20][20], f[10];

void first(char c);
void follow(char c);

void main() {
    int i;
    char ch, c;

    printf("Enter the number of productions\n");
    scanf("%d", &n);

    printf("ENter the productions\n");
    for (i = 0; i < n; i++)
        scanf("%s%c", a[i], &ch);

    printf("ENter the elements whose first and follow is to be found\n");
    scanf("%c", &c);

    first(c);
    printf("The first of %c ={", c);
    for (i = 0; i < m; i++)
        printf("%c", f[i]);
    printf("}\n");

    strcpy(f, "");
    m = 0;

    follow(c);
    printf("The follow of %c ={", c);
    for (i = 0; i < m; i++)
        printf("%c", f[i]);
    printf("}\n");
}

void first(char c) {
    int k;

    if (!isupper(c))
        f[m++] = c;

    for (k = 0; k < n; k++) {
        if (a[k][0] == c) {
            if (a[k][2] == '$')
                follow(a[k][0]);
            else if (islower(a[k][2]))
                f[m++] = a[k][2];
            else
                first(a[k][2]);
        }
    }
}

void follow(char c) {
    if (a[0][0] == c)
        f[m++] = '$';

    for (i = 0; i < n; i++) {
        for (j = 2; j < strlen(a[i]); j++) {
            if (a[i][j] == c) {
                if (a[i][j + 1] != '\0')
                    first(a[i][j + 1]);

                if (a[i][j + 1] == '\0' && c != a[i][0])
                    follow(a[i][0]);
            }
        }
    }
}
