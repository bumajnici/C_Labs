#include "my_lib.h"
#include <stdio.h>
#include <string.h>

int main(void) {
    printDuck(getHeader());

    char str[100];

    printf("Enter a line: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("Your line:\n%s\n", str);

    int size = strlen(str);
    for (int i = 0; i < size; i++) {
        removeSymbol(str, i);
    }

    printf("Your modified line:\n%s\n", str);

    return 0;
}
