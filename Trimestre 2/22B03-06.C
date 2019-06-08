/*CONSIGNA

Programar un Juego. El mismo deber  cumplir con las siguiente pautas:

	-Debe existir un personaje principal, que ser  manejado por el usuario del
	programa.
	-Al menos dos personajes que ser n los enemigos, y ser n controladas sus
	acciones por la m quina.
	-Deben desarrollarse al menos dos escenarios o niveles, y estos deben
	cargarse desde un archivo de texto.
	-Debe tener tres botones para NUEVO-INICIAR-SALIR, que ser n operados con
	el mouse.
	-Se deben implementar captura de im genes en variables.

*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <alloc.h>
#include <graphics.h>
#include <dos.h>
#include <bios.h>
#include <time.h>
#include <string.h>

#define ARRIBA 0x4800
#define ABAJO 0x5000
#define ESC 0x11b

void abrir(int *);
void guardar(int, char [4]);
void Dibujar(int,int);
void Menu(void);
int Menu2(void);

void main(void){
	void far *vecPlayer[2];
	void far *Ball;
	unsigned int tam;
	int drv=DETECT, mdo;
	int cont, y1,tecla;
	int YB,XB,auxp;
	int bandera=1;
    int nivel,puntaje=0,contador=0;
    char puntajeT[2];

		initgraph(&drv,&mdo,"C:\\BC\\BGI");

		for(cont=0;cont<2;cont++){
			Dibujar(cont,1);
			if(cont==0){
				tam=imagesize(0,0,22,92);
				vecPlayer[cont]=farmalloc(tam);
				getimage(0,0,22,92,vecPlayer[cont]);
				cleardevice();
			}else{
				tam=imagesize(0,0,20,getmaxy());
				vecPlayer[cont]=farmalloc(tam);
				getimage(0,0,20,getmaxy(),vecPlayer[cont]);
				cleardevice();
			}
		}

		cont=0;
		Dibujar(cont,0);

		tam=imagesize(0,0,16,16);
		Ball=farmalloc(tam);
		getimage(0,0,16,16,Ball);
		do{
			cleardevice();
			Menu();
            cleardevice();
            nivel=Menu2();
            bandera=1;
			cleardevice();
			y1=((getmaxy())/2)-45;

            switch (nivel){
              case 0:
                   nivel = 5;
                   break;
              case 1:
                   nivel=10;
                   break;
            }
            strset(puntajeT,NULL);
            puntaje=NULL;
            switch (contador){
              case 0:
                   YB=(getmaxy())/2;
                   XB=((getmaxx())/2);
                   break;
              case 1:
                   YB=((getmaxy())/2)+200;
                   XB=((getmaxx())/2)+100;
                   break;
              case 2:
                   YB=((getmaxy())/2)-200;
                   XB=((getmaxx())/2)-100;
                   break;
              case 3:
                   YB=((getmaxy())/2)-200;
                   XB=((getmaxx())/2)+100;
                   break;
              case 4:
                   YB=((getmaxy())/2)+200;
                   XB=((getmaxx())/2)-100;
                   break;
            }

			putimage(5,y1,vecPlayer[0],COPY_PUT);
			putimage((getmaxx())-25,0,vecPlayer[1],COPY_PUT);
			putimage(XB,YB,Ball,COPY_PUT);
            line(0,0,getmaxx(),0);
            line(0,getmaxy(),getmaxx(),getmaxy());
			do{
				if(bioskey(1)){
					tecla=bioskey(0);
				}else{
					tecla=0;
				}
				switch(tecla){
					case ARRIBA:
						if(y1-nivel>=0){
							putimage(5,y1,vecPlayer[0],XOR_PUT);
							y1-=nivel;
							putimage(5,y1,vecPlayer[0],COPY_PUT);
						}
						break;
					case ABAJO:
						if(y1+nivel<=((getmaxy())-91)){
							putimage(5,y1,vecPlayer[0],XOR_PUT);
							y1+=nivel;
							putimage(5,y1,vecPlayer[0],COPY_PUT);
						}
						break;
				}

				switch(bandera){
                    case 0:
                        if(XB<20){
						   if(!(YB-8>y1 && YB+8<y1+90)){
                              tecla=ESC;
                              outtextxy((getmaxx()/2)-15,getmaxy()/2,"PERDISTE");
                              delay(1500);
                           }
						}
                        if(tecla!=ESC){
						   putimage(XB,YB,Ball,XOR_PUT);
                           YB-=5;
                           XB-=5;
                           putimage(XB,YB,Ball,COPY_PUT);
                           if(YB-5<=0){
						      bandera=3;
                           }
                           if(XB-5<25 && (getpixel(XB-4,YB)==WHITE)){
                              bandera=2;
                              puntaje++;
                           }
                        }
                        break;

					case 1:
						putimage(XB,YB,Ball,XOR_PUT);
						YB+=5;
                        XB+=5;
						putimage(XB,YB,Ball,COPY_PUT);
						if (YB+5>(getmaxy()-16)){
                           bandera=2;
                        }
                        if (XB+5>((getmaxx())-45)){
                            bandera=3;
						}
						break;
                    case 2:
                         putimage(XB,YB,Ball,XOR_PUT);
                         YB-=5;
                         XB+=5;
                         putimage(XB,YB,Ball,COPY_PUT);
                         if(YB-5<=0){
						      bandera=1;
                         }
                         if (XB+5>((getmaxx())-45)){
                            bandera=0;
						 }
                         break;
                    case 3:
                         if(XB<20){
                           if(!(YB-8>y1 && YB+8<y1+90)){
                              tecla=ESC;
                              outtextxy((getmaxx()/2)-15,getmaxy()/2,"PERDISTE");
                              delay(1500);
                           }
						 }
                         if(tecla!=ESC){
                           putimage(XB,YB,Ball,XOR_PUT);
                           YB+=5;
                           XB-=5;
                           putimage(XB,YB,Ball,COPY_PUT);
                         }
                         if(XB-5<25 && (getpixel(XB-4,YB)==WHITE)){
                              bandera=1;
                              puntaje++;
                         }
                         if (YB+5>(getmaxy()-16)){
                           bandera=0;
                         }
                }

			delay(50);
            if (puntaje==50){
               tecla=ESC;
               outtextxy((getmaxx()/2)-15,getmaxy()/2,"GANASTE");
               delay(1500);
            }
			}while(tecla!=ESC);
            cleardevice();
            sprintf(puntajeT,"%i",(puntaje*100));
            outtextxy(getmaxx()/2,(getmaxy()/2)-50,"TU PUNTAJE: ");
            outtextxy(getmaxx()/2,getmaxy()/2,puntajeT);
            delay(3500);
            contador++;
            if (contador==4){
               contador=0;
            }
		}while(cont!=-4);
	closegraph();
}
void Menu(void){
	int px,py,btn;
	int bandera=0;

	_AX=0x00;
	geninterrupt(0x33);
	_AX=0x01;
	geninterrupt(0x33);
	rectangle(200,100,300,150);//empezar
	outtextxy(220,120,"EMPEZAR");

	rectangle(200,170,300,220);//salir
	outtextxy(220,190," EXIT ");

	do{
		_AX=0x03;
		geninterrupt(0x33);
		btn=_BX;
		px=_CX;
		py=_DX;
		if(px>=200 && px<=300 && py>=100 &&py<=150 && btn==1){
			bandera=1; //empieza
			_AX=0x02;
			geninterrupt(0x33);
		}
		if(px >=200 && px<=300 && py >=170 && py <=220 && btn==1){
			closegraph();
			exit(0);
		}
	}while(bandera!=1);
}
int Menu2(void){
	int px,py,btn;
	int bandera=2;

	_AX=0x00;
	geninterrupt(0x33);
	_AX=0x01;
	geninterrupt(0x33);
    outtextxy(200,50,"****NIVEL****");
	rectangle(200,100,300,150);//empezar
	outtextxy(220,120,"FACIL");

	rectangle(200,170,300,220);//dificil
	outtextxy(220,190,"DIFICIL");

	do{
		_AX=0x03;
		geninterrupt(0x33);
		btn=_BX;
		px=_CX;
		py=_DX;
		if(px>=200 && px<=300 && py>=100 &&py<=150 && btn==1){
			bandera=1; //empieza
			_AX=0x02;
			geninterrupt(0x33);
		}
		if(px >=200 && px<=300 && py >=170 && py <=220 && btn==1){
			bandera=0;
            _AX=0x02;
            geninterrupt(0x33);
		}
	}while(!(bandera==1 || bandera==0));
return(bandera);
}
void Dibujar(int y,int mdo){

	if(mdo==1){
		switch(y){
			case 0:
				rectangle(1,1,21,91);
				setfillstyle(SOLID_FILL,WHITE);
				floodfill(10,45,WHITE);
				break;
			case 1:
				rectangle(0,0,20,getmaxy());
				setfillstyle(SOLID_FILL,BLUE);
				floodfill(10,45,WHITE);
				break;
		}
	}else{
		circle(8,8,8);
		setfillstyle(SOLID_FILL,GREEN);
		floodfill(4,4,WHITE);
	}
}