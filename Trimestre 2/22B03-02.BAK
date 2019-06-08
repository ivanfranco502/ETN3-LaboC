/*CONSIGNA
Tomando como base el ejemplo de listas visto en teor¡a
-Hacer un programa que permita el ingreso de caracteres en una lista
simplemente encadenada de manera que dicho ingreso sea ordenado de menor
a mayor.
-Mostrar la lista de manera gr fica cada nodo y su enlace.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>

typedef struct Nod {
	unsigned char dato;
	struct Nod *sig;
}NODO;

void agregarNodo (NODO **, char);
void mostrarLista (NODO *);

void main(void){
	unsigned char a;
	NODO *primero=NULL;
	int drv=DETECT,mdo;
	clrscr();
initgraph(&drv,&mdo,"C:\\BC\\BGI");
	do{
		a=getch();
		if(a!=13){
			agregarNodo(&primero,a);
			mostrarLista(primero);
		}
	}while (a!=13);
//	mostrarLista(primero);
	getch();
closegraph();
}

void agregarNodo (NODO **pri, char d){
	NODO *nuevo, *aux,*aux2;
	aux= *pri;
	aux2=aux->sig;
	nuevo=malloc(sizeof(NODO));
	if (nuevo!=NULL){
		nuevo->dato=d;
		nuevo->sig=NULL;
		if (aux==NULL){ //1ø NODO
			*pri=nuevo;
		}else{
			if (nuevo->dato<aux->dato){
				nuevo->sig=aux;
				*pri=nuevo;
			}else{
				while (!((nuevo->dato<=aux2->dato&&nuevo->dato>=aux->dato)||(aux2==NULL && aux->sig==NULL))){
					aux=aux->sig;
					aux2=aux->sig;
				}
				nuevo->sig=aux2;
				aux->sig=nuevo;
			}
		}
	}
}

void mostrarLista (NODO *pri){
	NODO *aux=pri;
	int x=0,y=0;
	char dato[2];
	cleardevice();
	while (aux!=NULL){
		dato[0]=aux->dato;
		dato[1]=NULL;
		setcolor(RED);
		if(x!=0){
		setlinestyle(SOLID_LINE,1,3);
		line(x-9,y+10,x,y+10);
		}else{
			if(y!=0){
			setlinestyle(SOLID_LINE,1,3);
			line(x-620,y+16,x+620,y-18);
			}
		}
		setcolor(WHITE);
		setlinestyle(SOLID_LINE,1,1);
		rectangle(x,y,x+20,y+20);
		outtextxy(x+10,y+10,dato);
		if (x+40<640){
		x+=30;
		}else{
		x=0;
		y+=40;
		};
//		printf("[%p-%c-%p]-->\n",aux,aux->dato,aux->sig);
		aux=aux->sig;
	}
}