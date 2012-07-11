#include <stdio.h>
#include <stdlib.h>

FILE *fp;

int main(){
    char filename[] = "test.txt";
    int temp;
    fp = fopen(filename,"r");

    if(fp == NULL){
        fprintf(stderr, "Can't open input file %s!\n", filename);
        exit(1);
    }
    while(fscanf(fp,"%d", &temp) != EOF){
        printf("%d\n",temp);
    }
    fclose(fp);
}
