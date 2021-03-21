#include <stdio.h>
 #include <stdlib.h>
 #include <stdint.h>
 #include <string.h>

 char comando[10];
 int dbSize;
 char dbName[11];
int dbCont = 0;
 int menu=1;
char archivo[100];

 struct estudiante //estructura
 {
     int cedula;
     char nombre[30];
     int semestre;
 };
 struct estudiante *pestudiante;
 



 

 void mkdb(){
     scanf("%s", dbName);
     scanf("%d",&dbSize);
     getc(stdin);
     pestudiante = (struct estudiante *) malloc(sizeof(struct estudiante)*dbSize);
     dbCont=0;
     if(pestudiante == NULL) exit(0);  
 }
 
void loaddb(void){
    int cedulaA;
    char nombreA[30];
    int semestreA;
    char nombreArchivo[100];
    scanf("%s",nombreArchivo);
    getc(stdin);
    FILE *in_file = fopen(nombreArchivo,"r");
    if(in_file == NULL){
        printf("El archivo especificado no existe");
        exit(0);
    }
    strcat(archivo,nombreArchivo);
    while(1){
        if(feof(in_file)){
            break;
        }
        
        if(pestudiante != NULL){
            if(dbCont < dbSize){
                fscanf(in_file,"%d", &(pestudiante + dbCont)->cedula);
                fscanf(in_file,"%s", ((pestudiante + dbCont)->nombre));
                fscanf(in_file,"%d", &(pestudiante + dbCont)->semestre);
                getc(stdin);
                dbCont++;
                if(dbCont == dbSize){
                    printf("Base de datos llena\n");
                }
            }else{
                printf("Error, base de datos llena\n");
                break;
            } 
        }else{
        printf("No se ha creado la base de datos\n");
        break;
    } 

     }
     fclose(in_file);
 }

 void mkreg(void){
     if(pestudiante != NULL){
         if(dbCont < dbSize){
             scanf("%d", &(pestudiante + dbCont)->cedula);
             scanf("%s", (pestudiante + dbCont)->nombre);
             scanf("%d", &(pestudiante + dbCont)->semestre);
             getc(stdin);
             dbCont++;
             if(dbCont == dbSize){
                 printf("Base de datos llena\n");
             }
         }
         else printf("Error, base de datos llena\n");
     }else printf("No se ha creado la base de datos\n");

 }


 void readall(void){
         if(pestudiante != NULL){
             for(int i= 0; i < dbCont;i++){
                  printf("cedula: %d nombre: %s semestre: %d\n",(pestudiante + i)->cedula,(pestudiante + i)->nombre,(pestudiante + i)->semestre);
             }
         }else printf("No se ha creado la base de datos\n");
     
 }

void exitMenu(void){
    char entrada[10];
    int ret; 
    int respuesta=1;
    while(respuesta){
        printf("¿Desea guardar la base de datos? si/no\n");
        scanf("%s", entrada);
         ret = strcmp(entrada, "si");
         
         if(ret == 0){
             FILE *file;
            if(pestudiante != NULL){
                
             file = fopen(archivo, "w");
             for(int i= 0; i < dbCont;i++){
                  fprintf(file,"%d %s %d\n",(pestudiante + i)->cedula,(pestudiante + i)->nombre,(pestudiante + i)->semestre);
             }
         }else printf("No se ha creado la base de datos\n");

            fclose(file);
             menu=0;
             respuesta=0;
         }
         ret = strcmp(entrada, "no");
         if(ret == 0){
             menu=0;
            respuesta=0;
         }
    }
}

void readsize(void){
    if(pestudiante != NULL){
     printf("La base de datos tiene %d registros", dbSize);
    }else printf("No se ha creado la base de datos\n");
}

 void readreg(void){
     int ret;
     int cedulaBuscar;
     scanf("%d", &cedulaBuscar);
     getc(stdin);

     if(pestudiante != NULL){
         for(int i= 0; i < dbCont;i++){
             if((pestudiante + i)->cedula==cedulaBuscar){
                 printf("cedula: %d nombre: %s semestre: %d\n",(pestudiante + i)->cedula,(pestudiante + i)->nombre,(pestudiante + i)->semestre);
                return;
                 
             }
         }
         printf("Registro no encontrado\n");
     }else printf("No se ha creado la base de datos\n");
 }
 
void savedb(void){
    char rutaArchivo[100];
    scanf("%s",rutaArchivo);
    getc(stdin);
    FILE *file;
    
    file = fopen(rutaArchivo, "w");
     if(pestudiante != NULL){
             for(int i= 0; i < dbCont;i++){
                  fprintf(file,"%d %s %d\n",(pestudiante + i)->cedula,(pestudiante + i)->nombre,(pestudiante + i)->semestre);
             }
         }else printf("No se ha creado la base de datos\n");

  fclose(file);
}


int main(void) {
     int ret;
    
     while(menu){
         // get the command
         scanf("%s", comando);
         ret = strcmp(comando, "mkdb");
         if(ret == 0) mkdb();
         ret = strcmp(comando, "loaddb");
         if(ret == 0) loaddb();
         ret = strcmp(comando, "mkreg");
         if(ret == 0) mkreg();
         ret = strcmp(comando, "readreg");
         if(ret == 0) readreg();
         ret = strcmp(comando, "readall");
         if(ret == 0) readall();
         ret = strcmp(comando, "readsize");
         if(ret == 0) readsize();
         ret = strcmp(comando, "savedb");
         if(ret == 0) savedb();
          ret = strcmp(comando, "exit");
         if(ret == 0) exitMenu();

     }
     free(pestudiante);
     return EXIT_SUCCESS;
 }