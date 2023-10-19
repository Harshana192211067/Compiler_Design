#include <stdio.h>
#include <string.h>
int main() {
    char production[100];
    int i;
    printf("Enter a production (e.g., S->Aa|Bb): ");
    gets(production);
    char nonTerminal = production[0];
    char leadingSet[10];
    leadingSet[0] = '\0';
    char trailingSet[10];
    trailingSet[0] = '\0';
    // Calculate leading set
    int leadingFound = 0;
    for (i = 3; production[i] != '\0' && production[i] != '|'; i++) {
        if (isalpha(production[i])) {
            leadingSet[0] = production[i];
            leadingSet[1] = '\0';
            leadingFound = 1;
            break;
        }
    }

    // Calculate trailing set
    int len = strlen(production);
    int trailingFound = 0;
    for (i = len - 1; i >= 3; i--) {
        if (isalpha(production[i])) {
            trailingSet[0] = production[i];
            trailingSet[1] = '\0';
            trailingFound = 1;
            break;
        }
    }

    printf("Leading(%c) = {%s}\n", nonTerminal, leadingSet);
    printf("Trailing(%c) = {%s}\n", nonTerminal, trailingSet);

    return 0;
}
