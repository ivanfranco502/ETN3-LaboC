#include "clases.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void main(void){

	int opc,cal,pes,comida,tipo;
	int x,y;
	char *nom=(char *)(malloc(sizeof(char)*20));
	Animal *a= new Animal();
	Perro *b=new Perro();
	clrscr();
	printf("Quiere crear un animal o uno por defecto?\n");
	printf("Ingrese 1(uno) para un perro defecto, 2(dos) para uno creado por usted");
	scanf("%i",opc);
	switch(opc){
		case 1:
			break;
		case 2:
			clrscr();
			printf("Ingrese la cantidad de calorias q tiene su perro:");
			scanf("%i",&cal);
			printf("Ingrese el nombre de su animal:");
			scanf("%s",nom);
			a->asignarCalorias(cal);
			a->asignarNombre(nom);
			clrscr();
			printf("Ingrese el peso q va tiene su perro:");
			scanf("%i",&pes);
			b->asignarPeso(pes);
			break;
		}
		clrscr();
		do{
			printf("1-Ver las caracteristicas de tu animal\n");
			printf("2-Dar de comer\n");
			printf("3-Dar de tomar\n");
			printf("4-Hacerlo mover\n");
			printf("5-Salir\n");
			do{
			}while(!kbhit());
			opc=getch();
		switch(opc){
			case 1:
				clrscr();
				printf("Su animal tiene %i calorias\n",a->obtenerCalorias());
				printf("Su animal tiene de nombre %s\n",a->obtenerNombre());
				printf("Su animal es viviparo\n");
				printf("Su animal tiene %i de hambre\n",a->obtenerHambre());
				printf("Su animal tiene %i de sed\n",a->obtenerSed());
				switch(a->obtenerEstado()){
					case 1:
						printf("Su animal esta vivo\n");
						break;
					case 2:
						printf("Su animal esta muerto\n");
						break;
				}
				printf("Su perro tiene de peso %i\n",b->obtenerPeso());
				printf("Su perro esta en X=%i\n",b->obtenerX());
				printf("Su perro esta en Y=%i\n",b->obtenerY());
				printf("Su perro tiene %i de altura",b->obtenerAltura());
				getch();
				break;
			case 2:
				clrscr();
				printf("Que quiere darle al perro?\n");
				printf("1-Hueso");
				printf("2-Alimento balanceado");
				printf("3-Carne");
				scanf("%i",&comida);
				b->Alimentar(comida);
				printf("Su perro fue alimentado");
				getch();
				break;
			case 3:
				clrscr();
				printf("Que quiere darle al perro?\n");
				printf("1-Agua");
				printf("2-Vitalizador");
				scanf("%i",&tipo);
				b->Tomar(tipo);
				printf("Su perro fue hidratado");
				getch();
				break;
			case 4:
				clrscr();
				printf("Valor de x nuevo: ");
				scanf("%i",&x);
				printf("Valor de y nuevo: ");
				scanf("%i",&y);
				printf("Corriendo(1) o Caminando(2)");
				scanf("%i",&tipo);
				b->Moverse(x,y,tipo);
				printf("Su perro fue al lugar asignado");
				break;
		}
		}while(opc!=5);
}