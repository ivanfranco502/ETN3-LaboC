/*CONSIGNA
Hacer un programa que implemente una lista doblemente encadenada, donde el
dato contenido en el nodo sea una palabra de hasta 10 caracteres.
Hacer un men£ de cursores, con las siguientes opciones:
	Agregar Nodo
	Eliminar Nodo
	Eliminar Lista (de manera recursiva)
	Mostrar Lista
	Salir

NOTA: Se deber n respetar las condiciones del pr ctico anterior respecto
al ingreso ordenado y la representaci¢n gr fica.
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <string.h>

typedef struct Nod {
	char dato[10];
	struct Nod *sig;
	struct Nod *ant;
}NODO;

void AgregarNodo(NODO **,char *);
void MostrarLista(NODO *);
int EliminarNodo(NODO **,char *);
void EliminarLista(NODO **);

void main(void){

int drv=DETECT,mdo;
char opc;
int intopc=1;
char *palabra=malloc(sizeof(char)*10);
NODO *primero=NULL;

initgraph(&drv,&mdo,"C:\\BC\\BGI");
	do{
		cleardevice();//borra la pantalla
		outtextxy(50,4,"MENU");
		outtextxy(70,35,"Agregar Nodo");
		outtextxy(70,65,"Eliminar Nodo");
		outtextxy(70,95,"Eliminar Lista");
		outtextxy(70,125,"Mostrar Lista");
		outtextxy(70,155,"Salir");
		do{
			do{
			}while(!kbhit());
			opc=getch();
			switch(opc){
				case 'H':
				   intopc--;
				   if (intopc==0){
						intopc=5;
				   }
				   break;
				case 'P':
					intopc++;
					if (intopc==6){
						intopc=1;
					}
					break;
			}
			switch(intopc){
				case 1:
					setcolor(BLACK);
					rectangle(40,50,220,80);
					rectangle(40,140,220,170);
					setcolor(WHITE);
					rectangle(40,30,220,60);
					break;
				case 2:
					setcolor(BLACK);
					rectangle(40,30,220,60);
					rectangle(40,80,220,110);
					setcolor(WHITE);
					rectangle(40,50,220,80);
					break;
				case 3:
					setcolor(BLACK);
					rectangle(40,50,220,80);
					rectangle(40,110,220,140);
					setcolor(WHITE);
					rectangle(40,80,220,110);
					break;
				case 4:
					setcolor(BLACK);
					rectangle(40,80,220,110);
					rectangle(40,140,220,170);
					setcolor(WHITE);
					rectangle(40,110,220,140);
					break;
				case 5:
					setcolor(BLACK);
					rectangle(40,110,220,140);
					rectangle(40,30,220,60);
					setcolor(WHITE);
					rectangle(40,140,220,170);
					break;
			}
		}while(opc!=13);
		if (opc==13){
			switch(intopc){
				case 1:
					cleardevice();
					outtextxy(0,0,"Ingrese una palabra de menos de 10 caracteres: ");
					outtextxy(0,10,"");
					gets(palabra);
					AgregarNodo(&primero,palabra);
					outtextxy(0,50,"Agregado el Nodo correctamente");
					outtextxy(0,60,"Presione Enter para continuar");
					getch();
					break;
				case 2:
					 cleardevice();
					 outtextxy(0,0,"Ingrese el nodo a borrar");
					 gets(palabra);
					 if (EliminarNodo(&primero,palabra)==0){
						cleardevice();
						outtextxy(0,0,"El nodo no pudo ser borrado");
						getch();
					 }else{
						cleardevice();
						outtextxy(0,0,"Se ha borrado el nodo");
						getch();
					 }
					break;
				case 3:
					cleardevice();
					EliminarLista(&primero);
					outtextxy(0,0,"Se ha borrado la lista");
					getch();
					break;
				case 4:
					cleardevice();
					if(primero==NULL){
						outtextxy(0,0,"Para mostrar la lista debe agregar algun nodo");
						outtextxy(0,10,"Presione Enter para continuar");
					}else{
						MostrarLista(primero);
					}
					getch();
					break;
			}
		}
	}while(intopc!=5);
closegraph();
}
void AgregarNodo(NODO **pri,char *pal){

	NODO *nuevo, *aux,*aux2;
	aux= *pri;
	aux2=aux->sig;
	nuevo=malloc(sizeof(NODO));
	if (nuevo!=NULL){
		strcpy(nuevo->dato,pal);
		nuevo->sig=NULL;
		nuevo->ant=NULL;
		if (aux==NULL){ //1ø NODO
			*pri=nuevo;
		}else{
			if (strcmp(nuevo->dato,aux->dato)<0){
				nuevo->sig=aux;
				*pri=nuevo;
				nuevo->ant=NULL;
				aux->ant=nuevo;
			}else{
				while  (!(((strcmp(nuevo->dato,aux2->dato)<=0)&&(strcmp(nuevo->dato,aux->dato)>=0)||(aux2==NULL && aux->sig==NULL)))){
				//while (!((nuevo->dato<=aux2->dato&&nuevo->dato>=aux->dato)||(aux2==NULL && aux->sig==NULL))){
					aux=aux->sig;
					aux2=aux->sig;
				}
				nuevo->sig=aux2;
				aux2->ant=nuevo;
				aux->sig=nuevo;
				nuevo->ant=aux;
			}
		}
	}
}
void EliminarLista(NODO **pri){

NODO *aux;

	if(*pri!=NULL){
		aux=*pri;
		*pri=aux->sig;
		free(aux);
		EliminarLista(pri);
	}
}

int EliminarNodo(NODO **pri,char *pal){

NODO *aux,*aux2,*aux3;
int elimina=0;

	 aux=*pri;
	 if (aux==NULL){
		elimina=0;
	 }else{
	  aux2=aux->sig;
	  if(strcmp(aux->dato,pal)==0){
		 aux3=aux;
		 aux=aux2;
		 *pri=aux;
		 aux2->ant=NULL;
		 aux2=aux->sig;
		 free(aux3);
		 elimina=1;
	  }else{
			while(!((strcmp(aux->dato,pal)==0) || (aux->sig==NULL))){
			   aux=aux->sig;
			   //aux2=aux2->sig;
			}
			if ((strcmp(aux->dato,pal)==0)){
			   aux2=aux->sig;
			   aux3=aux->ant;
			   aux3->sig=aux2;
			   aux2->ant=aux3;
			   free(aux);
			   elimina=1;
			}else{
			   elimina=0;
			}
	  }
	 }
return(elimina);
}

void MostrarLista(NODO *pri){
	NODO *aux=pri;
	int x=0,y=0;
	cleardevice();
	while (aux!=NULL){
		setcolor(RED);
		if(x!=0){
			setlinestyle(SOLID_LINE,1,3);
			line(x,y+10,x-9,y+10);
		}else{
			if(y!=0){
				setlinestyle(SOLID_LINE,1,3);
				line(0,y-2,x+510,y-17);
			}
		}
		setcolor(WHITE);
		setlinestyle(SOLID_LINE,1,1);
		rectangle(x,y,x+120,y+20);
		outtextxy(x+10,y+10,aux->dato);
		if (x+120<480){
			x+=130;
		}else{
			x=0;
			y+=40;
		}
		aux=aux->sig;
	}
}
