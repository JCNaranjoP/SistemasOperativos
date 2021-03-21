/*
 ============================================================================
 Name        : Sistemas.c
 Author      : Camilo Naranjo
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

 int main(void) {
	int nMat;
	typedef struct{
		char nombre[32];
		float nota;
		int creditos;
	} Materia_t;
	printf("Introduzca el numero de materias que curso en el semestre: ");
	scanf("%d",&nMat);
	Materia_t *pMat = (Materia_t*)malloc(sizeof(Materia_t) * nMat);
	Materia_t *pFree = pMat;
	//Llenar datos de las materias
	for (int i=0; i<nMat; i++){
		getchar();
		printf("\nIngrese el nombre de la materia %d :", i+1);
		scanf("%32[^\n]s", &(pMat+i)->nombre);
		printf("Ingrese la nota de la materia %d :", i+1);
				scanf("%f", &(pMat+i)->nota);
	    printf("Ingrese el numero de creditos de la materia %d :", i+1);
				scanf("%d", &(pMat+i)->creditos);
	}
	//Imprimimos y sumamos las notas para sacar un promedio
	float sPromP = 0;
	int sCreditos = 0;
	for(int i=0; i<nMat; i++){
		printf("\nMateria: %s | Nota: %f | Creditos: %d",
				(pMat+i)->nombre, (pMat+i)->nota, (pMat+i)->creditos);
		sPromP += (pMat+i)->nota * (pMat+i)->creditos;
		sCreditos += (pMat+i)->creditos;
	}
	printf("\nEl promedio ponderado es: %f", (float)sPromP/sCreditos);


	free(pFree);
	return 0;
 }