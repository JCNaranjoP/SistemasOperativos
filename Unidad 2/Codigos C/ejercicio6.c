#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    pid_t pid_hijo1, pid_hijo2;
    int status1,status2;
    int factorial=1;
    pid_hijo1 = fork();
    switch(pid_hijo1) {
        case -1: /* Error */
            printf("Error al crear el proceso");
        return -1;
        case 0: /* Código ejecutado por el hijo1 */
            for (int i = 1; i < 11; i++){
                factorial*=i;
                printf("HIJO1: fact(%d) = %d\n",i,factorial);
            }
        break;
        default: /* Código ejecutado por el padre */
            pid_hijo2 = fork();
            switch(pid_hijo2) {
                case -1: /* Error */
                    printf("Error al crear el proceso");
                return -1;
                case 0: /* Código ejecutado por el hijo2 */
                    for (int i = 1; i < 11; i++){
                        factorial*=i;
                        printf("HIJO2: fact(%d) = %d\n",i,factorial);
                    }
                break;
                default: /* Código ejecutado por el padre */
                    /* Esperamos al primer hijo */
                    waitpid(pid_hijo1, &status1, 0);
                    /* Esperamos al segundo hijo */
                    waitpid(pid_hijo2, &status2, 0);
            }
    }
     /* Esta línea será ejecutada por ambos procesos, pero en
        en diferente contexto (el de cada proceso) */
        if(pid_hijo1==0) printf("Soy el hijo1 terminando\n");
         else if(pid_hijo2==0) printf("Soy el hijo2 terminando\n");
         else printf("Soy el padre terminando\n");
     exit(EXIT_SUCCESS);
 }