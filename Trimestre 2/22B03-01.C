/*CONSIGNA
Tomando como base el TP 8 (Busca Ceros)
-Hacer la representaci�n gr�fica de la matriz de manera que por cada n�mero
se muestre un rect�ngulo, y cambiando el color del rect�ngulo por el cual
se va avanzando
-Mostrar tambi�n la cantidad de soluciones que tiene cada laberinto.
-Hacer un men� que se maneje con los cursores, que tenga las siguientes
opciones:

	Generar Matriz
	Guardar Matriz
	Cargar Matriz
	Mostrar Soluciones
	Salir

*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <dos.h>
#include <graphics.h>
#include <string.h>

void buscar (int **,int,int,int,int,int *);//funcion que busca los 0 alrededor
int **crearMatriz(int,int);//funcion para crear matriz
void cargaMatriz(int **, int, int);//funcion para cargar la matriz
void imprimeMatriz(int **,int,int);//funcion que imprime matriz
void guardarMatriz(int,int,int **);
void abrirMatriz(int,int,int **);

void main(void){
	int **matriz;
	int fila=0,columna=0;
	int f=0,c=0,intopc=1;
	char opc;
	int *contador=0;
	int drv=DETECT, mdo;

	randomize();//funcion randomize que permite generar numeros al azar
	initgraph(&drv,&mdo,"C:\\BC\\BGI");
	do{
		cleardevice();//borra la pantalla
		outtextxy(50,4,"MENU");
		outtextxy(70,35,"Generar Matriz");
		outtextxy(70,65,"Guardar Matriz");
		outtextxy(70,95,"Cargar Matriz");
		outtextxy(70,125,"Mostrar Soluciones");
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
						//sistema de repeticion que busca 0s en la primera fila
						contador=0;
						for (c=0; c<=columna;c++){//fila=0 columna=contador++
							if (matriz[0][c]==0){//si encuentra un 0
							//llama a la funcion buscar 0
								delay(200);
								buscar(matriz,fila,columna,f,c,&contador);
							}
						}
						outtextxy(1,450,"Se terminaron de ver todas las posibilidades aprete algo");
						getch();
						cleardevice();
						outtextxy(0,0,"La cantidad de soluciones son: ");
						printf("\n");
						printf("%i\n",contador);
						outtextxy(0,450,"Pulse Enter para continuar");
						getch();
					}else{
						outtextxy(0,0,"Debe generar la matriz antes de poder verla");
						getch();
					}
				break;
			}
		}
	}while(intopc!=5);
		closegraph();
}
void abrirMatriz(int fila,int columna, int **matriz){

int x,y;
char *linea;

FILE *pf=fopen("U:\\laberinto.txt","rt");
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

	FILE *pf=fopen("U:\\laberinto.txt","wt");

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
void buscar (int **matriz, int fila, int columna,int f,int c,int *contador){
/*funcion buscar, que tiene como parametros
la matriz, cant de filas, cant de columnas
la fila del cero anterior, la columna del cero anterior
*/
if(f==fila-1){
   *contador=*contador+1;
}else{
//textcolor(4);//color de texto rojo
if (f<fila){//si f del cero es menor a la cant de filas
	if(f>0){//si f del cero es mayor a 0
		/*si arriba del 0 hay un cero
		si lo hay pone ese punto en 9 y vuelve a la funcion
		recursivamente con el nuevo punto para fijarse si
		hay un camino entero*/
		if (matriz[f-1][c]==0){
			delay(200);
			matriz[f-1][c]=9;

			setfillstyle(SOLID_FILL,RED);
			floodfill(c*15+7,(f-1)*15+7,WHITE);

			buscar(matriz,fila,columna,f-1,c,contador);
			matriz[f-1][c]=0;
//cuando termina, vuelve al 0 el punto antiguo
//			gotoxy(c*4+1,f-1+7);
			setfillstyle(SOLID_FILL,YELLOW);
			floodfill(c*15+7,(f-1)*15+7,WHITE);
//			cprintf("0");
		}
	}
	//si f de cero es mayor a 0 y c de cero es menor a la cant de col-1
	if(f>0 && c<columna-1){
		/*si arriba a la derecha del 0 hay un cero
		si lo hay pone ese punto en 9 y vuelve a la funcion
		recursivamente con el nuevo punto para fijarse si
		hay un camino entero*/
		if(matriz[f-1][c+1]==0){
			delay(200);
			matriz[f-1][c+1]=9;

			setfillstyle(SOLID_FILL,RED);
			floodfill(c*15+7,(f-1)*15+7,WHITE);

			buscar(matriz,fila,columna,f-1,c+1,contador);
			matriz[f-1][c+1]=0;

			setfillstyle(SOLID_FILL,YELLOW);
			floodfill((c+1)*15+7,(f-1)*15+7,WHITE);
//			gotoxy((c+1)*4+1,f-1+7);
//			cprintf("0");
		}
	}
	//si c de 0 es menor a cant de c-1
	if (c<columna-1){
		/*si a la derecha del 0 hay un cero
		si lo hay pone ese punto en 9 y vuelve a la funcion
		recursivamente con el nuevo punto para fijarse si
		hay un camino entero*/
		if(matriz[f][c+1]==0){
			delay(200);
			matriz[f][c+1]=9;

			setfillstyle(SOLID_FILL,RED);
			floodfill((c+1)*15+7,f*15+7,WHITE);

			buscar(matriz,fila,columna,f,c+1,contador);
			matriz[f][c+1]=0;

			setfillstyle(SOLID_FILL,YELLOW);
			floodfill((c+1)*15+7,f*15+7,WHITE);
//			gotoxy((c+1)*4+1,f+7);
//			cprintf("0");
		}
	}
	//si f de cero es menor a cant de f-1 Y c de cero es menor a cant de c-1
	if(f<fila-1 && c<columna-1){
		/*si abajo a la derecha del 0 hay un cero
		si lo hay pone ese punto en 9 y vuelve a la funcion
		recursivamente con el nuevo punto para fijarse si
		hay un camino entero*/
		if(matriz[f+1][c+1]==0){
			delay(200);
			matriz[f+1][c+1]=9;

			setfillstyle(SOLID_FILL,RED);
			floodfill((c+1)*15+7,(f+1)*15+7,WHITE);

			buscar(matriz,fila,columna,f+1,c+1,contador);
			matriz[f+1][c+1]=0;

			setfillstyle(SOLID_FILL,YELLOW);
			floodfill((c+1)*15+7,(f+1)*15+7,WHITE);
//			gotoxy((c+1)*4+1,f+1+7);
//			cprintf("0");
		}
	}
	//si f de cero es menor a cant f-1
	if(f<fila-1){
		/*si abajo del 0 hay un cero
		si lo hay pone ese punto en 9 y vuelve a la funcion
		recursivamente con el nuevo punto para fijarse si
		hay un camino entero*/
		if(matriz[f+1][c]==0){
			delay(200);
			matriz[f+1][c]=9;

			setfillstyle(SOLID_FILL,RED);
			floodfill(c*15+7,(f+1)*15+7,WHITE);

			buscar(matriz,fila,columna,f+1,c,contador);
			matriz[f+1][c]=0;

			setfillstyle(SOLID_FILL,YELLOW);
			floodfill(c*15+7,(f+1)*15+7,WHITE);
//			gotoxy(c*4+1,f+1+7);
//			cprintf("0");
		}
	}
	//si f de cero es menor a cant f-1 Y c de cero mayor a 0
	if(f<fila-1 && c>0){
		/*si abajo a la izquierda del 0 hay un cero
		si lo hay pone ese punto en 9 y vuelve a la funcion
		recursivamente con el nuevo punto para fijarse si
		hay un camino entero*/
		if(matriz[f+1][c-1]==0){
			delay(200);
			matriz[f+1][c-1]=9;

			setfillstyle(SOLID_FILL,RED);
			floodfill((c-1)*15+7,(f+1)*15+7,WHITE);

			buscar(matriz,fila,columna,f+1,c-1,contador);
			matriz[f+1][c-1]=0;

			setfillstyle(SOLID_FILL,YELLOW);
			floodfill((c-1)*15+7,(f+1)*15+7,WHITE);
//			gotoxy((c-1)*4+1,f+1+7);
//			cprintf("0");
		}
	}
	//si c de cero es mayor a 0
	if(c>0){
		/*si a la izquierda del 0 hay un cero
		si lo hay pone ese punto en 9 y vuelve a la funcion
		recursivamente con el nuevo punto para fijarse si
		hay un camino entero*/
		if(matriz[f][c-1]==0){
			delay(200);
			matriz[f][c-1]=9;

			setfillstyle(SOLID_FILL,RED);
			floodfill((c-1)*15+7,f*15+7,WHITE);

			buscar(matriz,fila,columna,f,c-1,contador);
			matriz[f][c-1]=0;

			setfillstyle(SOLID_FILL,YELLOW);
			floodfill((c-1)*15+7,f*15+7,WHITE);
//			gotoxy((c-1)*4+1,f+7);
// 			cprintf("0");
		}
	}
	//si f de cero es mayor a cero Y c de cero es mayor a 0
	if(f>0 && c>0){
		/*si arriba a la izquierda del 0 hay un cero
		si lo hay pone ese punto en 9 y vuelve a la funcion
		recursivamente con el nuevo punto para fijarse si
		hay un camino entero*/
		if(matriz[f-1][c-1]==0){
			delay(200);
			matriz[f-1][c-1]=9;

			setfillstyle(SOLID_FILL,RED);
			floodfill((c-1)*15+7,(f-1)*15+7,WHITE);

			buscar(matriz,fila,columna,f-1,c-1,contador);
			matriz[f-1][c-1]=0;

			setfillstyle(SOLID_FILL,YELLOW);
			floodfill((c-1)*15+7,(f-1)*15+7,WHITE);
//			gotoxy((c-1)*4+1,f-1+7);
//			cprintf("0");
		}
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
	int color;
		for (indice=0;indice<f*c;indice++){
//			gotoxy(indice%c*4+1,indice/c+7);
			rectangle(indice%c*15,indice/c*15,indice%c*15+15,indice/c*15+15);
			if (matriz[indice/c][indice%c]==0){
				color=RED;
			}else{
				color=BLUE;
			}
			setfillstyle(SOLID_FILL,color);
			floodfill(indice%c*15+7,indice/c*15+7,WHITE);

//			printf("%i",matriz[indice/c][indice%c]);
		}
}