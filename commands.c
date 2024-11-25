#include <stdio.h>
#include <string.h>

void parse_command(char *command);

void parse_command(char *command) {
    if (strncmp(command, "USE", 3) == 0) {
        printf("Comando USE\n");
    } else if (strcmp(command, "LIST") == 0) {
        printf("Comando LIST\n");
    } else if (strncmp(command, "APPEND", 6) == 0) {
        printf("Comando APPEND\n");
    } else if (strncmp(command, "REPLACE", 7) == 0) {
        printf("Comando REPLACE\n");
    } else {
        printf("Comando não reconhecido\n");
    }
}

int main() {
    char command[50];
    printf("Digite um comando DBASE: ");
    fgets(command, sizeof(command), stdin);
    command[strcspn(command, "\n")] = '\0'; // Remove newline
    parse_command(command);
    return 0;
}