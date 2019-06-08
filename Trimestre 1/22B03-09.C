/*CONSIGNA
Hacer una funcion recursiva que dado un entero sin signo, devuelve, segun
el parametro entero, el valor del termino de la sucesion o el resultado de
la serie de fibonacci. La funcion debera tener el siguiente prototipo:
	"unsigned long fibonacci (unsigned int,int);"
Sabiendo que para calcular el termino n de la sucesion se utiliza:
		   _
		  | 0				si n=1
	F(n)=<| 1				si n=2
		  | F(n-1)+F(n-2)   si n>2
		   -
Y que la serie hasta el termino n es:

		  n
	F(n)= E   F(i)
		 i=0
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

unsigned long fibonacci (unsigned int,int);//funcion con fibonacci %2

void main (void){
int n=0,sucesion=0;

clrscr();//borro pantalla
printf ("Ingrese el numero el indice para Fibonacci: ");
scanf ("%i",&n);//tomo el numero ingresado
printf ("Que quiere hacer (0=Valor/1=Serie)");
scanf ("%i",&sucesion);//veo si quiere el valor o la serie de numeros
if (sucesion==0){//si el usuario puso 0
	printf("El numero que se encuentra en esa posici¢n es: %i",fibonacci(n,sucesion));
	//llamo a la funcion fibo con sucesion =0
}else{
   printf(" %i",fibonacci(n,sucesion));
   //sino, llamo a la funcion fibo con sucesion <>0
}
getch();
}
unsigned long fibonacci (unsigned int n,int sucesion){
if (sucesion==0){//si sucesion es = 0
	switch (n) { //select case del numero
		case 1: return(0); break;//si el numero es =1, entonces fibo=0
		case 2: return(1); break;//si el numero es =2, entonces fibo=1
		default:return (fibonacci(n-1,sucesion)+fibonacci(n-2,sucesion));break;
		//sino, fibo(n-1)+fibo(n-2)
	}
}else{//si sucesion es <>0 entonces
	if(n==1){ //si n=1
		return(0);//devuelve 0
	}
	printf(" %i -",fibonacci(n-1,1));//mostrar fibo(n-1)
	return(fibonacci(n,0));//devuelve fibo del numero
}
}
