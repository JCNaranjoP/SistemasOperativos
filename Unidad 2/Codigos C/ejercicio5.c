#include <stdio.h>
 #include <stdlib.h>

 int main(int argc, char *argv[]) {
     int arregloInt[argc-1];
     int min,max;
     int suma = 0;
     for(int i = 0; i< argc-1; i++){
        arregloInt[i]=atoi(argv[i+1]);
        printf("arregloInt[%d] = %d\n", i,arregloInt[i]);
        if(i==0){
        min=arregloInt[0];
        max=arregloInt[0];
        }
        if(arregloInt[i]<min) min = arregloInt[i];
        if(arregloInt[i]>max) max = arregloInt[i];
        suma+=arregloInt[i];
     }
     printf("MIN: %d\n"
            "MAX: %d\n"
            "AVG: %f\n", min,max,(float)suma/(argc-1));
     exit(EXIT_SUCCESS); // exit(EXIT_FAILURE) en caso de error
 }