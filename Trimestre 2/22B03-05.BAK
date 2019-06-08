/*CONSIGNA
Hacer un programa que permita el ingreso de palabras y almacene en una lista
simplemente encadenada de manera ordenada, y ‚sta lista deber  tener su
principio en el  rea de datos de una lista doblemente encadenada que adem s
contenga la primera letra de la palabra, teniendo esta lista que generarse
ordenada.
	Ejemplo:

	________       _____________       _____________       _____________
   |  1000  |-----| NULL | 2000 |-----| 1000 | 3000 |-----| 2000 | NULL |
	--------      |______|______|     |______|______|     |______|______|
	   10         |  A   | 100  |     |  M   |  200 |     |  S   |  300 |
	primero       |______|______|     |______|______|     |______|______|
					  1000	   |			2000   |			3000   |
							   |                   |                   |
							   |                   |                   |
				   ____________|       ____________|       ____________|
				  |	 Argentina  |     |	 Marcela    |     |	  Sandra    |
				  |_____________|     |_____________|	  |_____________|
				  |		NULL	|	  |	   210		|	  |		310     |
				  |_____________|	  |_____________|	  |_____________|
						100					200	   |			300    |
												   |                   |
												   |                   |
									   ____________|       ____________|
									  |	 Mar¡a      |     |	  Sergio    |
									  |_____________|	  |_____________|
									  |	   220		|	  |		NULL    |
									  |_____________|	  |_____________|
											210	   |			310
												   |
												   |
									   ____________|
									  |	   Mario    |
									  |_____________|
									  |		NULL	|
									  |_____________|
											220

Donde el ingreso de datos fue en la siguiente secuencia;

Mar¡a
Argentina
Sergio
Marcela
Sandra
Mario


Deber  contar con un men£ de cursores con las siguientes opciones:
	Agregar Nodo
	Eliminar Nodo
	Eliminar Lista(de manera recursiva)
	Mostrar Lista
	Salir

NOTA: Tener en cuenta que si es eliminada la £nica palabra de la lista, tambi‚n
debe ser eliminado el nodo que contiene la letra.
*/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <string.h>

typedef struct NODP{
	unsigned char Pal[31];
	struct NODP *Sig;
}NODOP;
typedef struct NODL{
	unsigned char Dato;
	struct NODL *Sig;
	struct NODL *Ant;
	NODOP *Pal;
}NODOL;

void AgNodo(NODOL **, char *);
void AgP(NODOP **, char *);
void MostrarLista(NODOL *);
void ElNodo(NODOL **, char *);
void ElLista(NODOL *, NODOP *,int);

void main(void){
	unsigned char *Ingreso=malloc(sizeof(char)*32);
	char Cursor=NULL;
	int Driver=DETECT,Modo, Opcion=1;
	NODOL *Primero=NULL;

	initgraph(&Driver,&Modo,"C:\\BC\\BGI");
	cleardevice();
	do{
		cleardevice();
		outtextxy(10,20,"Agregar NODO");
		outtextxy(10,40,"Eliminar NODO");
		outtextxy(10,60,"Eliminar LISTA");
		outtextxy(10,80,"Mostrar LISTA");
		outtextxy(10,100,"SALIR");
		rectangle(5,20*Opcion,155,20*Opcion+10);
		do{
			do{
			}while(!kbhit());
			Cursor=getch();
			switch(Cursor){
				case 'H':
					Opcion--;
					if(Opcion==0){
						Opcion=5;
					}
					break;
				case 'P':
					Opcion++;
					if(Opcion==6){
						Opcion=1;
					}
			}
			if((Cursor=='H')||(Cursor=='P')){
				cleardevice();
				outtextxy(10,20,"Agregar NODO");
				outtextxy(10,40,"Eliminar NODO");
				outtextxy(10,60,"Eliminar LISTA");
				outtextxy(10,80,"Mostrar LISTA");
				outtextxy(10,100,"SALIR");
				rectangle(5,20*Opcion,155,20*Opcion+10);
			}
		}while(Cursor!=13);
		switch(Opcion){
			case 1:
				cleardevice();
				gotoxy(1,1);
				printf("Ingrese una palabra maximo 30:");
				strset(Ingreso,NULL);
				gets(Ingreso);
				AgNodo(&Primero,Ingreso);
				break;
			case 2:
				cleardevice();
				gotoxy(1,1);
				printf("NODO ELIMINAR: ");
				strset(Ingreso,NULL);
				gets(Ingreso);
				ElNodo(&Primero,Ingreso);
				break;
			case 3:
				ElLista(Primero,NULL,0);
				Primero=NULL;
				break;
			case 4:
				MostrarLista(Primero);
				getch();
				break;
			case 5:
				ElLista(Primero,NULL,0);
				Primero=NULL;
		}
	}while(Opcion!=5);
	closegraph();
}
void AgNodo(NODOL **Pri, char *Ing){
	NODOL *NuevoL,*AuxL1,*AuxL2;
	NODOP *NuevoP;
	AuxL1=*Pri;
	AuxL2=AuxL1->Sig;
	while(!((Ing[0]==AuxL1->Dato)||(AuxL1==NULL))){
		AuxL1=AuxL1->Sig;
	}
	if((AuxL1!=NULL)&&(Ing[0]==AuxL1->Dato)){
		AgP(&AuxL1->Pal,Ing);
	}else{
		AuxL1=*Pri;
		NuevoL=malloc(sizeof(NODOL));
		NuevoP=malloc(sizeof(NODOP));
		if(NuevoL!=NULL){
			NuevoL->Dato=Ing[0];
				NuevoL->Pal=NULL;
			if(AuxL1==NULL){
				if(NuevoP!=NULL){
					*Pri=NuevoL;
					NuevoL->Sig=NULL;
					NuevoL->Ant=NULL;
					strcpy(NuevoP->Pal,Ing);
					NuevoL->Pal=NuevoP;
					NuevoP->Sig=NULL;
				}
			}else{
				if(NuevoL->Dato<AuxL1->Dato){
					NuevoL->Sig=AuxL1;
					AuxL1->Ant=NuevoL;
					*Pri=NuevoL;
					NuevoL->Ant=NULL;
					AgP(&NuevoL->Pal,Ing);
				}else{
					while(!(((NuevoL->Dato<=AuxL2->Dato)&&(NuevoL->Dato>=AuxL1->Dato))||((AuxL1->Sig==NULL)&&(AuxL2==NULL)))){
						AuxL1=AuxL1->Sig;
						AuxL2=AuxL1->Sig;
					}
					NuevoL->Sig=AuxL2;
					NuevoL->Ant=AuxL1;
					AuxL1->Sig=NuevoL;
					AuxL2->Ant=NuevoL;
					AgP(&NuevoL->Pal,Ing);
				}
			}
		}
	}
}
void MostrarLista(NODOL *Pri){
	NODOL *AuxL=Pri;
	NODOP *AuxP;
	char *Aux=malloc(sizeof(char)*31);
	int x=0,y;
	cleardevice();
	while(AuxL!=NULL){
		y=1;
		setcolor(GREEN);
		rectangle(x*125,0,x*125+100,20);
		setcolor(WHITE);
		if(x!=0){
			line((x-1)*100+100,20,x*100,20);
		}
		Aux[0]=AuxL->Dato;
		Aux[1]=NULL;
		outtextxy(x*125+12,5,Aux);

		AuxP=AuxL->Pal;
		while(AuxP!=NULL){
			setcolor(GREEN);
			rectangle(x*125,y*100,x*125+100,y*100+20);

			setcolor(WHITE);
			if(y!=0){
				line(x*125+50,y*100-80,x*125+50,y*100);
			}
			strset(Aux,NULL);
			sprintf(Aux,"%s",AuxP->Pal);
			outtextxy(x*125+12,y*100+10,Aux);

			y++;
			AuxP=AuxP->Sig;
		}
		x++;
		AuxL=AuxL->Sig;
	}
}



