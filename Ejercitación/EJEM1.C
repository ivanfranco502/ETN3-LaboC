#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int suma (int, int); //funcion de suma recibe dos numeros enteros
int resta (int, int); //funcion de resta recibe dos numeros enteros
int multi (int, int); //funcion de multiplicacion recibe dos numeros enteros
float divi (int, int); //funcion de division recibe dos numeros enteros
int poten (int, int); // funcion de potencia recibe dos numeros enteros
void main(void) {
	int a,b;
	clrscr(); //borra la pantalla
		printf("A:");
		scanf("%i", &a); //toma el valor de A (primer valor)

		printf("B:");
		scanf("%i",&b); //toma el valor de B (segundo valor)
		/*muestra el resultado de la suma y
		llama a la funcion suma
		a la cual le suma los parametros*/
		printf("El resultado de suma %i con %i es %i", a, b, suma(a,b));
		/*muestra el resultado de la suma y
		llama a la funcion suma
		a la cual le suma los parametros*/
		printf("\n");
		printf("El resultado de resta %i con %i es %i", a,b,resta(a,b));
		/*muestra el resultado de la resta y
		llama a la funcion resta
		a la cual le suma los parametros*/
		printf("\n");
		/*muestra el resultado de la multiplicacion y
		llama a la funcion multiplicacion
		a la cual le suma los parametros*/
		printf("El resultado de multiplicación %i con %i es %i", a,b,multi(a,b));
		printf("\n");
		if(b==0){ //si b(denominador) es igual a 0
			printf("La división por 0 no está definida");
		}else{
		/*muestra el resultado de la division y
		llama a la funcion division
		a la cual le suma los parametros*/
			printf("El resultado de división %i con %i es %.3f", a,b, divi(a,b));
		}
		printf("\n");
		/*muestra el resultado de la potencia y
		llama a la funcion potencia
		a la cual le suma los parametros*/
		printf("El resultado de potencia %i con %i es %i", a, b, poten(a,b));

		getch();//espera a que el usuario toque algo para salir del programa
}
int suma(int x, int y){ //suma toma dos valores
	return(x+y); //se devuelve la suma de los dos valores
}
int resta(int x, int y){ //resta toma dos valores
	return (x-y); //se devuelve la resta de los dos valores
}
int multi(int x, int y){ //multiplicacion toma dos valores
	return (x*y); //se devuelve la multiplicacion de los dos valores
}
float divi (int x, int y){ //division toma dos valores
	return (x/(float)y); /* se devuelve la division de los dos valores
donde el y se hace float para poder alvergar un resultado en decimal*/
}
int poten (int x, int y){ //potencia toma dos valores
	char indice; //se define el indice para el for
	int resultado; //se define resultado que guarda
		resultado=1; //resultado es igual a 1
		for(indice=0;indice<y;indice++){ /*for con varios numeros
		indice arranca en 0
		el for se mantiene corriendo mientras sea menor que y(segundo valor)
		luego de ejecutarse el for se va sumando uno por pasada a indice*/
			resultado=resultado*x; //resultado es multiplicado por x(primer valor)
		}
	return (resultado); //se devuelve la potencia de los dos valores
}