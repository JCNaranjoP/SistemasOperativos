//p2.c
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include <string.h>

struct pareja //estructura
    {
        char clave[20];
        int valor;
    };
struct pareja *ppareja;
int cont=0;

void load(char *archivo);
void writee(char *archivo);

int main(int argc, char *argv[]) {
    ppareja = (struct pareja *) malloc(sizeof(struct pareja)*100);
    load(argv[1]);
    writee(argv[3]);
    free(ppareja);
    exit(EXIT_SUCCESS); // exit(EXIT_FAILURE) en caso de error
} 

void load(char *archivo){
    strcat(archivo,".txt");
    FILE *in_file = fopen(archivo,"r");
    if(in_file == NULL){
        printf("El archivo especificado no existe\n");
        exit(0);
    }
    while(1){
        if(feof(in_file)){
            break;
        }
        fscanf(in_file,"%s",(ppareja + cont) -> clave);
        fscanf(in_file,"%d",&(ppareja + cont) -> valor);
        cont++;
    }
    fclose(in_file);
}

void writee(char *archivo){
    strcat(archivo,".txt");
    FILE *file = fopen(archivo, "w");
    for(int i = cont-1; i > -1 ;i--){
        fprintf(file,"%s %d\n",(ppareja + i)->clave,(ppareja + i)->valor);
    }
    fclose(file);
}