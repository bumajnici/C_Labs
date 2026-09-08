#include"my_lib.h"
#include<stdio.h>
#include<string.h>

char* getHeader() {
    return "Variant: 16\tAuthor: Mykola Ponomarenko";
}

void printHeader () {
    printf(getHeader());
}

void printDuck(char* message) {
    int length = strlen(message);
    printf(" ");
    printf("_");
    for (int i = 0; i < length + 2; i++) {
        printf("_");
    }
    printf("_ \n");
    printf(" / ");
    for (int i = 0; i < length + 2; i++) {
        printf(" ");
    }
    printf(" \\\n");
    printf("| %s   |\n", message);
    printf(" \\_");
    for (int i = 0; i < length + 2; i++) {
        printf("_");
    }
    printf("_/\n");
    printf("  \\\n");
    printf("   \\\n");
    printf("    \\\n");
    printf("      ,~~.\n");
    printf(" ,   (  o )>\n");
    printf(" )`~~'   (\n");
    printf("(   .__)  )\n");
    printf(" `-.____,'\n");
}

void removeSymbol(char* message, int symbolPosition) {
    for (int i = symbolPosition; i < strlen(message); i++) {
        message[i] = message[i + 1];
    }
}