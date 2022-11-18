#include "IOMngr.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


FILE *in = NULL;
FILE *list = NULL;
char line[MAXLINE + 1];

int lineNum;
int lineCol;
int lastPrintedLine = -1;

int openFiles(char * sourceName, char * listingName) {
    in = fopen(sourceName, "r");

    if(in == NULL){ // check for error in opening file
        return 0;
    }

    if(listingName != NULL) {
        list = fopen(listingName, "w");
    }
    lineNum = 1;
    lineCol = -1;

    fgets(line, MAXLINE + 1, in);
    
    return 1;
}

void closeFiles() {
    if(list != NULL){
        fclose(list);
    }
    fclose(in);
}


char getNextSourceChar() {
    // check for EOF with no new line
    if(feof(in) && line[lineCol] == '\0'){
        return EOF;
    }

    lineCol += 1;
    char c = line[lineCol];

    // Move to next line
    if(c == '\n'){  
        if(NULL == fgets(line, MAXLINE + 1, in)){
            return EOF;
        }
        lineCol = 0;
        lineNum += 1;
        c = line[lineCol];
    }

    // Print line to listing file
    if(getCurrentColumnNum() == 0 && list != NULL) {
        int someInt = getCurrentLineNum();
        char str[MAXLINE + 1];

        sprintf(str, "%d. %s", someInt, line);
        if(EOF == fputs(str, list)){
            printf("ERROR WRITING\n");
        }
    }
    return c;
}

void writeIndicator(int column) {
    // determine how many digits in the line number
    int count = 0;
    int col = getCurrentLineNum();

    // Print only the lines that have errors and only once
    if(list == NULL && lastPrintedLine != getCurrentLineNum()) {
        printf("%d. %s", getCurrentLineNum(), line);
        lastPrintedLine = getCurrentLineNum();
    }

    do{
        col /= 10;
        count++;
    }while(col != 0);

    
    if(list != NULL) { // with listing file
        if(feof(in)){
            fputs("\n", list);
        }
        for(int i = 0; i < column + 2 + count; i++) {
            fputs(" ", list);
        }
        fputs("^", list);
        fputs("\n", list);

    }

    else { // without listing file
        if(feof(in)){
            printf("\n");
        }
        for(int i = 0; i < column + 2 + count; i++) {
            printf(" ");
        }
        printf("^\n");
    }

}

void writeMessage(char * message) {
    if(list == NULL){
        printf("%s\n", message);
    }
    else{
        fputs(message, list);
        fputs("\n", list);
    }
}

int getCurrentLineNum() {
    return lineNum;
}

int getCurrentColumnNum() {
    return lineCol;
}

// int main(int argc, char *argv[]) {
//     openFiles("h3test.txt", "ListingFile.txt");
//     // openFiles("testFile.txt", NULL);
//     // openFiles(argv[1], argv[2]);

//     while(getNextSourceChar() != EOF){

//     }
//     writeIndicator(4);

//     closeFiles();

// }
