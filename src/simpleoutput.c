#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *fp;

int main(){
    char filename[] = "test.txt";
    int i;
    fp = fopen(filename,"w");

    if(fp == NULL){
        fprintf(stderr, "Can't open output file %s!\n", filename);
        exit(1);
    }
    srand(time(NULL));
    for(i = 0; i < 100; i++){
        fprintf(fp,"%d\n", rand() % 256);
    }
    fclose(fp);
}
