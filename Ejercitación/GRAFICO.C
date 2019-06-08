#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>

void mover (int,int,int);

void main(void){
int tec;
int drv=DETECT,mdo;
int x=100,y=100;
initgraph(&drv,&mdo,"C:\\BC\\BGI");
cleardevice();
pieslice(x,y,15,290,15);
	do{
		tec=getch();
		mover(tec,x,y);
	}while (tec!=13);
closegraph();
}
void mover(int tec,int x, int y){
	switch(tec){
		case 8:{//ARRIBA
			cleardevice();
			pieslice(x,y+2,45,135,100);
			break;
		}
		case 2:{//ABAJO
			cleardevice();
			pieslice(x,y-2,45,135,100);
			break;
		}
		case 6:{//DERECHA
			cleardevice();
			pieslice(x+2,y,45,135,100);
			break;
		}case 4:{//IZQUIERDA
			cleardevice();
			pieslice(x-2,y,45,135,100);
			break;
		}
	}
}