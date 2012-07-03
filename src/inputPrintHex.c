#include <stdio.h>
#include <stdlib.h>

void printVal(unsigned char input){
    if(input > 15) return;

    switch(input){
        case 10:
            printf("A");
            break;
        case 11:
            printf("B");
            break;
        case 12:
            printf("C");
            break;
        case 13:
            printf("D");
            break;
        case 14:
            printf("E");
            break;
        case 15:
            printf("F");
            break;
        default:
            printf("%d", input);
            break;
    }
}

void printHex(unsigned char input){
    unsigned char temp = (input & 0xF0) >> 4;
    printf("0x");
    printVal(temp);
    temp = input & 0xF;
    printVal(temp);
}

int main(){
    FILE *fp;
    char filename[100];
    int temp;
    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename,"r");

    if(fp == NULL){
        fprintf(stderr, "Can't open input file %s!\n", filename);
        exit(1);
    }
    while(fscanf(fp,"%d", &temp) != EOF){
        printHex(temp);
        printf("\n");
    }
    fclose(fp);
}
