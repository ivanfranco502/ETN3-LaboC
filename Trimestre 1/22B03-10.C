/*CONSIGNA
Hacer un programa que permita indicar si un numero es divisible por tres,
utilizando una funcion recursiva (int esDivisiblePorTres(int);) que recibe
como parametro un entero y devuelve un 1 si ese numero es divisible o un
cero si no lo es.

TIP: Cuando un numero es divisible por 3 la suma de sus digitos tambien
lo es.
*/

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int boolTres (int n);//funcion booleana si es divisible por tres

void main(void){
int n=0;
clrscr();//borra pantalla
printf("Ingrese el numero a analizar si es divisible por 3: ");
scanf("%i", &n);//tomo el valor del numero ingresado
	if (boolTres(n)==0){//si booltres es igual a 0
		//el numero es divisible
		printf("El numero es divisible por tres");
	}else{
		//si bool<>0 entonces no es divisible
		printf("El numero no es divisible por tres");
	}
getch();
}
int boolTres (int n){ //funcion booltres que da si es divisible por tres
int a=0;
//cuenta que hace que se sumen los digitos del numero
a=n/100+(n/10-n/100*10)+(n-(n/10*10));

	if (a/3<=3 && a%3==0){//si la suma de los dig del numero/3 es <=3
	//Y el resto de a/3=0, entonces es divisible a tres
		return(0);
	}else{//sino cumple alguna de estas condiciones entonces
		if (a/3<=3 && a%3!=0){
		//si suma dig num/3 <=3 Y el resto de A/3 <>0, no es divisible por tres
			return(1);
		}else{
			return(boolTres(a));
			/*sino, entonces se llama de nuevo a la funcion pero en vez
			del numero es la suma de sus digitos para ver si este, es
			divisible por tres*/
		}
	}
}