#include "Clases.h"
Punto::Punto(){
	x=0;
	y=0;
}
Punto::Punto(int a, int b){
	x=a;
	y=b;
}
void Punto::asignarX(int a){
	x=a;
}
void Punto::asignarY(int a){
	y=a;
}
int Punto::obtenerX(){
	return(x);
}
int Punto::obtenerY(){
	return(y);
}
Punto3D::Punto3D():Punto(){
	z=0;
}
Punto3D::Punto3D(int a, int b, int c):Punto(a,b){
	z=c;
}
void Punto3D::asignarZ(int a){
	z=a;
}
int Punto3D::obtenerZ(){
	return(z);
}