void ElLista(NODOL *PriL, NODOP *PriP,int Mdo){
	NODOP *AuxP;
	if(PriL!=NULL){
		if(Mdo==0){
			if(PriL->Sig!=NULL){
				ElLista(PriL->Sig,PriP,Mdo);
			}
			AuxP=PriL->Pal;
			ElLista(PriL,AuxP,1);
			free(PriL);
		}else{
			if(PriP->Sig!=NULL){
				ElLista(PriL,PriP->Sig,Mdo);
			}
		free(PriP);
		}
	}
}
void ElNodo(NODOL **Pri,char *Ing){
	NODOL *AuxL,*AntL,*SigL;
	NODOP *AuxP,*AntP;
	AuxL=*Pri;
	while(!((Ing[0]==AuxL->Dato)||(AuxL==NULL))){
		AuxL=AuxL->Sig;
	}
	if(AuxL==NULL){
		cleardevice();
		outtextxy(1,1,"El NODO no esta");
	}else{
		AuxP=AuxL->Pal;
		if((strcmp(AuxP->Pal,Ing)==0)){
			if (AuxP->Sig==NULL){
				if(AuxL->Ant==NULL){
					SigL=AuxL->Sig;
					*Pri=SigL;
					SigL->Ant=NULL;
				}else{
					AntL=AuxL->Ant;
					SigL=AuxL->Sig;
					AntL->Sig=SigL;
					if(SigL!=NULL){
						SigL->Ant=AntL;
					}
					free(AuxL);
					free(AuxP);
				}
			}else{
				AuxL->Pal=AuxP->Sig;
				free(AuxP);
			}
		}else{
			AntP=AuxP;
			AuxP=AuxP->Sig;
			while(!(((strcmp(AuxP->Pal,Ing)==0)||(AuxP==NULL)))){
				AntP=AuxP;
				AuxP=AuxP->Sig;
			}
			if(AuxP!=NULL){
				if(AuxP->Sig==NULL){
					AntP->Sig=NULL;
					free(AuxP);
				}else{
					AntP->Sig=AuxP->Sig;
					free(AuxP);
				}
			}else{
				cleardevice();
				outtextxy(1,1,"EL NODO NO EXISTE");
			}
		}
	}
}
void AgP(NODOP **PriP, char *Ing){
	NODOP *NuevoP,*AuxP1,*AuxP2;
	AuxP1=*PriP;
	AuxP2=AuxP1->Sig;
	NuevoP=malloc(sizeof(NODOP));
	if(NuevoP!=NULL){
		strcpy(NuevoP->Pal,Ing);
		if(AuxP1==NULL){
			*PriP=NuevoP;
			NuevoP->Sig=NULL;
		}else{
			if(strcmp(NuevoP->Pal,AuxP1->Pal)<0){
				NuevoP->Sig=AuxP1;
				*PriP=NuevoP;
			}else{
				while(!(((strcmp(NuevoP->Pal,AuxP2->Pal)<=0)&&(strcmp(NuevoP->Pal,AuxP1->Pal)>=0))||((AuxP1->Sig==NULL)&&(AuxP2==NULL)))){
					AuxP1=AuxP1->Sig;
					AuxP2=AuxP1->Sig;
				}
				NuevoP->Sig=AuxP2;
				AuxP1->Sig=NuevoP;
			}
		}
	}
}

