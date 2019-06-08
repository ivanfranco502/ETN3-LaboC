#include "clases.h"
#include <string.h>
#include <stdlib.h>

Animal::Animal(){
	nombre=(char *)(malloc(sizeof(char)*20));
	strset(nombre,NULL);
	extremidades=4;
	calorias=3500;
	strcpy(nombre,"Astor");
	especie=1;
	hambre=5;
	sed=5;
	estado=1;
}
Animal::Animal(int a,int b, char *c, int d){
	nombre=(char *)(malloc(sizeof(char)*20));
	strset(nombre,NULL);
	extremidades=a;
	calorias=b;
	strcpy(nombre,c);
	especie=d;
	hambre=5;
	sed=5;
	estado=1;
}
int Animal::obtenerExtremidades(){
	return(extremidades);
}
int Animal::obtenerCalorias(){
	return(calorias);
}
char *Animal::obtenerNombre(){
	return(nombre);
}
int Animal::obtenerEspecie(){
	return(especie);
}
int Animal::obtenerHambre(){
	return(hambre);
}
int Animal::obtenerSed(){
	return(sed);
}
int Animal::obtenerEstado(){
	return(estado);
}
void Animal::asignarExtremidades(int a){
	if(a>=0 && a<=100){
		extremidades=a;
	}
}
void Animal::asignarCalorias(int a){
	if(a<100){
		calorias=a;
		estado=2;
	}else{
		calorias=a;
		estado=1;
	}
}
void Animal::asignarNombre(char *a){
	nombre=a;
}
void Animal::asignarEspecie(int a){
	switch(a){
		case 1:
			especie=a;
		case 2:
			especie=a;
	}
}
