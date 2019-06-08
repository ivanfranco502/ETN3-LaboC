/*
--------------------------------------------------------------------------------
Evaluaci¢n de Laboratorio II - Listas

--------------------------------------------------------------------------------
Apellido/s, Nombre/s: Franco Iv n
N§ de Cuenta: 22b03
--------------------------------------------------------------------------------

Enunciado:

hacer un programa que permita crear una lista simplemente encadenada
con los elementos de cada uno de los niveles de un tri ngulo de Tartaglia,
desarrollando una funci¢n recursiva que permita el c lculo de los elementos.


							1
						1		1
					1		2		1
				1		3		3		1
			1		4		6		4		1
		1		5		10	    10   	5		1


Se sabe que el primer nivel siempre es 1 y tiene un elemento, el segundo
tiene 2 elementos, y desde el tercer nivel hasta el £ltimo nivel
(indicado por el usuario) tiene en sus extremos unos y la suma de izquierda
a derecha de los elementos del nivel anterior.

--------------------------------------------------------------------------------
Notas: Es requerimiento para la aprobaci¢n:

- Hacer la funci¢n recursiva que genere cada nodo de la lista, de cada uno
de los niveles, teniendo en cuenta que solo existe una lista, y que ‚sta
contiene los datos del nivel a calcular.

- Hacer una funci¢n que permita mostrar la lista.

- Mostrar cada uno de los niveles calculados.

- Guardar el archivo con el nombre 22bXX21.c
--------------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

typedef struct Nod{
	int num;
	struct Nod *sig;
}NODO;

void Lista (NODO **,int);
void MostrarLista(NODO **,int,int);

void main(void){
	NODO *pri;
	int niveles=0;
	do{
		clrscr();
		printf("Cantidad de niveles del tri ngulo de Tartaglia: ");
		scanf("%i",&niveles);
	}while(niveles<1);
	Lista(&pri,niveles);
}
void Lista(NODO **pri,int niv){
	NODO *aux,*aux2;
	NODO *a;
	int suma,fila=1;
    clrscr();
	do{
		aux=*pri;
		aux2=aux->sig;
		aux->sig=aux2;
		a->num=NULL;
		a->sig=NULL;
			switch (fila){
				case 1:
					a->num=1;
					a->sig=NULL;
					*pri=a;
					MostrarLista(&pri,niv,1);
					break;
				case 2:
					aux2->num=1;
					aux2->sig=NULL;
					MostrarLista(&pri,niv,2);
					break;
				default:
					while(aux2!=NULL && aux->sig!=NULL){
						suma=0;
						suma=(aux->num)+(aux2->num);
						a->num=suma;
						a->sig=aux2;
						aux->sig=a;
						aux=a->sig;
						aux2=aux->sig;
					}
					aux=*pri;
					aux2=aux->sig;
					suma=0;
					do{
						suma++;
						aux=aux2;
						aux2=aux->sig;
					}while(aux!=NULL);
					suma=ceil(suma/2);
/*					do{

					}while();*/
					break;
			}
		fila++;
	}while(fila<=niv);
}
void MostrarLista(NODO **pri,int niv,int y){
	NODO *aux;
	int x=0;
	aux=*pri;
	while(aux!=NULL && aux->sig!=NULL){
		gotoxy(x+3,y);
		printf("%i",aux->num);
		aux=aux->sig;
		x++;
	}
	getch();
}