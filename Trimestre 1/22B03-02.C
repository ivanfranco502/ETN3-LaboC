#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <dos.h>

/* CONSIGNA:
Hacer un programa que permita cargar una matriz
entera de 5 filas por 5 columnas de manera que
el usuario indique dos valores enteros para el
rango de los n£meros a generar al azar, y un valor
que indica si pueden o no estar repetidos. El
programa debe tener una funci¢n con el prototipo
"void cargaMatriz (int [][], int, int, int);"
para cargar la matriz y otra funci¢n
"void imprimeMatriz (int [][]);"
que se encarga de imprimir la matriz.
Validar los ingresos. La matriz debe ser declarada
como puntero.
*/

int **crearMatriz(void);//funcion que crea la matriz
void cargaMatriz(int **,int,int,int);//funcion que carga la matriz
void imprimeMatriz(int **);//funcion que imprime la matriz
int boolEsta(int **,int);//funcion booleana para revisar si esta el numero

void main(void){
	int valormin=0, valormax=0, dif=0;
	char rep=0;
	int **matriz; //matriz o vector con doble puntero
	randomize();//funcion random
	clrscr();//borra pantalla
	matriz = crearMatriz();  //llama a la funcion crear matriz
	printf ("Repetici¢n n£meros (1-NO/0-SI): ");//pregunta si numeros se repiten
	scanf ("%i",&rep);
	getch();
		if (rep!=0){//si rep es distinto entonces no se puede repetir
			do{//se hace un do para asegurar diferencia de min y max
				clrscr();
				printf("Repetici¢n n£meros (1-NO/0-SI): %i", rep);
				printf("\n");
				printf("Valor MINIMO: ");
				scanf ("%i",&valormin);
				printf("Valor MAXIMO: ");
				scanf ("%i",&valormax);
				dif=valormax-valormin;
			}while (dif<25);
		}else{
			printf("Valor MINIMO: ");
			scanf ("%i",&valormin);
			printf("Valor MAXIMO: ");
			scanf ("%i",&valormax);
		}
	cargaMatriz(matriz, valormin,valormax,rep);
	//se le pasa la matriz, min y max y si se repite o no
	getch();
	imprimeMatriz(matriz);
	//se imprime la matriz
	getch();
	}
int **crearMatriz (void){
//se crea la matriz
	int x;
	int **m= malloc (sizeof (int *) * 4);
	//busca si hay lugar para filas
	for (x=0;x<5;x++){
		m[x]= malloc(sizeof (int) * 4);
	//busca si hay lugar para columnas
	}
return(m);
//devuelve la matriz
}
void cargaMatriz(int **matriz,int min,int max,int rep){
//funcion que carga la matriz
	int fila,columna;
	for (fila=0;fila<5;fila++){
		for(columna=0;columna<5;columna++){
			matriz[fila][columna]=NULL;
		//se borra todo lo que este dentro de la matriz
		}
	}
	if (rep==0){
	//si repeticion es SI entonces
		for (fila=0;fila<5;fila++){
			for(columna=0;columna<5;columna++){
				matriz[fila][columna]=random(max-min)+min;
				//se le carga a la matriz con un random sin verificar
				//si se repiten
			}
		}
	}else{
	//si repeticion es NO entonces
		int aux;
		for(fila=0; fila<5; fila++){
			for(columna=0; columna <5;columna++){
				do{
					aux=random(max-min)+min;
					//se generan numeros al azar
				}while(boolEsta(matriz,aux)==1);
				//mientras el numero generado este en la matriz se hace el do
				matriz[fila][columna]=aux;
				//al no encontrarse en la matriz, se lo agrega en la ultima
				//fila y columna sin llenar
			}
		}
	}
}
int boolEsta(int **matriz, int aux){
//funcion que verifica si un numero ya se encuentra en la matriz
int fila=0, columna=0,resultado=0;
   for(fila=0;fila<5 && resultado !=1;fila++){
		for(columna=0;columna<5 && resultado !=1;columna++){
			if (aux==matriz[fila][columna]){
			//si el numero esta en la posicion del for entonces
				resultado=1;
			//resultado es SI ESTA y se sale del for indicando que esta rep
			}
		}
   }
	if (resultado==1){
		return(1);
	}else{
		return(0);
	}
}
void imprimeMatriz (int **matriz){
//funcion que imprime la matriz creada
	int fila, columna,x,y;
		for (fila=0;fila<5;fila++){
			for(columna=0;columna<5;columna++){
				gotoxy((fila*5)+1,columna+10);
				//se imprime en el espacio de la pantalla del gotoxy
				printf("[%i]",matriz[fila][columna]);
				//se imprime el numero dentro de corchetes
			}
		}
}