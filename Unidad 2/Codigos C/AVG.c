//AVG.c
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main(int argc, char *argv[]) {
    int num;
    int suma = 0;
    for(int i = 1; i< argc; i++){
        num = atoi(argv[i]);
        suma+=num;
    }
    printf("AVG: %f\n", (float)suma/(argc-1));
    exit(EXIT_SUCCESS); // exit(EXIT_FAILURE) en caso de error
} 