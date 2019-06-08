/*CONSIGNA
Hacer un programa que permita cargar al azar con cero y unos, una matriz
cuyo tama¤o debe ser indicado por el usuario, y mediante una funci¢n
recursiva, buscar el mayor  rea compuesta por ceros, armando una lista
donde cada nodo, en el  rea de datos, deber  almacenar las coordenadas
de la soluci¢n obtenida. Y devuelve la cantidad de elementos que componen
dicha  rea.

NOTAS:
	1.La representaci¢n debe ser gr fica donde los cero deben ser rect ngulos
	pintados de BLANCO y los unos rect ngulos pintados de NEGRO.
	2.Un  rea es un conjunto de casillas BLANCAS adyacentes, delimitadas
	por casillas NEGRAS o por los l¡mites del tablero.
	3.Hacer un men£ que se maneje con los cursores, que tenga las siguientes
	opciones:
		Generar Tablero
		Guardar Tablero
		Cargar Tablero
		Mostrar Soluci¢n
		Mostrar Lista
		Salir
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <time.h>
#include <dos.h>

typedef struct Nod {
	int fila;
	int columna;
	struct Nod *sig;
}NODO;

void agregarNodo (NODO **, int,int);
void mostrarLista (NODO *);
int **crearMatriz(int,int);//funcion para crear matriz
void cargaMatriz(int **, int, int);//funcion para cargar la matriz
void imprimeMatriz(int **,int,int);//funcion que imprime matriz
void guardarMatriz(int,int,int **);
void abrirMatriz(int,int,int **);
void buscarCero(int **, int, int, NODO **);
void buscar(int **, int, int, int, int,int *);
void pintar(int**, int,int,int,int,NODO **);


void main(void){
	int **matriz;
	int fila=0,columna=0;
	int intopc=1;
	char opc;
	NODO *pri=NULL;
	int drv=DETECT, mdo;

	randomize();//funcion randomize que permite generar numeros al azar
	initgraph(&drv,&mdo,"C:\\BC\\BGI");
	do{
		cleardevice();//borra la pantalla
		outtextxy(50,4,"MENU");
		outtextxy(70,35,"Generar Tablero");
		outtextxy(70,65,"Guardar Tablero");
		outtextxy(70,95,"Cargar Tablero");
		outtextxy(70,125,"Mostrar Solucion");
		outtextxy(70,155,"Mostrar Lista");
		outtextxy(70,185,"Salir");
		do{
			do{
			}while(!kbhit());
			opc=getch();
			switch(opc){
				case 'H':
				   intopc--;
				   if (intopc==0){
						intopc=6;
				   }
				   break;
				case 'P':
					intopc++;
					if (intopc==7){
						intopc=1;
					}
					break;
			}
			switch(intopc){
				case 1:
					setcolor(BLACK);
					rectangle(40,50,220,80);
					rectangle(40,170,220,200);
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
					rectangle(40,170,220,200);
					setcolor(WHITE);
					rectangle(40,140,220,170);
					break;
				case 6:
					setcolor(BLACK);
					rectangle(40,140,220,170);
					rectangle(40,30,220,60);
					setcolor(WHITE);
					rectangle(40,170,220,200);
					break;
			}
		}while(opc!=13);
		if (opc==13){
			switch(intopc){
				case 1:
					cleardevice();
					outtextxy(0,0,"Ingrese el numero de filas: ");
					printf("\n");
					scanf("%i",&fila);//se toma el valor de cant de filas para la matriz
					outtextxy(0,10,"Ingresa el numero de columnas: ");
					printf("\n");
					scanf("%i%",&columna);//se toma el valor de cant de col para la matriz
					matriz = crearMatriz(fila,columna);//se crea la matriz con F y C
					cleardevice();
					if (fila==0 && columna==0){
						outtextxy(0,40,"No hay suficiente memoria. Lo lamentamos");
						outtextxy(0,50,"Pulse enter para finalizar.");
						getch();
					}else{
						outtextxy(0,40,"La matriz ha sido creada correctamente\n");
						outtextxy(0,50,"Pulse enter para cargarla.");
						getch();
						cargaMatriz(matriz,fila,columna);//se carga la matriz (0s y 1s)
						cleardevice();
						outtextxy(0,60,"Cargada la matriz correctamente\n");
						outtextxy(0,70,"Pulse Enter para continuar");
						getch();
					}
					break;
				case 2:
					cleardevice();
					guardarMatriz(fila,columna,matriz);
					outtextxy(0,10,"Guardada la matriz correctamente");
					outtextxy(0,20,"Pulse Enter para continuar");
					getch();
					break;
				case 3:
					cleardevice();
					abrirMatriz(fila,columna,matriz);
					outtextxy(0,10,"Cargada la matriz correctamente");
					outtextxy(0,20,"Pulse Enter para continuar");
					break;
				case 4:
					if(fila!=0 && columna!=0){
						cleardevice();
						imprimeMatriz(matriz,fila,columna);//se imprime la matriz
						buscarCero(matriz, fila, columna,&pri);
						outtextxy(0,450,"Pulse Enter para continuar");
						getch();
					}else{
						cleardevice();
						outtextxy(0,0,"Debe generar la matriz antes de poder verla");
						getch();
					}
					break;
				case 5:
					cleardevice();
					mostrarLista(pri);
					getch();
					break;
			}
		}
	}while(intopc!=6);
		closegraph();
}
void abrirMatriz(int fila,int columna, int **matriz){

int x,y;
char *linea;

FILE *pf=fopen("U:\\tablero.txt","rt");
	fscanf(pf,"%i",&fila);
	fscanf(pf,"%i",&columna);
	linea=malloc(sizeof(char)*columna+1);
	for(x=0;x<=columna;x++){
		linea[x]=NULL;
	}
	for(x=0;x<fila;x++){
		fscanf(pf,"%s",linea);
		for(y=0;y<columna;y++){
			matriz[x][y]=linea[y]-48;
		}
	}
fclose(pf);
}
void guardarMatriz(int fila, int columna, int **matriz){

	int x,y;
	char *linea;

	FILE *pf=fopen("U:\\tablero.txt","wt");

	fprintf(pf,"%i\n",fila);
	fprintf(pf,"%i\n",columna);

	for(x=0;x<fila;x++){
		for(y=0;y<columna;y++){
			fprintf(pf,"%i",matriz[x][y]);
		}
		fprintf(pf,"\n");
	}
	fclose(pf);
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
	int color;
	setcolor(1);
		for (indice=0;indice<f*c;indice++){
//			gotoxy(indice%c*4+1,indice/c+7);
			rectangle(indice%c*15,indice/c*15,indice%c*15+15,indice/c*15+15);
			if (matriz[indice/c][indice%c]==0){
				color=WHITE;
			}else{
				color=BLACK;
			}
			setfillstyle(SOLID_FILL,color);
			floodfill(indice%c*15+7,indice/c*15+7,1);

//			printf("%i",matriz[indice/c][indice%c]);
		}
		setcolor(WHITE);
}
void agregarNodo (NODO **pri, int fa,int ca){
	NODO *nuevo, *aux,*aux2;
	aux= *pri;
	aux2=aux->sig;
	nuevo=malloc(sizeof(NODO));
	if (nuevo!=NULL){
		nuevo->fila=fa;
		nuevo->columna=ca;
		nuevo->sig=NULL;
		if (aux==NULL){ //1ø NODO
			*pri=nuevo;
		}else{
			while (!(aux2==NULL && aux->sig==NULL)){
				aux=aux->sig;
				aux2=aux->sig;
			}
			nuevo->sig=aux2;
			aux->sig=nuevo;
		}
	}
}

void mostrarLista (NODO *pri){
	NODO *aux=pri;
	int x=0,y=0;
	char dato[6],fs[3], cs[3];
	strset(dato,NULL);
	strset(fs,NULL);
    strset(cs,NULL);
	cleardevice();
	while (aux!=NULL){
		sprintf(fs, "%2i", aux->fila);
		fs[2]=NULL;
		sprintf(cs, "%2i", aux->columna);
		cs[2]=NULL;
		strcat(dato, fs);
		strcat(dato, "/\0");
		strcat(dato, cs);
		dato[5]=NULL;
//		dato[0]=aux->fila-48;
//		dato[1]='/';
//		dato[2]=aux->columna-48;
//		dato[3]=NULL;
		setcolor(RED);
		if(x!=0){
		setlinestyle(SOLID_LINE,1,3);
		line(x-9,y+10,x,y+10);
		}else{
			if(y!=0){
			setlinestyle(SOLID_LINE,1,3);
			line(x-620,y+16,x+590,y-18);
			}
		}
		setcolor(WHITE);
		setlinestyle(SOLID_LINE,1,1);
		rectangle(x,y,x+50,y+20);
		outtextxy(x+10,y+10,dato);
		if (x+50<580){
		x+=60;
		}else{
		x=0;
		y+=40;
		};
//		printf("[%p-%c-%p]-->\n",aux,aux->dato,aux->sig);
		aux=aux->sig;
		strset(dato,NULL);
		strset(fs,NULL);
		strset(cs,NULL);

	}
}
void buscarCero (int **matriz, int col, int fil, NODO **pri){

int f=0,c=0;
int cantceros=0;
int x=-1,y=-1;
int contador=0;

	getch();
	for (f=0; f<fil-1; f++){
		for (c=0; c<col;c++){
			if(matriz[f][c]==0){
				buscar(matriz,col,fil,f,c,&contador);

				if(contador>cantceros){
					x=f;
					y=c;
					cantceros=contador;
				}
			}
			contador=0;
		}
	}
setcolor(WHITE);
printf("\n\n");
if(x<0 ||y<0){
	outtextxy(0,200,"La matriz generada no tiene ceros");
}else{
	pintar(matriz,col,fil,x,y,pri);

	printf("El numero de fila: %i",x);
	printf("\n");
	printf("El numero de columnas: %i",y);
	printf("\n");
	printf("La cantidad de ceros: %i",cantceros);
}
outtextxy(0,300,"Enter para salir");
getch();
}
void pintar(int** matriz, int columna,int fila,int f,int c,NODO **primero){
	if (f<fila){
		setfillstyle(SOLID_FILL,RED);
		floodfill(c*15+7,(f)*15+7,BLUE);
		agregarNodo(primero,f,c);
		matriz[f][c]=5;
	if(f>0){
		if (matriz[f-1][c]==9){

			pintar(matriz,fila,columna,f-1,c,primero);

		}
	}
	if (c<columna-1){
		if(matriz[f][c+1]==9){

			pintar(matriz,fila,columna,f,c+1,primero);

		}
	}
	if(f<fila-1){
		if(matriz[f+1][c]==9){

			pintar(matriz,fila,columna,f+1,c,primero);

		}
	}
	if(c>0){
		if(matriz[f][c-1]==9){

			pintar(matriz,fila,columna,f,c-1,primero);

		}
	}
}

}
void buscar(int **matriz, int columna, int fila, int f, int c,int *contador){

if (f<fila){
matriz[f][c]=9;
*contador=*contador+1;
	if(f>0){
		if (matriz[f-1][c]==0){
			setfillstyle(SOLID_FILL,WHITE);
			floodfill(c*15+7,(f-1)*15+7,BLUE);

			buscar(matriz,fila,columna,f-1,c,contador);
		}
	}
	if (c<columna-1){
		if(matriz[f][c+1]==0){
			setfillstyle(SOLID_FILL,WHITE);
			floodfill((c+1)*15+7,f*15+7,BLUE);

			buscar(matriz,fila,columna,f,c+1,contador);
		}
	}
	if(f<fila-1){
		if(matriz[f+1][c]==0){
			setfillstyle(SOLID_FILL,WHITE);
			floodfill(c*15+7,(f+1)*15+7,BLUE);

			buscar(matriz,fila,columna,f+1,c,contador);
		}
	}
	if(c>0){
		if(matriz[f][c-1]==0){
			setfillstyle(SOLID_FILL,WHITE);
			floodfill((c-1)*15+7,f*15+7,BLUE);

			buscar(matriz,fila,columna,f,c-1,contador);
		}
	}
}
}