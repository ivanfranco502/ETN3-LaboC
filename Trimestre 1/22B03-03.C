#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <dos.h>

/* CONSIGNA
Hacer un programa que permita cargar 2 matrices
de n x m, entera, con valores generados al azar
entre -999 y 999, mostrarlas en forma de matriz
y sumarlas elemento a elemento, indicando los
elementos que se est n sumando en un color
diferente al de la matriz e imprimiendo el
resultado, tambi‚n en forma de matriz. Darle un
tiempo entre cada operaci¢n utilizando la funci¢n
"delay(50)" que pertenece a la biblioteca "dos.h".
Las matrices deben estar declaradas como punteros.
*/
int **crearMatriz(int,int);
void cargaMatriz(int **, int, int);
void imprimeMatriz(int **,int,int,int **);
void imprimeSumaMatriz(int **,int, int,int **);

void main(void){
	int **matriz1; //matriz 1
	int **matriz2; //matriz 2
	int fila=0,columna=0;
	randomize();//funcion random
	clrscr(); //borra pantalla
	cprintf("Ingrese el numero de filas: ");
	scanf("%i",&fila);//cant de filas
	cprintf("Ingresa el numero de columnas: ");
	scanf("%i%",&columna);//cant de columnas
	//se crean las dos matrices
	matriz1 = crearMatriz(fila,columna);
	matriz2 = crearMatriz(fila,columna);
	//se cargan las dos matrices
	cargaMatriz(matriz1,fila,columna);
	cargaMatriz(matriz2,fila,columna);
	//se imprimen las dos matrices
	imprimeMatriz(matriz1,fila,columna, matriz2);
	getch();
	//imprime la suma de las dos matrices
	imprimeSumaMatriz (matriz1,fila,columna,matriz2);
	getch();
	}
int **crearMatriz (int fila, int columna){
//crea la matriz
	int x;
	int **m= malloc (sizeof (int *) * fila);
	//verifica espacio en vector de vectores
	for (x=0;x<fila;x++){
		m[x]= malloc(sizeof (int) * columna);
		//verifica espacio en vector
	}
return(m);
}
void cargaMatriz(int **matriz,int f,int c){
//carga la matriz
	int fila,columna;
	for (fila=0;fila<f;fila++){
		for(columna=0;columna<c;columna++){
			matriz[fila][columna]=NULL;
			//borra el contenido que la matriz puede tener
		}
	}
	for (fila=0;fila<f;fila++){
		for(columna=0;columna<c;columna++){
			matriz[fila][columna]=random(1999)-999;
			//se llena la matriz con numeros entre -999 y 999
		}
	}
}
void imprimeSumaMatriz(int **matriz1, int f, int c, int **matriz2){
//funcion que imprime la suma de las dos matrices
	int fila,columna,x=1, y=4;
		for(fila=0;fila < f;fila++){
			y+=1;x=1;
			for(columna=0;columna<c;columna++){
				x+=7;
				gotoxy(x,y);

				textcolor(1);
				cprintf("[%i]",matriz1[fila][columna]);
				gotoxy(x+20,y);
				cprintf("[%i]",matriz2[fila][columna]);
				delay(500);

				textcolor(7);
				gotoxy(x,y);
				cprintf("[%i]",matriz1[fila][columna]);
				gotoxy(x+20,y);
				cprintf("[%i]",matriz2[fila][columna]);

				gotoxy(x,y+10);
				cprintf("[%i]",(matriz1[fila][columna])+(matriz2[fila][columna]));
			}
		}
}
void imprimeMatriz (int **matriz, int f, int c,int **matriz2){
//funcion que imprime las dos matrices
	int fila, columna,x=1,y=4;
		for (fila=0;fila<f;fila++){
			y+=1;
			x=1;
			for(columna=0;columna<c;columna++){
				x+=7;
				gotoxy(x,y);
				printf("[%i]",matriz[fila][columna]);
				gotoxy(x+20,y);
				printf("[%i]",matriz2[fila][columna]);

			}
		}
}
