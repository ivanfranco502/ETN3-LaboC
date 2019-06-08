/*CONSIGNA
Tomando como base el practico palindromo, hacer que el programa resuelva la
verificacion y la conversion en palindromo de mandera recursiva
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int boolPalin  (char *,int);//funcion devuelve si es palindromo
char *(palin) (char *, int);//funcion que genera palindromo

void main (void){
char * chrpal=malloc(sizeof(char)*50);//verifica si hay espacio vector char
clrscr();
scanf("%s",chrpal); //se toma la palabra
	if (boolPalin(chrpal,0)==0){ //si bool palin devuelve 0 es palindromo
		printf("Es palindromo la palabra");
	}else{//si bool palin devuelve 1 no es palindromo
		printf("No es palindromo la palabra");
		printf("\n");
		//hace la palabra palindromo
		//llamado a la funcion crear palindromo
		printf("La palabra hecha palindromo es %s", palin(chrpal,0));
	}
getch();
}

int boolPalin(char * pal, int indice){ //funcion booleana que dice si
//la palabra es palindromo o no
int val=0;
	if (pal[indice]!= pal[strlen(pal)-indice-1]){//si la letra de la palabra
	//es distinta a la letra en la posicion del len de la palabra menos
	//el indice, no es palindromo
		val=1;
	}
	if (indice ==(strlen(pal)/2)){//si el indice es igual al la mitad
	//de la palabra, es palindromo
		val=0;
	}
return(val);
}
char *(palin)(char* pal, int cont){//funcion que hace palindromo una palabra

char *aux=malloc(sizeof(char)*50);//variable auxiliar
char *fin=malloc(sizeof(char)*50);//variable final

memset(aux,50,NULL);
memset(fin,50,NULL);
strcpy(aux,pal);//copia palabra a auxiliar
strrev(aux);//invierte auxiliar

	aux[strlen(pal)-cont]=NULL;//borra la ultima letra de aux(primera de pal)
	if (boolPalin(aux,0)==0){//si aux es palindromo
		memset(aux,50,NULL);//se borra aux
		memset(fin,50,NULL);//se borra fin
		strcpy(fin,pal);//se copia pal a final
		strncpy(aux,pal,cont);//se le copia a aux la "CONT" cantidad de
		//letras de pal
		aux[cont]=NULL;//se borra la "CONT" posicion
		strrev(aux);//se invierte aux
		strcat(fin,aux);//se le pega a fin la parte de aux

		return(fin);
	}

return(palin(pal,cont+1));//llama a la misma funcion pero ahora con el cont+1
}