#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *fp;
FILE *hexfile;

void printVal(unsigned char input){
    if(input > 15) return;

    switch(input){
        case 10:
            fprintf(hexfile,"A");
            break;
        case 11:
            fprintf(hexfile,"B");
            break;
        case 12:
            fprintf(hexfile,"C");
            break;
        case 13:
            fprintf(hexfile,"D");
            break;
        case 14:
            fprintf(hexfile,"E");
            break;
        case 15:
            fprintf(hexfile,"F");
            break;
        default:
            fprintf(hexfile,"%d", input);
            break;
    }
}

void printHex(unsigned char input){
    unsigned char temp = (input & 0xF0) >> 4;
    fprintf(hexfile,"0x");
    printVal(temp);
    temp = input & 0xF;
    printVal(temp);
}


int main(){
    char filename[] = "viInput.txt";
    char file2[] = "hexviInput.txt";
    int i;
    int temp;

    fp = fopen(filename,"w");
    if(fp == NULL){
        fprintf(stderr, "Can't open output file %s!\n", filename);
        exit(1);
    }

    hexfile = fopen(file2, "w");
    if(hexfile == NULL){
        fprintf(stderr, "Can't open output file %s!\n", filename);
        exit(1);
    }
    srand(time(NULL));

    for(i = 0; i < 100; i++){
        temp = rand() % 256;
        fprintf(fp,"%d\n", temp);
        printHex(temp);
        fprintf(hexfile,"\n");
    }

    fclose(fp);
    fclose(hexfile);
}
