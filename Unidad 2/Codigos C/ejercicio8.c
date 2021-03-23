#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
    pid_t pid_hijo1, pid_hijo2, pid_hijo3;
    int status1,status2,status3;
    pid_hijo1 = fork();
    switch(pid_hijo1) {
        case -1: /* Error */
            printf("Error al crear el proceso");
        return -1;
        case 0: /* Código ejecutado por el hijo1 */
           execv("./MIN",argv);
        break;
        default: /* Código ejecutado por el padre */
            pid_hijo2 = fork();
            switch(pid_hijo2) {
                case -1: /* Error */
                    printf("Error al crear el proceso");
                return -1;
                case 0: /* Código ejecutado por el hijo2 */
                    execv("./MAX",argv);
                break;
                default: /* Código ejecutado por el padre */
                    pid_hijo3 = fork();
                    switch(pid_hijo3) {
                    case -1: /* Error */
                    printf("Error al crear el proceso");
                    return -1;
                    case 0: /* Código ejecutado por el hijo3 */
                        execv("./AVG",argv);
                    break;
                    default: /* Código ejecutado por el padre */
                        /* Esperamos al primer hijo */
                        waitpid(pid_hijo1, &status1, 0);
                        /* Esperamos al segundo hijo */
                        waitpid(pid_hijo2, &status2, 0);
                        /* Esperamos al tercer hijo */
                        waitpid(pid_hijo3, &status3, 0);
                    }
            }
    }
     /* Esta línea será ejecutada por ambos procesos, pero en
        en diferente contexto (el de cada proceso) */
        if(pid_hijo1==0) printf("Soy el hijo1 terminando\n");
         else if(pid_hijo2==0) printf("Soy el hijo2 terminando\n");
         else if(pid_hijo3==0) printf("Soy el hijo3 terminando\n");
         else printf("Soy el padre terminando\n");
         
     exit(EXIT_SUCCESS);
 }