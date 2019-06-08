#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h> //librer¡a para strings

int palindromo(char[30]);   // funci¢n palindromo con vector char de 30
char *(hacerp) (char cad1[30]);

void main(void) {
	char cad1[30]; //vector char 30
	char indice; //contador

	clrscr();//borra pantalla
		for (indice=0; indice<30;indice++){//for para borrar todo
			cad1[indice]= NULL;//borra todo lo deja en NULL
		}
	printf("Ingresar la palabra para ser analizada:");
	gets(cad1); //lee palabra ingresada
	printf("\n");
	if (palindromo(cad1)==0){//funcion palindromo devuelve resultado 0 entonces
		printf("Su palabra ingresada es palindromo");//si es 0 es palindromo
	}else{
		printf("Su palabra ingresada no es palindromo");//si es distinto de 0 no es palindromo
		printf("\n");
		printf("\n");
		printf("Por lo tanto el programa crear  la palabra en forma que sea palindroma");
		printf("\n");
		printf("Su palabra hecha palindromo es %s%s",cad1, hacerp(cad1));
		//llama la funci¢n para hacer palindromo la palabra
	}

	getch();//espera hasta que la persona cliquee enter
}
/*FUNCION PALINDROMO
esta funcion tiene la capacidad de devolver dos resultados
y son numericos (0 y 1) segun el caso, 0 si es palindromo
y 1 si no es palindromo*/

int palindromo(char cad1[30]){
	char cadaux[30];
	char indice;
	char indice2;
	for (indice=0; indice<30;indice++){ //for para borrar el vector auxiliar
		cadaux[indice]= NULL;
	}
	indice=0;
	indice2=0;
	for (indice =(strlen(cad1)-1); indice>-1 ; indice--){//for para voltear la palabra
		cadaux[indice2]= cad1[indice]; //primera letra = ultima letra y asi sucesivamente
		indice2++;
	}
	if(strcmp(cad1,cadaux)==0){  //si funcion c da igualdad en vector y aux =0
		return(0); //devuelve 0 (palindromo)
	}else{
		return(1); //devuelve 1 (no palindromo)
	}
}
char *(hacerp)(char aux[30]){ //funcion para hacer palindromo
	int x,y=0;

	char *cad1=malloc(sizeof(char)*strlen(aux)); //busca si el vector entra en memoria
	/*memset carga al vector con lo que se quiera
	en este caso se lo borra
	porque lo que llenamos es con NULL*/
	memset(cad1, strlen(aux), NULL);
		for(x= strlen(aux)-2;x>-1;x--){ //for para agregarle la otra parte
			cad1[y]=aux[x]; //cad = aux pero volteado
			y++;
		}
	cad1[y]=NULL; //se borra la ultima pos
	return(cad1);
}