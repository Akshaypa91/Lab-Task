#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int get_operand(int *op) {
    int c;
    while (isspace(c = getchar())) ;
    if (!isdigit(c)) return 0;
    *op = c - '0';
    while (isdigit(c = getchar())) {
        *op = *op * 10 + (c - '0');
    }
    if (c != EOF) ungetc(c, stdin);
    return 1;
}

int get_operator(char *opr) {
    int c;
    while (isspace(c = getchar())) ;
    if (c == EOF) return 0;
    *opr = c;
    return 1;
}

int calculate(int op1, char opr, int op2) {
    switch (opr) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': 
            if (op2 != 0) return op1 / op2;
            else {
                printf("Error: Division by zero.\n");
                exit(1);
            }
        case '%': return op1 % op2;
        case '<': return op1 << op2;
        case '>': return op1 >> op2;
        case '|': return op1 | op2;
        case '&': return op1 & op2;
        default: 
            printf("bad opr1\n");
            exit(1);
    }
}

int main() {
    int op1, op2;
    char opr;

    while (1) {
        if (!get_operand(&op1)) {
            printf("bad op1\n");
            exit(1);
        }
        if (!get_operator(&opr)) {
            printf("bad opr1\n");
            exit(1);
        }
        if (!get_operand(&op2)) {
            printf("bad op2\n");
            exit(1);
        }

        char opr2;
        if (get_operator(&opr2)) {
            if (opr2 != opr) {
                printf("opr1 %c != opr2 %c\n", opr, opr2);
                exit(1);
            }
        }

        printf("%d %c %d = %d\n", op1, opr, op2, calculate(op1, opr, op2));
    }

    return 0;
}
