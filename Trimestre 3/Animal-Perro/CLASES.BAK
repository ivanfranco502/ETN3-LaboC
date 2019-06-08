#include "clases.h"
#include <string.h>
#include <stdlib.h>

Animal::Animal(){
	nombre=(char *)(malloc(sizeof(char)*20));
	strset(nombre,NULL);
	extremidades=4;
	calorias=10500;
	strcpy(nombre,"Astor");
	hambre=20;
	sed=20;
	estado=1;
}
Animal::Animal(int a,int b, char *c){
	nombre=(char *)(malloc(sizeof(char)*20));
	strset(nombre,NULL);
	extremidades=a;
	calorias=b;
	strcpy(nombre,c);
	hambre=20;
	sed=20;
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
int Animal::obtenerHambre(){
	return(hambre);
}
int Animal::obtenerSed(){
	return(sed);
}
int Animal::obtenerEstado(){
	return(estado);
}
void Animal::asignarCalorias(int a){
	if(a<100){
		calorias=a;
		estado=2;
	}else{
		calorias=a;
	}
}
void Animal::asignarNombre(char *a){
	nombre=a;
}
void Animal::asignarEstado(int a){
	estado=a;
}
void Animal::asignarHambre(int a){
	if(a<=50){
		hambre=a;
		if(hambre<0){
			hambre=0;
		}
	}else{
		hambre=a;
		asignarEstado(2);
	}
}
void Animal::asignarSed(int a){
	if(a<=50){
		sed=a;
		if(sed<0){
			sed=0;
		}
	}else{
		sed=a;
		asignarEstado(2);
	}
}
Perro::Perro():Animal(){
	peso=1;
	x=0;
	y=0;
	altura=1;
}
Perro::Perro(int a,int b, char *c,int e):Animal(a, b, c){
	peso=e;
	x=0;
	y=0;
	altura=(e/10)+1;
}
int Perro::obtenerPeso(){
	return(peso);
}
int Perro::obtenerX(){
	return(x);
}
int Perro::obtenerY(){
	return(y);
}
int Perro::obtenerAltura(){
	return(altura);
}
void Perro::asignarAltura(){
	altura=(peso/10)+1;
}
void Perro::asignarPeso(int a){
	if(a>0){
		peso=a;
	}else{
		asignarEstado(2);
		peso=a;
	}
}
void Perro::Alimentar(int comida){
	if(obtenerHambre()<=50){
		if(obtenerHambre()>0){
			switch(comida){
				case 1:
					asignarCalorias(obtenerCalorias()+10);
					asignarHambre(obtenerHambre()-2);
					break;
				case 2:
					peso++;
					asignarCalorias(obtenerCalorias()+10);
					altura=(peso/10)+1;
					asignarHambre(obtenerHambre()-3);
					break;
				case 3:
					peso++;
					peso++;
					asignarCalorias(obtenerCalorias()+20);
					altura=(peso/10)+1;
					asignarHambre(obtenerHambre()-5);
					break;
			}
		}
	}else{
		asignarEstado(2);
	}
}
void Perro::Moverse(int nx, int ny,int modo,int distancia){
int cont=0;

	if(obtenerEstado()==1){
		switch(modo){
			case 1:
				do{
					asignarCalorias(obtenerCalorias()-20);
					asignarHambre(obtenerHambre()+2);
					asignarSed(obtenerSed()+2);
					x=nx;
					y=ny;
					cont++;
				}while(cont<distancia);
				break;
			case 2:
				do{
					asignarCalorias(obtenerCalorias()-10);
					asignarHambre(obtenerHambre()+1);
					asignarSed(obtenerSed()+1);
					x=nx;
					y=ny;
					cont++;
				}while(cont<distancia);
				break;
		}
	}
}
void Perro::Tomar(int tipo){
	if(obtenerSed()<=50){
		if(obtenerSed()>0){
			switch(tipo){
				case 1:
					asignarSed(obtenerSed()-3);
					break;
				case 2:
					asignarSed(obtenerSed()-2);
					asignarHambre(obtenerHambre()+2);
					asignarCalorias(obtenerCalorias()+10);
					break;
			}
		}
	}else{
		asignarEstado(2);
	}
}