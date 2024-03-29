//------------------------------------------------------------------------------
// Evaluaci�n de Laboratorio II - Grupo B - (1/2) - Trimestre 3
//------------------------------------------------------------------------------
// Apellido/s, Nombre/s	: Franco, Ivan
// N�mero de Cuenta	: 22b03
//------------------------------------------------------------------------------
// Enunciado:
/*
-	Hacer una clase llamada Poligono, con las propiedades privadas para
	almacenar el largo de cada lado, y la cantidad de lados del mismo.
	El m�todo constructor por defecto debe recibir la cantidad de lados y el
	largo de los lados. El constructor debe llamar a un m�todo privado que
	ser� el encargado de representar gr�ficamente al pol�gono.
	Deben existir los m�todos para la consulta de los valores de las
	propiedades.
	Un m�todo debe permitir calcular el per�metro de cada pol�gono y otro
	debe permitir calcular la superficie del pol�gono.
-	Hacer una clase Tri�ngulo que hereda de Pol�gono, que tenga una
	sobreescritura del m�todo que calcula superficie, especificado solo para
	tri�ngulos.
-	Hacer una clase Cuadrado que hereda de Pol�gono, que tenga una
	sobreescritura del m�todo que calcula superficie, especificado solo para
	cuadrados.
-	Un programa principal ser� el encargado de instanciar los objetos
	definido,utilizando un men� de opciones para seleccionar a cada uno de los
	elementos.
*/
//------------------------------------------------------------------------------
// Notas:	- Guardar todos los archivos de la Evaluaci�n en una carpeta con el
//					nombre e22bxx31.
//------------------------------------------------------------------------------
#include "poligono.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <mem.h>
#include <alloc.h>

void main(void){

	int drv=DETECT,mdo;
	Poligono *a=NULL;
	Cuadrado *b=NULL;
	Triangulo *c=NULL;
	int opc, cla,indic;
	int *longi;

initgraph(&drv,&mdo,"C:\\BC\\BGI");
	do{
		cleardevice();
		outtextxy(50,0,"MENU");
		outtextxy(10,20,"1-Crear un poligono");
		outtextxy(10,30,"2-Crear un cuadrado");
		outtextxy(10,40,"3-Crear un triangulo");
		outtextxy(10,50,"4-Cantidad de lados");
		outtextxy(10,60,"5-Longitud de los lados");
		outtextxy(10,70,"6-Salir");

		opc=getch();
		opc-=48;

		switch(opc){
			case 1:
				cleardevice();

				outtextxy(30,0,"Ingrese la cantidad de lados:");
				scanf("%i",&cla);
				longi=(int *)(malloc(sizeof(int)*cla));

				for(indic=0;indic<cla;indic++){
					outtextxy(30,(indic*10)+10,"Ingrese la longitud del lado:");
					scanf("%i",&longi[indic]);
				}
				a= new Poligono(cla,longi);
				getch();
				break;
			case 2:
				cleardevice();

				cla=4;
				longi=(int *)(malloc(sizeof(int)*4));

				for(indic=0;indic<cla;indic++){
					outtextxy(30,(indic*10)+10,"Ingrese la longitud del lado:");
					scanf("%i",&longi[indic]);
				}
				a= new Poligono(cla,longi);
				getch();
				break;
			case 3:
				cleardevice();

				cla=3;

				longi=(int *)(malloc(sizeof(int)*3));

				for(indic=0;indic<cla;indic++){
					outtextxy(30,(indic*10)+10,"Ingrese la longitud del lado:");
					scanf("%i",&longi[indic]);
				}
				a=new Poligono(cla,longi);
				getch();
				break;
			case 4:
				//cantidad de lados
					clrscr();
					if(a!=NULL){
						printf("La cantidad de lados es de %i",a->obtenerCantLados());
					}else{
						if(b!=NULL){
							printf("La cantidad de lados es de %i",a->obtenerCantLados());
						}else{
							if(c!=NULL){
								printf("La cantidad de lados es de %i",a->obtenerCantLados());
							}
						}
					}
					getch();
				break;
			case 5:
				//longitudes
					clrscr();
					memset(longi,NULL,cla);
					if(a!=NULL){
						for(indic=0;indic<cla;indic++){
							longi[indic]=a->obtenerLongitud(indic);
							printf("Lado %i tiene de longitud: %i\n",indic,longi[indic]);
						}
					}else{
						if(b!=NULL){
							for(indic=0;indic<cla;indic++){
								longi[indic]=a->obtenerLongitud(indic);
								printf("Lado %i tiene de longitud: %i\n",indic,longi[indic]);
							}
						}else{
							if(c!=NULL){
								for(indic=0;indic<cla;indic++){
									longi[indic]=a->obtenerLongitud(indic);
									printf("Lado %i tiene de longitud: %i\n",indic,longi[indic]);
								}
							}
						}
					}
					getch();
				break;
		}
	}while(opc!=6);

closegraph();
}