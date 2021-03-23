//MIN.c
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
int main(int argc, char *argv[]) {
    int min,num;
    for(int i = 1; i< argc; i++){
        num = atoi(argv[i]);
        if(i==1) min=num;
        if(num<min) min = num;
    }
    printf("MIN: %d\n", min);
    exit(EXIT_SUCCESS); // exit(EXIT_FAILURE) en caso de error
} 