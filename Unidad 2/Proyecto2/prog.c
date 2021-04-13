#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <pthread.h>

void load(char *archivo);
void imprimir(void);
void processHilo1(char *archivo);
void processHilo2(char *archivo);
void resultado(char *archivo);

struct linea //estructura
    {
        char nombre[20];
        char ocupacion[20];
        int edad;
    };
struct linea *plinea;
int cont=0;


int main(int argc, char *argv[]) {
    plinea = (struct linea *) malloc(sizeof(struct linea)*100);
    load(argv[1]); //Metodo que carga los datos
    imprimir(); //Metodo que imprime los registros de la estructura
    
    pthread_t id_hilo1;
    pthread_t id_hilo2;
    pthread_create(&id_hilo1, NULL, &processHilo1,argv[2]);
    pthread_create(&id_hilo2, NULL, &processHilo2,argv[3]);
    pthread_join(id_hilo1,NULL);
    pthread_join(id_hilo2,NULL);


    resultado(argv[2]);
    resultado(argv[3]);
    free(plinea);
    exit(EXIT_SUCCESS);
}

void load(char *archivo){
    char nombre[10];
    strcat(nombre,archivo);
    strcat(nombre,".txt");
    FILE *in_file = fopen(nombre,"r");
    if(in_file == NULL){
        printf("El archivo especificado no existe\n");
        exit(0);
    }
    while(1){
        if(feof(in_file)){
            break;
        }
        fscanf(in_file,"%s",(plinea + cont) -> nombre);
        fscanf(in_file,"%s",(plinea + cont) -> ocupacion);
        fscanf(in_file,"%d",&(plinea + cont) -> edad);
        cont++;
    }
    fclose(in_file);
}

void imprimir(void){
    for (int i = 0; i < cont; i++)
    {
        printf("%s %s %d\n", (plinea + i)->nombre, (plinea + i)->ocupacion, (plinea + i)->edad);
    } 
}

void processHilo1(char *archivo){
    char nombre[10];
    strcat(nombre,archivo);
    strcat(nombre,".txt");
    FILE *file = fopen(nombre, "w");
    for(int i = cont-1; i > -1 ;i--){
        fprintf(file,"%s %s %d\n", (plinea + i)->nombre, (plinea + i)->ocupacion, (plinea + i)->edad);
    }
    fclose(file);
}

void processHilo2(char *archivo){
    struct linea *plineaHilo = (struct linea *) malloc(sizeof(struct linea)*cont);
    for(int i=0;i<cont;i++){
        strcat((plineaHilo + i)->nombre , (plinea + i)->nombre);
        strcat((plineaHilo + i)->ocupacion,(plinea + i)->ocupacion);
        (plineaHilo + i)->edad = (plineaHilo + i)->edad;
    }

    char nombre[10];
    strcat(nombre,archivo);
    strcat(nombre,".txt");
    FILE *file = fopen(nombre, "w");
    int mayor = 0;
    for(int j = 0; j < cont ;j++){
        for (int i = 0; i < cont; i++)
        {
            if((plineaHilo + i)->ocupacion[0] < (plineaHilo + mayor)->ocupacion[0]) mayor = i;
        }
        
        fprintf(file,"%s %s %d\n", (plineaHilo + mayor)->nombre, (plineaHilo + mayor)->ocupacion, (plineaHilo + mayor)->edad);
        (plineaHilo + mayor)->ocupacion[0] = '{';
    }
    fclose(file);
    free(plineaHilo);
}

void resultado(char *archivo){
    printf("%s\n",archivo);
    load(archivo);
    printf("Archivo: %s\n",archivo);
    imprimir();
}