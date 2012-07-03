#include <stdio.h>

FILE *fp;

int main(){
    char filename[] = "test.txt";
    int i;
    fp = fopen(filename,"w");

    if(fp == NULL){
        fprintf(stderr, "Can't open output file %s!\n", filename);
        exit(1);
    }
    for(i = 0; i < 100; i++){
        fprintf(fp,"%d\n", i);
    }
    fclose(fp);
}
