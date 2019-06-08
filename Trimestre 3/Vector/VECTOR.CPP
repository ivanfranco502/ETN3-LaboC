#include "vector.h"
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdio.h>

Vector::Vector(){

	Pri=(int *)(malloc(sizeof(int)*10));
	cantElem=10;
	cargarElem(0,1,0,10);

}
Vector::Vector(int a,int b,int c,int d){

	Pri=(int *)(malloc(sizeof(int)*a));
	cantElem=a;
	if(b<c){
		if((c-b<a) && d==0){
			cargarElem(b,c,d,cantElem);
		}else{
			if(c-b>a){
				cargarElem(b,c,d,cantElem);
			}
		}
	}

}

void Vector::cargarElem(int min, int may,int rep,int cantelem){

int indice=0,num=NULL;
int esta=0,ind=0;

	switch(rep){
		case 1://no se repiten
			do{
				do{
					num=(random(may-min))+min;
					do{
						if(Pri[indice]==num){
							esta=1;
						}
						indice++;
					}while(!(indice>=cantelem || esta==0));
				}while(esta!=0);
				Pri[ind]=num;
				ind++;
			}while(ind<cantelem);

		case 0://se repiten
			do{
				num=(random(may-min))+min;
				Pri[ind]=num;
				ind++;
			}while(ind<cantelem);
	}
}
int Vector::obtenerCantElem(){
	return(cantElem);
}
int Vector::obtenerNumDeter(int a){
	return(Pri[a]);
}
char *Vector::obtenerCadena(){
//[e1,e2,e3,...,en]
	int indice;

	printf("[");
	for(indice=0;indice<cantElem;indice++){
		if (indice!=cantElem-1){
			printf("%i,",Pri[indice]);
		}else{
			printf("%i]",Pri[indice]);
		}
	}

}
/*void Vector::graficarVector(){

}
void Vector::ordenarVector(int a){

} */