#include "poligono.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <alloc.h>

Poligono::Poligono(int cantlad,int *lon){
int i;
	cantlados=cantlad;
	longitud=(int *)(malloc(sizeof(int)*cantlados));
	for (i=0;i<cantlados;i++){
		longitud[i]=lon[i];
	}
}
int Poligono::obtenerCantLados(){
	return(cantlados);
}
int Poligono::obtenerLongitud(int pos){
	return(longitud[pos]);
}
int Poligono::calcularPerimetro(){
	int suma,i;

	for(i=0;i<cantlados;i++){
		suma+=longitud[i];
	}
	return(suma);
}

Triangulo::Triangulo(int cantlad,int *lon):Poligono(cantlad,lon){

}
int Triangulo::calcularSup(){
	int sup;

	sup=(obtenerLongitud(0)*obtenerLongitud(1))/2;
	return(sup);

}
Cuadrado::Cuadrado(int cantlad,int *lon):Poligono(cantlad,lon){

}
int Cuadrado::calcularSup(){
	int sup;

	sup=obtenerLongitud(0)*obtenerLongitud(1);
	return(sup);
}