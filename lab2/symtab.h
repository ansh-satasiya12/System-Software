#ifndef SYMTAB_H
#define SYMTAB_H

#define SYMTAB_SIZE 20
#define SYMBOL_LEN 10   

typedef struct {
    char symbol[SYMBOL_LEN];
    int address;        
    int is_occupied;    
} SymNode;

void init_symtab();
int insert_symbol(char *symbol, int address); 
int search_symbol(char *symbol); 
void display_symtab();

#endif
