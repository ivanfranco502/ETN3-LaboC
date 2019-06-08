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
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <time.h>
#include <dos.h>

int **crearMatriz(int,int);//funcion para crear matriz
void cargaMatriz(int **, int, int);//funcion para cargar la matriz
void imprimeMatriz(int **,int,int);//funcion que imprime matriz
void guardarMatriz(int,int,int **);
void abrirMatriz(int,int,int **);
void buscarCero(int **, int, int);
void buscar(int **, int, int, int, int,int *);

void main(void){
	int **matriz;
	int fila=4,columna=3;
	int intopc=0;
	char opc;
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
 /*					outtextxy(0,0,"Ingrese el numero de filas: ");
					printf("\n");
					scanf("%i",&fila);//se toma el valor de cant de filas para la matriz
					outtextxy(0,10,"Ingresa el numero de columnas: ");
					printf("\n");
					scanf("%i%",&columna);//se toma el valor de cant de col para la matriz*/
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
						buscarCero(matriz,fila,columna);
						outtextxy(0,450,"Pulse Enter para continuar");
						getch();
					}else{
						outtextxy(0,0,"Debe generar la matriz antes de poder verla");
						getch();
					}
					break;
				case 5:
					cleardevice();

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
	strset(linea,NULL);
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
	matriz[0][0]=1;
	matriz[0][1]=1;
	matriz[0][2]=1;
	matriz[1][0]=0;
	matriz[1][1]=0;
	matriz[1][2]=1;
	matriz[2][0]=0;
	matriz[2][1]=0;
	matriz[2][2]=1;
	matriz[3][0]=1;
	matriz[3][1]=1;
	matriz[3][2]=0;

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
void buscarCero (int **matriz, int col, int fil){

int f=0,c=0;
int cantceros=0;
int x=0, y=0;
int contador=0;
	for (f=0; f<fil; f++){
		for (c=0; c<col;c++){
			if(matriz[f][c]==0){
				buscar(matriz,col,fil,c,f,&contador);

				if(contador>cantceros){
					x=f;
					y=c;
					cantceros=contador;
				}
			}
		}
	}
outtextxy(0,250,"ENTER");
getch();
cleardevice();
printf("X: %i",x);
printf("Y: %i",y);
printf("Cant 0= %i",cantceros);
getch();
}
void buscar(int **matriz, int columna, int fila, int c, int f,int *contador){

if (f<fila){
	if(f>0){
		if (matriz[f-1][c]==0){
			matriz[f-1][c]=9;

			setfillstyle(SOLID_FILL,WHITE);
			floodfill(c*15+7,(f-1)*15+7,BLUE);

			buscar(matriz,fila,columna,f-1,c,contador);
			setfillstyle(SOLID_FILL,RED);
			floodfill(c*15+7,(f-1)*15+7,BLUE);
			*contador=*contador+1;
		}
	}
	if (c<columna-1){
		if(matriz[f][c+1]==0){
			matriz[f][c+1]=9;

			setfillstyle(SOLID_FILL,WHITE);
			floodfill((c+1)*15+7,f*15+7,BLUE);

			buscar(matriz,fila,columna,f,c+1,contador);

			setfillstyle(SOLID_FILL,RED);
			floodfill((c+1)*15+7,f*15+7,BLUE);
			*contador=*contador+1;
		}
	}
	if(f<fila-1){
		if(matriz[f+1][c]==0){
			matriz[f+1][c]=9;

			setfillstyle(SOLID_FILL,WHITE);
			floodfill(c*15+7,(f+1)*15+7,BLUE);

			buscar(matriz,fila,columna,f+1,c,contador);

			setfillstyle(SOLID_FILL,RED);
			floodfill(c*15+7,(f+1)*15+7,BLUE);
			*contador=*contador+1;
		}
	}
	if(c>0){
		if(matriz[f][c-1]==0){
			matriz[f][c-1]=9;

			setfillstyle(SOLID_FILL,WHITE);
			floodfill((c-1)*15+7,f*15+7,BLUE);

			buscar(matriz,fila,columna,f,c-1,contador);

			setfillstyle(SOLID_FILL,RED);
			floodfill((c-1)*15+7,f*15+7,BLUE);
			*contador=*contador+1;
		}
	}
}
}