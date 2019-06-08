/*CONSIGNA
Hacer un programa que permita generar una matriz de NxM y que al azar
cargue valores 0 (ceros) y 1 (unos). Esos valores van a representar camino
para el cero y paredes para el uno. El programa debera encontrar todas las
salidas del laberinto, teniendo como condicion que siempre la entrada
esta en la primera fila y que la salida esta en la ultima fila.
Para resolverlo es necesario utilizar una funcion recursiva.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <dos.h>

void buscar (int **,int,int,int,int);//funcion que busca los 0 alrededor
int **crearMatriz(int,int);//funcion para crear matriz
void cargaMatriz(int **, int, int);//funcion para cargar la matriz
void imprimeMatriz(int **,int,int);//funcion que imprime matriz

void main(void){
int **matriz;
int fila=0,columna=0;
int f=0,c=0;
	randomize();//funcion randomize que permite generar numeros al azar
	clrscr();//borra la pantalla
	cprintf("Ingrese el numero de filas: ");
	scanf("%i",&fila);//se toma el valor de cant de filas para la matriz
	cprintf("Ingresa el numero de columnas: ");
	scanf("%i%",&columna);//se toma el valor de cant de col para la matriz
	matriz = crearMatriz(fila,columna);//se crea la matriz con F y C
	cargaMatriz(matriz,fila,columna);//se carga la matriz (0s y 1s)
	imprimeMatriz(matriz,fila,columna);//se imprime la matriz
	//sistema de repeticion que busca 0s en la primera fila
	for (c=0; c<=columna;c++){//fila=0 columna=contador++
		if (matriz[0][c]==0){//si encuentra un 0
			//llama a la funcion buscar 0
			buscar(matriz,fila,columna,f,c);
		}
	}
	getch();
}
void buscar (int **matriz, int fila, int columna,int f,int c){
/*funcion buscar, que tiene como parametros
la matriz, cant de filas, cant de columnas
la fila del cero anterior, la columna del cero anterior
*/
textcolor(4);//color de texto rojo
if (f<fila){//si f del cero es menor a la cant de filas
	if(f>0){//si f del cero es mayor a 0
		/*si arriba del 0 hay un cero
		si lo hay pone ese punto en 9 y vuelve a la funcion
		recursivamente con el nuevo punto para fijarse si
		hay un camino entero*/
		if (matriz[f-1][c]==0){
			matriz[f-1][c]=9;
			buscar(matriz,fila,columna,f-1,c);
			matriz[f-1][c]=0;
			//cuando termina, vuelve al 0 el punto antiguo
			gotoxy(c*4+1,f-1+7);
			cprintf("0");
		}
	}
	//si f de cero es mayor a 0 y c de cero es menor a la cant de col-1
	if(f>0 && c<columna-1){
		/*si arriba a la derecha del 0 hay un cero
		si lo hay pone ese punto en 9 y vuelve a la funcion
		recursivamente con el nuevo punto para fijarse si
		hay un camino entero*/
		if(matriz[f-1][c+1]==0){
			matriz[f-1][c+1]=9;
			buscar(matriz,fila,columna,f-1,c+1);
			matriz[f-1][c+1]=0;

			gotoxy((c+1)*4+1,f-1+7);
			cprintf("0");
		}
	}
	//si c de 0 es menor a cant de c-1
	if (c<columna-1){
		/*si a la derecha del 0 hay un cero
		si lo hay pone ese punto en 9 y vuelve a la funcion
		recursivamente con el nuevo punto para fijarse si
		hay un camino entero*/
		if(matriz[f][c+1]==0){
			matriz[f][c+1]=9;
			buscar(matriz,fila,columna,f,c+1);
			matriz[f][c+1]=0;

			gotoxy((c+1)*4+1,f+7);
			cprintf("0");
		}
	}
	//si f de cero es menor a cant de f-1 Y c de cero es menor a cant de c-1
	if(f<fila-1 && c<columna-1){
		/*si abajo a la derecha del 0 hay un cero
		si lo hay pone ese punto en 9 y vuelve a la funcion
		recursivamente con el nuevo punto para fijarse si
		hay un camino entero*/
		if(matriz[f+1][c+1]==0){
			matriz[f+1][c+1]=9;
			buscar(matriz,fila,columna,f+1,c+1);
			matriz[f+1][c+1]=0;

			gotoxy((c+1)*4+1,f+1+7);
			cprintf("0");
		}
	}
	//si f de cero es menor a cant f-1
	if(f<fila-1){
		/*si abajo del 0 hay un cero
		si lo hay pone ese punto en 9 y vuelve a la funcion
		recursivamente con el nuevo punto para fijarse si
		hay un camino entero*/
		if(matriz[f+1][c]==0){
			matriz[f+1][c]=9;
			buscar(matriz,fila,columna,f+1,c);
			matriz[f+1][c]=0;

			gotoxy(c*4+1,f+1+7);
			cprintf("0");
		}
	}
	//si f de cero es menor a cant f-1 Y c de cero mayor a 0
	if(f<fila-1 && c>0){
		/*si abajo a la izquierda del 0 hay un cero
		si lo hay pone ese punto en 9 y vuelve a la funcion
		recursivamente con el nuevo punto para fijarse si
		hay un camino entero*/
		if(matriz[f+1][c-1]==0){
			matriz[f+1][c-1]=9;
			buscar(matriz,fila,columna,f+1,c-1);
			matriz[f+1][c-1]=0;

			gotoxy((c-1)*4+1,f+1+7);
			cprintf("0");
		}
	}
	//si c de cero es mayor a 0
	if(c>0){
		/*si a la izquierda del 0 hay un cero
		si lo hay pone ese punto en 9 y vuelve a la funcion
		recursivamente con el nuevo punto para fijarse si
		hay un camino entero*/
		if(matriz[f][c-1]==0){
			matriz[f][c-1]=9;
			buscar(matriz,fila,columna,f,c-1);
			matriz[f][c-1]=0;

			gotoxy((c-1)*4+1,f+7);
			cprintf("0");
		}
	}
	//si f de cero es mayor a cero Y c de cero es mayor a 0
	if(f>0 && c>0){
		/*si arriba a la izquierda del 0 hay un cero
		si lo hay pone ese punto en 9 y vuelve a la funcion
		recursivamente con el nuevo punto para fijarse si
		hay un camino entero*/
		if(matriz[f-1][c-1]==0){
			matriz[f-1][c-1]=9;
			buscar(matriz,fila,columna,f-1,c-1);
			matriz[f-1][c-1]=0;

			gotoxy((c-1)*4+1,f-1+7);
			cprintf("0");
		}
	}
}
}
int **crearMatriz (int fila, int columna){//funcion que crea la matriz
//parametros, la cantidad de filas, y la cantidad de columnas
	int x;
	int **m= malloc (sizeof (int *) * fila);
	//busca si hay espacio para el vector de vector
	for (x=0;x<fila;x++){
		m[x]= malloc(sizeof (int) * columna);
		//busca si hay espacia para el vector de cada fila
	}
return(m);//devuelve la matriz
}
void cargaMatriz(int **matriz,int f,int c){//funcion carga matriz
	int fila,columna;
	for (fila=0;fila<f;fila++){//for para fila
		for(columna=0;columna<c;columna++){//for para columna
			matriz[fila][columna]=NULL;//borra todos los elementos de la matriz
		}
	}
	for (fila=0;fila<f;fila++){
		for(columna=0;columna<c;columna++){
			matriz[fila][columna]=random(2);//carga cada lugar con un 1 o 0 al azar
		}
	}
}
void imprimeMatriz (int **matriz, int f, int c){ //funcion imprime matriz
	int indice;
		for (indice=0;indice<f*c;indice++){
			gotoxy(indice%c*4+1,indice/c+7);
			printf("%i",matriz[indice/c][indice%c]);
		}
}