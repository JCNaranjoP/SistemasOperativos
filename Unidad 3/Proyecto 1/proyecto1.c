#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    pid_t pid_hijo;
    int status;
    int pfdPadre[2];
    int pfdHijo[2];
    int MSGSIZE = 100;
    char buf[MSGSIZE];
    
    exit(EXIT_SUCCESS);
}