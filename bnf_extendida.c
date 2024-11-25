#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int parse_expression();
int parse_term();
int parse_factor();

int parse_expression() {
    int value = parse_term();
    char operator;
    while ((operator = getchar()) == '+' || operator == '-') {
        int term = parse_term();
        if (operator == '+')
            value += term;
        else
            value -= term;
    }
    ungetc(operator, stdin);
    return value;
}

int parse_term() {
    int value = parse_factor();
    char operator;
    while ((operator = getchar()) == '*' || operator == '/') {
        int factor = parse_factor();
        if (operator == '*')
            value *= factor;
        else
            value /= factor;
    }
    ungetc(operator, stdin);
    return value;
}

int parse_factor() {
    int value = 0;
    char ch = getchar();
    if (isdigit(ch)) { // valor é um dígito
        ungetc(ch, stdin);
        scanf("%d", &value);
    } else if (ch == '(') {
        value = parse_expression();
        getchar(); // Consome ')'
    }
    return value;
}
