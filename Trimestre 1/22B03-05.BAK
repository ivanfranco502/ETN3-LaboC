/* CONSIGNA
Hacer una funci¢n de "ingreso de datos validado", segun el
siguiente prototipo:
	char (*ingreso)(unsigned int, unsigned int);
donde el primer parametro indica el largo de la cadena a
ingresar y el segundo parametro corresponde al formato del
ingreso, para el cual se declararan las siguientes constantes:

-MAYUSCULAS 0 Pasa todas las letras a mayusculas
-CAPITAL    1 Pasa la primer letra de cada palabra a mayus
-NUMERO     2 Permite el ingreso solamente de numeros enteros
-NUMERO_SS  3 Permite el ingreso de numeros de punto flotante
-ALFANUM    4 Permite el ingreso de letras y numeros
-TELEFONO   5 Cuatro difitos para la central y cuatro para el
			  abonado (####-####)
-CELULAR    6 Dos digitos para indicar que es celular (15),
			  cuatro para la central y cuatro para el abonado
			  (##-####-####)
-EMAIL		7 Verificar que en la cadena exista solamente un "@"
			  y al menos dos cadenas separadas por punto
-FECHA		8 DD/MM/AAAA
-PASSWORD 	9 ********

NOTA: tener en cuenta que sera necesario investigar las
funciones de conversion de datos.
*/
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

#define MAYUSCULA 0
#define CAPITAL 1
#define NUMERO 2
#define NUMERO_SS 3
#define ALFANUM 4
#define TELELFONO 5
#define CELULAR 6
#define EMAIL 7
#define FECHA 8
#define PASSWORD 9

char *ingreso(unsigned int, unsigned int);

void main(void){
int longitud=0,constante=0;
clrscr();
printf("Ingrese el valor de costanste: ");
scanf("%i", &constante);
if(constante==5){
	do{
		printf("Ingrese un numero para la longitud: ");
		scanf("%i", &longitud);
	}while(longitud!=9);
}else{
	if(constante==6){
		do{
			printf("Ingrese un numero para la longitud: ");
			scanf("%i", &longitud);
		}while(longitud!=12);
	}else{
		printf("\n");
		printf("Ingrese un numero para la longitud: ");
		scanf("%i", &longitud);
	}
}
printf("Ingrese su palabra con %i de longitud: ",longitud);
printf("\nSu palabra hecha es: %s", ingreso(longitud,constante));
getch();
}

char *ingreso (unsigned int longitud,unsigned int constante){
	char *palabra=malloc(sizeof(char)*longitud-1);
	char carac;
	int indic=0;
	int mayus;
	strset(palabra,NULL);
	switch (constante){
		case 0:
			do{
			   carac=getche();
			   if (isalpha(carac)){
				palabra[indic]=toupper(carac);
				indic++;
			   }
			}while(indic<longitud);
			break;
		case 1:
			do{
				carac=getche();
				if(isalpha(carac)){
					if(indic==0 || mayus==1){
						palabra[indic]=toupper(carac);
						if (mayus==1){
							mayus=0;
						}
					}else{
						palabra[indic]=tolower(carac);
					}
				}else{
					if (carac==32){
						mayus=1;
						palabra[indic]=carac;
					}
				}
				indic++;
			}while(indic<longitud);
			break;
		case 2:
			do{
			carac=getche();
				if(isdigit(carac)){
					palabra[indic]=carac;
					indic++;
				}
			}while(indic <longitud);
			break;
		case 3:
			do{
			carac=getche();
				if(isdigit(carac)){
					palabra[indic]=carac;
					indic++;
				}else{
					if(carac==46 && mayus!=3){
						palabra[indic]=carac;
						indic++;
						mayus=3;
					}
				}
			}while(indic <longitud);
			break;
		case 4:
			do{
				carac=getche();
				if(isdigit(carac)){
					palabra[indic]=carac;
					indic++;
				}else{
					if(isalpha(carac)){
						palabra[indic]=carac;
						indic++;
					}
				}
			}while(indic<longitud);
			break;
		case 5:
			do{
				carac=getche();
				if(isdigit(carac) && indic!=4){
					palabra[indic]=carac;
					indic++;
				}else{
					if(indic==4 && carac=='-'){
						palabra[indic]=carac;
						indic++;
					}
				}
			}while(indic<longitud);
			break;
		case 6:
			do{
				carac=getche();
				if(isdigit(carac)&& indic!=2 &&indic!=7){
					switch(indic){
						case 0:
							if(carac=='1'){
								palabra[indic]=carac;
								indic++;
							}
							break;
						case 1:
							if(carac=='5'){
								palabra[indic]=carac;
								indic++;
							}
						default:
							palabra[indic]=carac;
							indic++;
					}
				}else{
					if(indic==2 && carac=='-'){
						palabra[indic]=carac;
						indic++;
					}
					if(indic==7 && carac=='-'){
						palabra[indic]=carac;
						indic++;
					}
				}
			}while(indic<longitud);
			break;

	}
	return(palabra);
}
