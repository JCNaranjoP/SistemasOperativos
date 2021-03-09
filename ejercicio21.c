/*
 * archivo.c
 *
 *  Created on: 02 mar. 2021
 *      Author: naranjo
 */
#include <stdio.h>
#include <stdint.h>

 uint8_t arrayCommon(int32_t* arr1, int32_t arr1Size,int32_t* arr2, int32_t arr2Size, int32_t* arrRes, int32_t arrResSize){
	 uint8_t salida=0;
	 for(int i=0; i<arr1Size; i++){
		 for(int j=0; j<arr2Size; j++){
			 if(*(arr1+i)==*(arr2+j)){
				 int bandera = 1;
				 for(int k=0; k<arrResSize; k++){
					 if(*(arrRes+k)==*(arr1+i)){
						 bandera = 0;
					 }
				 }
				 if(bandera==1){
					 *(arrRes+salida)=arr1[i];
					 salida++;
				 }

			 }
		 }
	 }
	 return salida;
 }

 int main (void){
	 int32_t arr1Size;
	 int32_t arr2Size;
	 int32_t arrResSize;
	 printf("Introduzca el tamaño del primer arreglo: ");
	 scanf("%d",&arr1Size);
	 int32_t arr1[arr1Size];
	 for(int i=0; i<arr1Size;i++){
		 printf("Introduzca el valor %d: ",i+1);
		 scanf("%d",arr1+i);
	 }
	 printf("Introduzca el tamaño del segundo arreglo: ");
	 scanf("%d",&arr2Size);
	 int32_t arr2[arr2Size];
	 for(int i=0; i<arr2Size;i++){
	 		 printf("Introduzca el valor %d: ",i+1);
	 		 scanf("%d",arr2+i);
	 	 }
	 if(arr1Size>arr2Size){
			 arrResSize=arr1Size;
		 }else{
			 arrResSize=arr2Size;
		 }
	 int32_t arrRes[arrResSize];
	uint8_t numeroRepetidos = arrayCommon(arr1, arr1Size, arr2, arr2Size, arrRes, arrResSize);
	printf("Se repiten %d numero:\n",numeroRepetidos);
	for(int i=0;i<numeroRepetidos;i++){
	    printf("Numero %d: %d\n",i+1,arrRes[i]);
	}
	 return 0;
 }