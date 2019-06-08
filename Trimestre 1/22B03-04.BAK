#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

/*CONSIGNA
Definir un registro con los siguientes campos:
	-X
	-Y
	-Z
	-Dim
Enteros donde (x,y,z) representan las coordenadas
de un punto y dim indica cuantas de esas
coordenadas ser n utilizadas. El programa deber 
pedir:
	1)la cantidad de dimensiones con que se trabaja.
	2)los pares de coordenadas de 2 puntos que
	dependeran del punto uno, y devolver  la
	distancia entre ambos puntos.
*/
typedef struct {
//creacion del typo llamado punto con variables X;Y;Z y DIM
	int x;
	int y;
	int z;
	int dim;
}punto;
int distancia(punto, punto);
void main (void){
	punto p1;
	punto p2;
	int boolDim=0;
	//vacia las variables
	p1.x=0;
	p2.x=0;
	p1.y=0;
	p2.y=0;
	p1.z=0;
	p2.z=0;
	p1.dim=1;
	p2.dim=1;
	do{
	//repeticion para
		clrscr();
		printf ("Ingrese la cantidad de dimensiones (1/2/3): ");
		scanf ("%i",&p1.dim);
		//cantidad de dimensiones
		printf ("Ingrese x del punto 1: ");
		//toma el valor x del punto 1
		scanf ("%i", &p1.x);
		switch (p1.dim){
		//si dim es dos
			case 2:{
			//toma el valor y del punto 1
				printf ("Ingrese y del punto 1: ");
				scanf ("%i", &p1.y);
				boolDim=0;
				break;
			}
			//si dim es tres
			case 3:{
				//toma el valor de y del punto 1
				printf ("Ingrese y del punto 1: ");
				scanf ("%i", &p1.y);
				//toma el valor de z del punto 1
				printf ("Ingrese z del punto 1: ");
				scanf ("%i", &p1.z);
				boolDim=0;
				break;
			}
			default: {
				if (p1.dim != 1){
					boolDim=1;
				}else{
					boolDim=0;
				}
			}
		}
	}while (boolDim==1);
	//toma el valor x del punto 1
	printf ("Ingrese x del punto 2: ");
	scanf ("%i", &p2.x);
	switch (p1.dim){
		//si dimension es 2
		case 2:{
			printf ("Ingrese y del punto 2: ");
			scanf ("%i", &p2.y);
			//toma el valor y del punto 2
			break;
		}
		//si dimension es 3
		case 3:{
		//se toma el valor y del punto 2
			printf ("Ingrese y del punto 2: ");
			scanf ("%i", &p2.y);
			//se toma el valor z del punto 2
			printf ("Ingrese z del punto 2: ");
			scanf ("%i", &p2.z);
			break;
		}
	}
//llamar a funcion distancia
printf ("La distancia entre los dos puntos es de: %i", distancia(p1,p2));
getch();
}
int distancia (punto p1, punto p2){
//funcion que saca la distancia del punto 1 y del punto 2
	int resultado;
	resultado=sqrt((pow(p1.x-p2.x,2))+(pow(p1.y-p2.y,2))+(pow(p1.z-p2.y,2)));
	//resultado es igual
	//raiz(((x-x1)^2)+((y-y1)^2)+((z-z1)^2))
	//PITAGORAS
	return(resultado);
	//devuelve resultado
}