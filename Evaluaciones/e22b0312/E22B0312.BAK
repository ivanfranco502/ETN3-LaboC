/*Evaluación de Laboratorio II - 5ø 2ø C.S.C. - Grupo B
-------------------------------------------------------------------------------------------------
APELLIDO, Nombre/s: Franco, Iv n
-------------------------------------------------------------------------------------------------
Temas de la Evaluación:

Manejo de punteros a Vectores y Matrices.
Ordenamiento y Búsqueda.
Manejo de Funciones recursivas.
-------------------------------------------------------------------------------------------------
Enunciado:

Hacer un programa que almacene en una matriz de 12 x 12  elementos enteros, elegidos al azar
entre dos valores ingresados por el usuario donde pueden existir repetidos, muestre la matriz
generarda inicialmente, la traspuesta y la ordenada.


1) La carga de la matriz debe ser realizada por una función que recibe como parámetros a la
   matriz, y los valores ingresados por el usuario.

2) La función ordenaFR() recibe como parámetro la matriz, debiendo ordenar la matriz aplicando el
   criterio de frecuencia de mayor a menor, que indica que el número más repetido debe ser el
   mayor, y en caso de existir igual cantidad de números para una frecuencia, el mayor será el
   primero.

			   1 2 3 3				1 4 5 8				4 4 4 4
			   4 4 4 5				2 4 6 8 			8 8 8 5
			   5 6 4 1				3 4 4 0				5 3 3 1
			   8 8 0 8				3 5 1 8				1 6 2 0

			   (original)	       (traspuesta)		(ordenada por frecuencia)

3) Hacer una función que permita mostrar la matriz en forma de matriz.

4) Una función debe mostrar la matriz traspuesta.

5) El programa debe tener un menu que permita la selección de las siguientes opciones:

					1) Cargar Matriz
					2) Mostrar Matriz
					3) Trasponer
					4) Ordenar
					0) Salir

NOTAS:
	- El programa debe salir solo por la opción de salida.
	- Hacer funciones que reciban los parámetros necesarios.
	- La función que traspone la matriz debe ser recursiva.
	- NO HACER UNA MATRIZ DE UNA SOLA FILA O UNA SOLA COLUMNA.
	- Implementar punteros para la creación de la matriz.
	- Crear una carpeta e22bxx12, donde las xx deben ser reemplazadas por el número que le
	corresponda a su cuenta, en la unidad U.
  - Este enunciado debe ser parte del código fuente.
-------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int crearMatriz(int,int);
int ordenaFR(int **);
void cargaMatriz (int **, int, int);
void mostrarMatriz (int **);
void transponer (int **);


void main(void){
	int intOpc,**m;
	int men=0,may=0;
	randomize();
    clrscr();
	**m=crearMatriz(12,12);
	printf("Menor numero: ");
	scanf("%i", &men);
	printf("Mayor numero: ");
	scanf("%i",&may);
	do{
		clrscr();
		printf("MENU\n");
		printf("(1) - CARGAR MATRIZ\n");
		printf("(2) - MOSTRAR MATRIZ\n");
		printf("(3) - TRANSPONER\n");
		printf("(4) - ORDENAR POR FRECUENCIA\n");
		printf("(0) - SALIR\n");
		printf("¨Qu‚ desea hacer? ");
		scanf("%i", &intOpc);
		switch (intOpc){
			case 1:
				cargaMatriz (m, men, may);
				break;
			case 2:
				mostrarMatriz(m);
				break;
			case 3:
//				trasponer(m);
//				getch();
				break;
			case 4:
//				ordenaFR(m);
//				getch();
				break;
		}
	}while(intOpc!=0);
getch();
}

int crearMatriz(int f, int c){
	int **aux,a,b;
	aux=malloc(sizeof(int*)*f);
	for (a=0;a<=c;a++){
		aux=malloc(sizeof(int)*c);
	}
	for(a=0;a<=f;a++){
		for (b=0;b<=c;b++){
			aux[a][b]=NULL;
		}
	}
return(**aux);
}
void cargaMatriz (int **mat,int menor,int mayor){
	int a,b;
	for (a=0;a<=12;a++){
		for(b=0;b<=12;b++){
			mat[a][b]=random(mayor+menor)-menor;
		}
	}
}
void mostrarMatriz (int **mat){
int fila,columna;
clrscr();
	for (fila=0;fila<=12;fila++){
		for(columna=0;columna<=12;columna++){
			gotoxy(columna+10,fila+5);
			printf("%i",mat[fila][columna]);
		}
	}
	getch();
}
/*void transponer (int **mat){

}
int ordenaFR(int **mat){
} */