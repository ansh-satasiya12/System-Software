#include<stdio.h>
#include<string.h>
#define TABSZ 10

typedef struct{
    char name[10];
    int occupied;

}node;

node symtab[TABSZ];

void createtable(){
    for(int i =0;i<TABSZ;i++){
        symtab[i].occupied = 0;
    }
}

int hash(char *str) {
    int sum = 0;
    for (int i = 0;str[i]!= '\0';i++) {
        sum += str[i];
    }
    return sum % TABSZ;
}

void insert(char *str){
    int index = hash(str);

    int full = 1;
    for (int i = 0; i < TABSZ; i++) {
        if (symtab[i].occupied == 0) {
            full = 0;
            break;
        }
    }

    if (full) {
        printf("HASH TABLE IS FULL\n");
        return;
    }

    while (symtab[index].occupied) {
        index = (index + 1) % TABSZ;
    }


    strcpy(symtab[index].name, str);
    symtab[index].occupied = 1;
    printf("Inserted '%s' at index %d\n", str, index);

}

int search(char *str){
    int index = hash(str);
    int start = index;

    while (symtab[index].occupied) {
        if (strcmp(symtab[index].name, str) == 0) {
            printf("Found '%s' at index %d\n", str, index);
            return index;
        }

        index = (index + 1) % TABSZ;

        if (index == start)
            break;   
    }

    printf("'%s' not found\n", str);
    return -1;
}

display(){
    printf("\n--- SYMBOL TABLE ---\n");
    printf("Index\tSymbol\n");
    printf("------------------\n");
    for (int i = 0; i < TABSZ; i++) {
        if (symtab[i].occupied) {
            printf("%d\t%s\n", i, symtab[i].name);
        } else {
            printf("%d\t---\n", i);
        }
    }
    printf("------------------\n");
}
