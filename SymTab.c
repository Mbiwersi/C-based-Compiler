#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SymTab.h"

SymTab * createSymTab(int size) {
    SymTab* s = (SymTab *) malloc(sizeof(SymTab*));
    s->contents = (SymEntry **) malloc(sizeof(SymEntry*) * size);

    for(int i = 0; i < s->size; i++) {
        s->contents[i]->name = NULL;
    }
    s->size = size;
    s->current = NULL;
}

void destroySymTab(SymTab *table) {
    for(int i = 0; i < table->size; i++){
        SymEntry* current = table->contents[i];
        while(current != NULL){
            free(current->attribute);
            free(current->name);

            SymEntry* temp = current;
            current = current->next;

            free(temp->next);
            free(temp);
        }
        free(current);
    }
    free(table->contents);
    // free(table->size);
    free(table->current);
    free(table);
}

// Hash function method
unsigned long hash_function(char* str, int size) {
    unsigned long i = 0;
    for (int j=0; str[j]; j++)
        i += str[j];
    return i % size;
}

// return 0 if the name is not in the linked list, else return 1
int inList(SymEntry* head, char* name) {
    SymEntry* current  = head;
    while(current != NULL){
        // if(current->name == name){
        if(strcmp(current->name, name) == 0) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}


int enterName(SymTab* table, char *name) {
    int hashNum = hash_function(name, table->size);

    // check for dups
    if(!inList(table->contents[hashNum], name)){
        // create entry
        SymEntry* entry = (SymEntry*) malloc(sizeof(SymEntry));

        // entry->name = name;
        entry->name = strdup(name);

        // entry->attribute = NULL;
        // entry->attribute = malloc(sizeof(void *)); // unneeded 

        //strdup(name) -> malloc and copy
        entry->next = table->contents[hashNum];

        // put in list
        table->contents[hashNum] = entry;
        table->current = entry;
    }
}

int findName(SymTab* table, char* name) {
    // printf("Searching for %s; ", name);
    for(int i = 0; i < table->size; i++) {
        SymEntry* current = table->contents[i];
        while(current != NULL) {
            // if(current->name == name){
            if(strcmp(current->name, name) == 0){
                table->current = current;
                // printf("Found name!\n");
                return 1;
            }
            current = current->next;
        }
    }
    // printf("Did not find name\n");
    return 0;
}

int hasCurrent(SymTab* table) {
    return table->current != NULL;
}

void setCurrentAttr(SymTab* table, void * attr) {
    table->current->attribute = attr;
}

void * getCurrentAttr(SymTab* table) {
    return table->current->attribute;
}

char * getCurrentName(SymTab* table) {
    return table->current->name;
}

SymEntry * getCurrent(SymTab* table){
    return table->current;
}

int startIterator(SymTab* table) {
    for(int i = 0; i < table->size; i++){
        SymEntry* current = table->contents[i];
        if(current != NULL){
            table->current = current;
            return 1;
        }
    }
    return 0;
}


int nextEntry(SymTab* table) {
    // case for null current
    if(table->current == NULL){
        // printf("Returning zero\n");
        return 0;
    }

    // check if the current has a next first
    if(table->current != NULL){
        if(table->current->next != NULL){
            // printf("Found next current using current next = %s\n", table->current->next->name);
            table->current = table->current->next;
            return 1;
        }
    }

    // find the next entry using the hash_function of the current + 1
    for(long i = hash_function(table->current->name, table->size) + 1; i < table->size; i++){
        SymEntry* current = table->contents[i];
        // printf("Searching row(%d)\n", i);
        if(current != NULL){
            table->current = current;
            // printf("\nFound next current using hash = %s\n", table->current->name);
            return 1;
        }
    }
    return 0; // all have been visited
}

// print out the table
void printTab(SymTab* s){
    printf("\n");
    for(int i = 0; i < s->size; i++){
        SymEntry* current = s->contents[i];
        printf("Row(%d) = ", i);
        while(current != NULL){
            printf(current->name);
            printf(", ");
            current = current->next;
        }
        printf("\n");
    }
}

// int main(int argc, char *argv[]) {
//     SymTab * s = createSymTab(7);

//     // Testing
//     printf("\n----- TESTING enterName() -----\n");
//     enterName(s, "Michael\0");
//     enterName(s, "Jenna\0");
//     enterName(s, "Steven\0");
//     enterName(s, "karen\0");
//     enterName(s, "joe\0");
//     enterName(s, "Bender\0");
//     enterName(s, "Bush\0");
//     enterName(s, "Vlad\0");

//     printTab(s);

//     startIterator(s);
//     nextEntry(s);
//     nextEntry(s);
//     nextEntry(s);
//     nextEntry(s);
//     nextEntry(s);
//     nextEntry(s);
//     nextEntry(s);
//     nextEntry(s);


//     // // adding dups
//     // enterName(s, "Michael");

//     // // testing findName
//     // printf("\n----- TESTING findName() -----\n");
//     // findName(s, "Michael\0");
//     // findName(s, "David\0");
//     // findName(s, "karen\0");
//     // findName(s, "Anna\0");
//     // findName(s, "Vlad\0");
//     // findName(s, "Steven\0");
//     // findName(s, "joe\0");

//     // // Testing hasCurrent
//     // SymTab * s2 = createSymTab(7);
//     // printf("hasCurrent(); expecting 1, result = %d\n", hasCurrent(s));
//     // printf("hasCurrent(); expecting 0, result = %d\n", hasCurrent(s2));

//     // // Testing getCurrentName
//     // printf("getCurrentName() = %s\n", getCurrentName(s));
//     // findName(s, "Michael");
//     // printf("getCurrentName() = %s\n", getCurrentName(s));

//     // // Testing startIterator
//     // startIterator(s);
//     // printf("New current.name = %s\n", s->current->name);
//     // enterName(s, "Issac");
//     // printf("Current name after entering name = %s\n", s->current->name);
//     // enterName(s, "Kolda");
//     // printf("Current name after entering name = %s\n", s->current->name);
//     // printf("New current.name = %s\n", s->current->name);

//     // startIterator(s);
//     // printf("current.name after startIterator() = %s\n", s->current->name);

//     // // printf("Destorying table\n");
//     // // destroySymTab(s);
//     // // findName(s, "Michael");

//     // // Visual look at the list
//     // printTab(s);

//     // printf("\nCurrent after startIterator = %s\n", s->current->name);
//     // printf("Current after another nextEntry = %s     return value = %d\n", s->current->name, nextEntry(s));
//     // printf("Current after another nextEntry = %s     return value = %d\n", s->current->name, nextEntry(s));
//     // printf("Current after another nextEntry = %s     return value = %d\n", s->current->name, nextEntry(s));
//     // printf("Current after another nextEntry = %s     return value = %d\n", s->current->name, nextEntry(s));
//     // printf("Current after another nextEntry = %s     return value = %d\n", s->current->name, nextEntry(s));
//     // printf("Current after another nextEntry = %s     return value = %d\n", s->current->name, nextEntry(s));
//     // printf("Current after another nextEntry = %s     return value = %d\n", s->current->name, nextEntry(s));
//     // printf("Current after another nextEntry = %s     return value = %d\n", s->current->name, nextEntry(s));
//     // printf("Current after another nextEntry = %s     return value = %d\n", s->current->name, nextEntry(s));
//     // printf("Current after another nextEntry = %s     return value = %d\n", s->current->name, nextEntry(s));

//     // startIterator(s);
//     // printf("current.name after startIterator() = %s\n", s->current->name);
// }