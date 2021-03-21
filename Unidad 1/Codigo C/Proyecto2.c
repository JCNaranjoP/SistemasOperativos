#include <stdio.h>
 #include <stdlib.h>
 #include <stdint.h>
 #include <string.h>

char comando[10];
int menu=1;
int dbActive = -1;
int nDb = 0;

struct estudiante //estructura
{
    int cedula;
    char nombre[30];
    int semestre;
};
 
struct dataBase //estructura bases de datos
{  
    char dbName[30];
    int dbSize;
    int dbCont;
    struct estudiante *pestudiante;
};
struct dataBase *pdataBase;

void svdb(void);
void rr(void);
void rsdb(void);
void exitMenu(void);
void radb(void);
void mreg(void);
void ldb(void);
void mdb(void);
void sdb(void);
void gdb(void);
void lsdbs(void);

int main(void) {
     int ret;
    
     while(menu){
         // get the command
         scanf("%s", comando);
         ret = strcmp(comando, "mdb");
         if(ret == 0) mdb();
         ret = strcmp(comando, "ldb");
         if(ret == 0) ldb();
         ret = strcmp(comando, "mreg");
         if(ret == 0) mreg();
         ret = strcmp(comando, "rr");
         if(ret == 0) rr();
         ret = strcmp(comando, "radb");
         if(ret == 0) radb();
         ret = strcmp(comando, "rsdb");
         if(ret == 0) rsdb();
         ret = strcmp(comando, "svdb");
         if(ret == 0) svdb();
          ret = strcmp(comando, "exit");
         if(ret == 0) exitMenu();
         ret = strcmp(comando, "sdb");
         if(ret == 0) sdb();
         ret = strcmp(comando, "gdb");
         if(ret == 0) gdb();
         ret = strcmp(comando, "lsdbs");
         if(ret == 0) lsdbs();

     }
     for(int i=0;i<nDb;i++){
         free((pdataBase + i)->pestudiante);
     }
     free(pdataBase);
     return EXIT_SUCCESS;
}
 
void gdb(void){
    if(dbActive!=-1){
        printf("Base de datos activa: %s, tamaño: %d, registros disponibles: %d", (pdataBase + dbActive)->dbName,(pdataBase + dbActive)->dbSize,((pdataBase + dbActive)->dbSize-(pdataBase + dbActive)->dbCont));
    }else printf("No hay ninguna base de datos activa\n");
}

void lsdbs(void){
    if(nDb!=0){
        for(int i=0;i<nDb;i++){
            printf("Nombre: %s tamaño: %d cantidad registros: %d\n", (pdataBase+i)->dbName,(pdataBase+i)->dbSize,(pdataBase+i)->dbCont);
        }
    }else printf("No se ha creado ninguna base de datos\n");
}

void sdb(void){
    int ret;
    char dbBuscar[30];
    scanf("%s", dbBuscar);
    getc(stdin);
    if(nDb != 0){
        for(int i= 0; i < nDb;i++){
            ret=strcmp((pdataBase+i)->dbName,dbBuscar);
            if(ret==0){
                dbActive=i;
                return; 
            }
        }
        printf("Base de datos no encontrada\n");
    }else printf("No se ha creado ninguna base de datos\n");
}
 void mdb(void){
    if(nDb == 0){
        pdataBase = (struct dataBase *) malloc(sizeof(struct dataBase)*10);
        pdataBase->dbCont=0;
        nDb++;
        scanf("%s", pdataBase->dbName);
        scanf("%d",&(pdataBase->dbSize));
        getc(stdin);
        pdataBase->pestudiante = (struct estudiante *) malloc(sizeof(struct estudiante)*pdataBase->dbSize);
        if(pdataBase == NULL) exit(0);
    }else{
        if(nDb < 5){
            (pdataBase + nDb)->dbCont=0;
            scanf("%s", (pdataBase + nDb)->dbName);
            scanf("%d",&((pdataBase + nDb)->dbSize));
            getc(stdin);
            (pdataBase + nDb)->pestudiante = (struct estudiante *) malloc(sizeof(struct estudiante)*(pdataBase + nDb)->dbSize);
            if(pdataBase == NULL) exit(0); 
            nDb++;
            if(nDb == 5)printf("Limite de bases de datos alcanzado\n");
        }else printf("Error, limite de bases de datos alcanzado\n");   
    }
}
 
