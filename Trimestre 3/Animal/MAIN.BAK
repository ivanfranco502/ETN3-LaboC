#include "clases.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void main(void){

	int ext,cal,esp;
	char *nom=(char *)(malloc(sizeof(char)*20));
	Animal *a= new Animal();
	clrscr();

	printf("Ingrese la cantidad de extremidades:");
	scanf("%i",&ext);
	printf("Ingrese la cantidad de calorias:");
	scanf("%i",&cal);
	printf("Es viviparo(1) o es oviparo(2):");
	scanf("%i",&esp);
	printf("Ingrese el nombre de su animal:");
	scanf("%s",nom);
	a->asignarExtremidades(ext);
	a->asignarCalorias(cal);
	a->asignarEspecie(esp);
	a->asignarNombre(nom);
	printf("\nSu animal tiene %i extremidades",a->obtenerExtremidades());
	printf("\nSu animal tiene %i calorias",a->obtenerCalorias());
	printf("\nSu animal tiene de nombre %s",a->obtenerNombre());
	switch(a->obtenerEspecie()){
		case 1:
			printf("\nSu animal es viviparo");
			break;
		case 2:
			printf("\nSu animal es oviparo");
			break;
	}
	printf("\nSu animal tiene %i de hambre",a->obtenerHambre());
	printf("\nSu animal tiene %i de sed",a->obtenerSed());
	switch(a->obtenerEstado()){
		case 1:
			printf("\nSu animal esta vivo");
			break;
		case 2:
			printf("\nSu animal esta muerto");
			break;
	}

}