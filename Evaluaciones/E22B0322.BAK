/*-----------------------------------------------------------------------------
Evaluaci¢n de Laboratorio II - Grupo B (2/2)
-----------------------------------------------------------------------------
Alumno: Iv n Franco
-----------------------------------------------------------------------------

Se tienen los siguientes datos almacenados en un archivo DATA.IN con formato
de texto plano, que representan los n£meros almacenados en una matriz, y que
a su vez indican los colores de relleno de rect ngulos de 3x3.

Se pide hacer un programa con las siguientes opciones de men£:

		  1 - Cargar Datos 			(Archivo)
		  2 - Mostrar Matriz 		(N£meros y Gr ficos)
		  3 - Rotar Matriz 		  	(En Sentido Horario)
		  4 - Capturar Imagenes		(Ambas)
		  5 - Generar Mo sico 		(Ingresando el valor de ancho y alto)
		  0 - Salir
-----------------------------------------------------------------------------
Notas:

1) Los datos contenidos en el archivo son los siguientes:

		  8
		  8
		  4 8 4 4 4 4 4 1
		  8 9 8 4 4 4 1 1
		  4 8 4 4 4 1 1 1
		  4 4 4 4 1 1 1 1
		  4 4 4 1 1 1 1 1
		  4 4 1 1 1 9 9 1
		  4 1 1 1 1 9 9 1
		  1 1 1 1 1 1 1 1

2) Guardar la evaluaci¢n bajo el nombre e22bxx22.c en su cuenta (excluyente).
3) El Archivo DATA.IN deber  estar almacenado en la carpeta c:\temp.
4) El mos ico esta formado por la intercalaci¢n de un gr fico de matriz
   original y uno de matriz rotada, cubriendo la superficie total que
   indic¢ el usuario. Este procedimiento debe ser recursivo.
5) Todos los puntos deben estar desarrollados.
-----------------------------------------------------------------------------*/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

void cargarArchivo(int *,int *,int **);
void mostrarMatriz(int **);
void rotarMatriz(int **);
//void capturarMatriz();
//void imprimeMatMo();
void generarArchivo(void);

void main (void){

int tecla=6;
int fila, columna,x;
int drv=DETECT, mdo;
int **m=malloc(sizeof(int *)*8);

for(x=0;x<8;x++){
	m[x]=malloc(sizeof(int)*8);
}

generarArchivo();

initgraph(&drv,&mdo,"C:\\BC\\BGI");

	do{
		cleardevice();
		 outtextxy(0,5,"1 - Cargar Datos");
		 outtextxy(0,15,"2 - Mostrar Matriz");
		 outtextxy(0,25,"3 - Rotar Matriz");
		 outtextxy(0,35,"4 - Capturar Imagenes");
		 outtextxy(0,45,"5 - Generar Mos ico");
		 outtextxy(0,55,"0 - Salir");

		 tecla=getche();

		 switch(tecla){
			 case 49:
				cleardevice();
				cargarArchivo(&fila,&columna,m);
				outtextxy(5,0,"Los datos fueron cargados");
				getch();
				break;
			 case 50:
				cleardevice();
				mostrarMatriz(m);
				getch();
				break;
			 case 51:
				cleardevice();
				rotarMatriz(m);
				outtextxy(5,0,"Los datos fueron rotados");
				getch();
				break;
			 case 52:
				cleardevice();
				mostrarMatriz(m);
//				capturarMatriz();
				getch();
				break;
			 case 53:
				cleardevice();
				printf("Ingrese la cantidad de filas:");
				fila=getche();
				fila-=48;
				printf("Ingrese la cantidad de filas:");
				columna=getche();
				columna-=48;
//				imprimeMatMo();
				getch();
				break;
		 }

	}while(tecla!=48);

closegraph();

}

void rotarMatriz(int **m){

int f,c;
int finF=7,finC=7;
int **aux=malloc(sizeof(int *)*8);

	for(f=0;f<8;f++){
		aux[f]=malloc(sizeof(int)*8);
	}

	for(f=0;f<8;f++){
		for(c=0;c<8;c++){
			aux[f][c]=m[f][c];
		}
	}

	for (f=0;f<8;f++){
		for(c=0;c<8;c++){
			m[f][c]=aux[finC-c][finF-f];
		}
	}

}

void mostrarMatriz(int **m){

int f,c;
int x=0,y=0;
int dat[2];

dat[0]=NULL;
dat[1]=NULL;

	for(f=0;f<8;f++){
		for(c=0;c<8;c++){
			rectangle(x,y,x+10,y+10);
			dat[0]=m[f][c];
			outtextxy(x+2,y-2,dat);
			x+=10;
			y+=10;
		}
		x=0;
		y=10;
	}
	x=100;
	y=10;
	for(f=0;f<8;f++){
		for(c=0;c<8;c++){
			rectangle(x,y,x+10,y+10);
			setfillstyle(SOLID_FILL,m[f][c]);
			floodfill(x+1,y-1,WHITE);
			x+=10;
			y+=10;
		}
		x=100;
		y=10;
	}

}

void cargarArchivo(int *fi,int *co, int **mat){

int f,c;
char *linea=malloc(sizeof(char)*8);
FILE *pf=fopen("C:\\temp\\data.in","rt");

	fscanf(pf,&fi);
	fscanf(pf,&co);

	for(f=0;f<8;f++){
		fscanf(pf,&linea[f]);
	}

	for(f=0;f<8;f++){
		for(c=0;c<8;c++){
		mat[f][c]=linea[f]-48;
		}
	}
fclose(pf);
}

void generarArchivo(void){

int f,c;
FILE *pf=fopen("C:\\temp\\data.in","wt");
int **m=malloc(sizeof(int *)*8);

	for(f=0;f<8;f++){
		m[f]=malloc(sizeof(int)*8);
	}

	for(f=0;f<8;f++){
		for(c=0;c<8;c++){
			m[f][c]=1;
		}
	}

	f=8;
	c=8;

	m[0][0]=4;
	m[1][0]=8;
	m[2][0]=4;
	m[3][0]=4;
	m[4][0]=4;
	m[5][0]=4;
	m[6][0]=4;

	m[0][1]=8;
	m[1][1]=9;
	m[2][1]=8;
	m[3][1]=4;
	m[4][1]=4;
	m[5][1]=4;

	m[0][2]=4;
	m[1][2]=8;
	m[2][2]=4;
	m[3][2]=4;
	m[4][2]=4;

	m[0][3]=4;
	m[1][3]=4;
	m[2][3]=4;
	m[3][3]=4;

	m[0][4]=4;
	m[1][4]=4;
	m[2][4]=4;

	m[0][5]=4;
	m[1][5]=4;
	m[5][5]=9;
	m[6][5]=9;

	m[0][6]=4;
	m[5][6]=4;
	m[6][6]=4;


	fprintf("%i\n",&f);
	fprintf("%i\n",&c);

	for(f=0;f<8;f++){
		for(c=0;c<8;c++){
			fprintf("%i",&m[f][c]);
		}
		fprintf("\n",NULL);
	}
fclose(pf);
}