void ldb(void){
    char nombreArchivo[100];
    scanf("%s",nombreArchivo);
    getc(stdin);
    FILE *in_file = fopen(nombreArchivo,"r");
    if(in_file == NULL){
        printf("El archivo especificado no existe\n");
        exit(0);
    }
    if(nDb == 0){
            pdataBase = (struct dataBase *) malloc(sizeof(struct dataBase)*10);
        }
        fscanf(in_file,"%s",(pdataBase + nDb)->dbName);
        fscanf(in_file,"%d",&(pdataBase + nDb)->dbSize);
        (pdataBase + nDb)->pestudiante = (struct estudiante *) malloc(sizeof(struct estudiante)*(pdataBase + nDb)->dbSize);
        (pdataBase + nDb)->dbCont=0;
    while(1){
        if(feof(in_file)){
            break;
        }
        
    
            fscanf(in_file,"%d", &((pdataBase + nDb)->pestudiante + (pdataBase + nDb)->dbCont)->cedula);
            fscanf(in_file,"%s", (((pdataBase + nDb)->pestudiante + (pdataBase + nDb)->dbCont)->nombre));
            fscanf(in_file,"%d", &((pdataBase + nDb)->pestudiante + (pdataBase + nDb)->dbCont)->semestre);
            
            (pdataBase + nDb)->dbCont++;
            if((pdataBase + nDb)->dbCont == (pdataBase + nDb)->dbSize){
                printf("Base de datos llena\n");
                fclose(in_file);
                printf("Base de datos cargada correctamente\n");
                nDb++;
                return;
            }
       
        }
        nDb++;
        fclose(in_file);
        printf("Base de datos cargada correctamente\n");
     
}

void mreg(void){
    if(dbActive != -1){
            if((pdataBase + dbActive)->dbCont < (pdataBase + dbActive)->dbSize){
                scanf("%d", &((pdataBase + dbActive)->pestudiante + (pdataBase + dbActive)->dbCont)->cedula);
                scanf("%s", ((pdataBase + dbActive)->pestudiante + (pdataBase + dbActive)->dbCont)->nombre);
                scanf("%d", &((pdataBase + dbActive)->pestudiante + (pdataBase + dbActive)->dbCont)->semestre);
                getc(stdin);
                (pdataBase + dbActive)->dbCont++;
                if((pdataBase + dbActive)->dbCont == (pdataBase + dbActive)->dbSize){
                 printf("Base de datos llena\n");
                }
            }else printf("Error, base de datos llena\n"); 
    }else printf("No hay ninguna base de datos activa\n");
}


 void radb(void){
    if(dbActive != -1){   
        if((pdataBase + dbActive)->pestudiante != NULL){
            for(int i= 0; i < (pdataBase + dbActive)->dbCont;i++){
                printf("cedula: %d nombre: %s semestre: %d\n",((pdataBase + dbActive)->pestudiante + i)->cedula,((pdataBase + dbActive)->pestudiante + i)->nombre,((pdataBase + dbActive)->pestudiante + i)->semestre);
            }
        }else printf("No se ha creado ningun registro\n");
    }else printf("No hay ninguna base de datos activa\n");
 }

void exitMenu(void){
    if(dbActive != -1){
        char entrada[10];
        int ret; 
        int respuesta=1;
        while(respuesta){
            printf("¿Desea guardar la base de datos? si/no\n");
            scanf("%s", entrada);
            ret = strcmp(entrada, "si");
            if(ret == 0){
                svdb();
                menu=0;
                respuesta=0;
            }
            ret = strcmp(entrada, "no");
            if(ret == 0){
                menu=0;
                respuesta=0;
            }
        }
    }else menu = 0; 
}

void rsdb(void){
    if(dbActive != -1){
        if((pdataBase + dbActive)->pestudiante != NULL){
         printf("La base de datos tiene %d registros\n", (pdataBase + dbActive)->dbSize);
        }else printf("No se ha creado ningun registro\n");
    }else printf("No hay ninguna base de datos activa\n");
}

 void rr(void){
     int cedulaBuscar;
     scanf("%d", &cedulaBuscar);
     getc(stdin);
    if(dbActive!=-1){
            for(int i= 0; i < (pdataBase + dbActive)->dbCont;i++){
                if(((pdataBase + dbActive)->pestudiante + i)->cedula==cedulaBuscar){
                 printf("cedula: %d nombre: %s semestre: %d\n",((pdataBase + dbActive)->pestudiante + i)->cedula,((pdataBase + dbActive)->pestudiante + i)->nombre,((pdataBase + dbActive)->pestudiante + i)->semestre);
                return; 
                }
            }
            printf("Registro no encontrado\n");
    }else printf("No hay ninguna base de datos activa\n");
     
 }
 
void svdb(void){
    getc(stdin);
    if(dbActive!=-1){
        char rutaArchivo[100];
        strcpy(rutaArchivo,(pdataBase + dbActive)->dbName);
        strcat(rutaArchivo,".txt");
        FILE *file;
        file = fopen(rutaArchivo, "w");
            fprintf(file,"%s %d\n",(pdataBase + dbActive)->dbName,(pdataBase + dbActive)->dbSize);
             for(int i= 0; i < (pdataBase + dbActive)->dbCont;i++){
                  fprintf(file,"%d %s %d\n",((pdataBase + dbActive)->pestudiante + i)->cedula,((pdataBase + dbActive)->pestudiante + i)->nombre,((pdataBase + dbActive)->pestudiante + i)->semestre);
            }
      
        fclose(file);
    }else printf("No hay ninguna base de datos activa\n");
    
}


