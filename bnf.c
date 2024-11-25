#include <stdio.h>
#include <stdlib.h>

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
    ungetc(operator, stdin); // retorna o operador não usado
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
    if (ch == '(') {
        value = parse_expression();
        getchar(); // consome o ')'
    } else {
        ungetc(ch, stdin);
        scanf("%d", &value);
    }
    return value;
}

int main() {
    printf("Resultado: %d\n", parse_expression());
    return 0;
}
