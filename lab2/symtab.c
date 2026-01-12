#include<stdio.h>
#include<string.h>
#include "symtab.h"

static SymNode symtab[SYMTAB_SIZE];

void init_symtab(){
    for(int i=0;i< SYMTAB_SIZE;i++){
        symtab[i].is_occupied = 0;
        symtab[i].symbol[10] = '\0';
        symtab[i].address = 0;
    }
}

int insert_symbol(char *symbol,int address){
     for(int i = 0;i <SYMTAB_SIZE;i++){
        if (symtab[i].is_occupied &&
            strcmp(symtab[i].symbol, symbol) == 0) {
            return 0; 
        }
     }

     for (int i = 0; i < SYMTAB_SIZE; i++) {
        if (!symtab[i].is_occupied) {
            strcpy(symtab[i].symbol, symbol);
            symtab[i].address = address;
            symtab[i].is_occupied = 1;
            return 1;
        }
    }

    return 0;
}

int search_symbol(char *symbol) {
    for (int i = 0; i < SYMTAB_SIZE; i++) {
        if (symtab[i].is_occupied &&
            strcmp(symtab[i].symbol, symbol) == 0) {
            return symtab[i].address;
        }
    }
    return -1; 
}

void display_symtab() {
    printf("\n[Symbol Table]\n");
    printf("Index\tLabel\tAddress\n");

    for (int i = 0; i < SYMTAB_SIZE; i++) {
        if (symtab[i].is_occupied) {
            printf("%d\t%s\t%X\n",
                   i,
                   symtab[i].symbol,
                   symtab[i].address);
        }
    }
}
