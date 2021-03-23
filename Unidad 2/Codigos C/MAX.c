//MAX.c
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main(int argc, char *argv[]) {
    int max,num;
    for(int i = 1; i< argc; i++){
        num = atoi(argv[i]);
        if(i==1) max=num;
        if(num>max) max = num;
    }
    printf("MAX: %d\n", max);
    exit(EXIT_SUCCESS); // exit(EXIT_FAILURE) en caso de error
} 