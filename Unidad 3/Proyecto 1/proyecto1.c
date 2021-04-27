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
    pipe(pfdPadre);
    pipe(pfdHijo);
    pid_hijo = fork();
    switch(pid_hijo) {
        case -1: /* Error */
            printf("Error al crear el proceso");
            return -1;
        case 0: /* Código ejecutado por el hijo */
            close(pfdPadre[1]);
            close(pfdHijo[0]);
            
            close(pfdHijo[1]);
            close(pfdPadre[0]);
            break;
        default: /* Código ejecutado por el padre */
            close(pfdPadre[0]);
            close(pfdHijo[1]);
            while (1)
            {
                scanf("%[^\n]",&buf);
                getc(stdin);
                /* write pipe */
                write(pfdPadre[1], buf, MSGSIZE);
                /* read pipe */
                read(pfdHijo[0], buf, MSGSIZE);
                /* imprimimos el mensaje */
                printf("%s\n",buf);
            }
            close(pfdPadre[1]);
            close(pfdHijo[0]);
            waitpid(pid_hijo, &status, 0);
    }
    /* Esta línea será ejecutada por ambos procesos, pero en
        en diferente contexto (el de cada proceso) */
    exit(EXIT_SUCCESS);
}