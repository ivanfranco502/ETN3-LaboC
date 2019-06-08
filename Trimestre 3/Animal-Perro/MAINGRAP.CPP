#include "clases.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <graphics.h>
#include <dos.h>
#include <time.h>
#include <alloc.h>
#include <math.h>

void main(void){

    void far *vecComida[3];
    void far *vecAgua[2];
    void far *Dog[2];
    int drv=DETECT,mdo;
	int intopc=0,pes=0,comida=0,tipo=0;
    char opc=NULL;
    unsigned int cal=0;
    unsigned int tam;
	int x,y,cont;
	int distancia;
	char *nom=(char *)(malloc(sizeof(char)*20));
	Perro *b=new Perro();

	clrscr();

	initgraph(&drv,&mdo,"C:\\BC\\BGI");

       for(cont=0;cont<7;cont++){
          switch(cont){
            case 0:
            //hueso
                 circle(20,20,4);
                 circle(20,15,4);
                 line(25,20,35,20);
                 line(25,15,35,15);
                 circle(40,20,4);
                 circle(40,15,4);

                 setfillstyle(SOLID_FILL,WHITE);
                 floodfill(20,20,WHITE);
                 setfillstyle(SOLID_FILL,WHITE);
                 floodfill(20,15,WHITE);
                 setfillstyle(SOLID_FILL,WHITE);
                 floodfill(20,17,WHITE);
                 setfillstyle(SOLID_FILL,WHITE);
                 floodfill(25,17,WHITE);
                 setfillstyle(SOLID_FILL,WHITE);
                 floodfill(40,20,WHITE);
                 setfillstyle(SOLID_FILL,WHITE);
                 floodfill(40,17,WHITE);
                 setfillstyle(SOLID_FILL,WHITE);
                 floodfill(40,15,WHITE);

                 tam=imagesize(16,11,44,24);
                 vecComida[0]=farmalloc(tam);
                 getimage(16,11,44,24,vecComida[0]);
                 cleardevice();
                 break;
            case 1:
            //alimento balanceado
                    arc(20,40,220,319,15);
                    line(9,49,9,45);
                    line(31,49,31,45);
                    arc(20,35,220,319,15);
                    arc(20,55,48,128,15);
                    circle(20,45,2);
                    circle(24,45,2);
                    circle(16,45,2);

                    setfillstyle(SOLID_FILL,WHITE);
                    floodfill(20,51,WHITE);
                    setfillstyle(SOLID_FILL,RED);
                    floodfill(20,45,WHITE);
                    setfillstyle(SOLID_FILL,GREEN);
                    floodfill(24,45,WHITE);
                    setfillstyle(SOLID_FILL,BLUE);
                    floodfill(16,45,WHITE);

                 tam=imagesize(9,35,31,55);
                 vecComida[1]=farmalloc(tam);
                 getimage(9,35,31,55,vecComida[1]);
                 cleardevice();
                 break;
            case 2:
            //carne

        arc(20,40,120,260,10);
        line(15,32,35,25);
        arc(35,35,355,90,10);
        arc(21,40,260,350,10);
        line(32,42,44,38);
        circle(20,40,2);

        setfillstyle(SOLID_FILL,RED);
        floodfill(23,40,WHITE);


                 tam=imagesize(10,25,45,50);
                 vecComida[2]=farmalloc(tam);
                 getimage(10,25,45,50,vecComida[2]);

                 cleardevice();
                 break;
            case 3:
            //agua
        arc(20,40,220,319,15);
        line(9,49,9,45);
        line(31,49,31,45);
        arc(20,35,220,319,15);
        arc(20,55,48,128,15);

        setfillstyle(SOLID_FILL,WHITE);
        floodfill(20,51,WHITE);
        setfillstyle(SOLID_FILL,LIGHTBLUE);
        floodfill(20,45,WHITE);

                 tam=imagesize(9,35,31,55);
                 vecAgua[0]=farmalloc(tam);
                 getimage(9,35,31,55,vecAgua[0]);
                 cleardevice();
                 break;
            case 4:
            //vitalizador
        arc(20,40,220,319,15);
        line(9,49,9,45);
        line(31,49,31,45);
        arc(20,35,220,319,15);
        arc(20,55,48,128,15);

        setfillstyle(SOLID_FILL,WHITE);
        floodfill(20,51,WHITE);
        setfillstyle(SOLID_FILL,GREEN);
        floodfill(20,45,WHITE);

                 tam=imagesize(9,35,31,55);
                 vecAgua[1]=farmalloc(tam);
                 getimage(9,35,31,55,vecAgua[1]);
                 cleardevice();
                 break;
            case 5:
            //perro

        //cabeza
        arc(50,40,230,140,15);
        line(37,32,20,35);
        line(40,52,27,50);
        line(20,35,27,50);
        line(24,44,34,46);
        circle(45,35,2);
        line(54,25,62,15);
        line(60,28,62,15);
        line(50,25,58,15);
        line(58,15,59,16);
        //cuerpo
        line(66,40,120,43);
        line(63,49,63,69);
        rectangle(66,69,55,73);
        line(66,55,66,69);
        line(66,60,100,60);
        line(100,55,100,60);
        line(100,60,110,65);
        line(110,65,110,69);
        line(115,55,113,69);
        rectangle(113,69,103,73);
        line(120,43,115,55);
        line(116,43,122,25);
        line(120,43,122,25);

        setfillstyle(SOLID_FILL,BROWN);
        floodfill(49,41,WHITE);
        setfillstyle(SOLID_FILL,BROWN);
        floodfill(70,45,WHITE);

                 tam=imagesize(20,15,122,73);
                 Dog[0]=farmalloc(tam);
                 getimage(20,15,122,73,Dog[0]);

				cleardevice();
                break;
            case 6:
            //perro

        //cabeza
        arc(50,40,230,140,15);
        line(37,32,20,35);
        line(40,52,27,50);
        line(20,35,27,50);
        line(24,44,34,46);

        line(42,32,47,37);
        line(47,32,42,37);

        line(54,25,62,15);
        line(60,28,62,15);
        line(50,25,58,15);
        line(58,15,59,16);
        //cuerpo
        line(66,40,120,43);
        line(63,49,63,69);
        rectangle(66,69,55,73);
        line(66,55,66,69);
        line(66,60,100,60);
        line(100,55,100,60);
        line(100,60,110,65);
        line(110,65,110,69);
        line(115,55,113,69);
        rectangle(113,69,103,73);
        line(120,43,115,55);
        line(116,43,122,25);
        line(120,43,122,25);

        setfillstyle(SOLID_FILL,BROWN);
        floodfill(49,41,WHITE);
        setfillstyle(SOLID_FILL,BROWN);
        floodfill(70,45,WHITE);

                 tam=imagesize(20,15,122,73);
                 Dog[1]=farmalloc(tam);
                 getimage(20,15,122,73,Dog[1]);

                cleardevice();
                break;
          }
       }
	   outtextxy(1,1,"Quiere crear un animal o uno por defecto?");
	   outtextxy(1,10,"Ingrese 1(uno) para un perro defecto, 2(dos) para uno creado por usted");
	   opc=getch();

          switch(opc){
		    case 49:
			     break;
		    case 50:
			     cleardevice();
			     outtextxy(50,1,"Ingrese la cantidad de calorias que tiene su perro:");
			     scanf("%i",&cal);
			     outtextxy(50,20,"Ingrese el nombre de su animal:");
			     scanf("%s",nom);
			     b->asignarCalorias(cal);
			     b->asignarNombre(nom);
			     outtextxy(50,40,"Ingrese el peso que tiene su perro:");
			     scanf("%i",&pes);
				 b->asignarPeso(pes);
				 b->asignarAltura();
			     break;
		  }
		  do{
             cleardevice();
			 outtextxy(50,4,"MENU");
             outtextxy(70,35,"Ver Caracteristicas");
			 outtextxy(70,65,"Alimentar");
			 outtextxy(70,95,"Hidratar");
			 outtextxy(70,125,"Movilizar");
			 outtextxy(70,155,"Salir");
			 do{
                do{
                }while(!kbhit());
                opc=getch();
                switch(opc){
                     case 'H':
                          intopc--;
                          if(intopc==0){
                             intopc=5;
                          }
                          break;
                     case 'P':
                          intopc++;
                          if(intopc==6){
                             intopc=1;
                          }
                          break;
                }
                switch(intopc){
                    case 1:
					     setcolor(BLACK);
					     rectangle(40,50,230,80);
					     rectangle(40,140,230,170);
					     setcolor(WHITE);
					     rectangle(40,30,230,60);
					     break;
				    case 2:
					     setcolor(BLACK);
					     rectangle(40,30,230,60);
					     rectangle(40,80,230,110);
					     setcolor(WHITE);
					     rectangle(40,50,230,80);
					     break;
				    case 3:
					     setcolor(BLACK);
					     rectangle(40,50,230,80);
					     rectangle(40,110,230,140);
					     setcolor(WHITE);
					     rectangle(40,80,230,110);
					     break;
				    case 4:
					     setcolor(BLACK);
					     rectangle(40,80,230,110);
					     rectangle(40,140,230,170);
					     setcolor(WHITE);
					     rectangle(40,110,230,140);
					     break;
				    case 5:
					     setcolor(BLACK);
					     rectangle(40,110,230,140);
					     rectangle(40,30,230,60);
					     setcolor(WHITE);
					     rectangle(40,140,230,170);
					     break;
			    }
		     }while(opc!=13);

		     if (opc==13){
             textcolor(BLACK);
			    switch(intopc){
                 case 1:
				     clrscr();
				     printf("Nombre: %s\n",b->obtenerNombre());
				     printf("Calorias: %i\n",b->obtenerCalorias());
				     printf("Hambre: %i\n",b->obtenerHambre());
				     printf("Sed: %i\n",b->obtenerSed());
				     switch(b->obtenerEstado()){
					    case 1:
						     printf("ESTADO: vivo\n");
                             putimage(300,50,Dog[0],COPY_PUT);
						     break;
					    case 2:
						     printf("ESTADO: muerto\n");
                             putimage(300,50,Dog[1],COPY_PUT);
						     break;
				     }
				     printf("Peso: %i\n",b->obtenerPeso());
				     printf("X=%i\n",b->obtenerX());
				     printf("Y=%i\n",b->obtenerY());
				     printf("Altura: %i\n",b->obtenerAltura());
				     getch();
				     break;
			     case 2:
				     clrscr();
					 if(b->obtenerEstado()==2){
					   printf("TU PERRO SE MURIO");
					   putimage(300,50,Dog[1],COPY_PUT);
					 }else{
						 printf("Que quiere darle al perro?\n");
						 printf("1-Hueso\n");
						 printf("2-Alimento balanceado\n");
						 printf("3-Carne\n");
						 putimage(300,50,Dog[0],COPY_PUT);
						 scanf("%i",&comida);
						 if(b->obtenerHambre()!=0){
							 b->Alimentar(comida);
							 switch(comida){
								case 1:
									 putimage(280,100,vecComida[0],COPY_PUT);
									 delay(2000);
									 putimage(280,100,vecComida[0],XOR_PUT);
									 break;
								case 2:
									 putimage(280,100,vecComida[1],COPY_PUT);
									 delay(2000);
									 putimage(280,100,vecComida[1],XOR_PUT);
									 break;
								case 3:
									 putimage(280,100,vecComida[2],COPY_PUT);
									 delay(2000);
									 putimage(280,100,vecComida[2],XOR_PUT);
									 break;
							 }
						 }else{
							outtextxy(300,35,"Su animal esta satisfecho");
						 }
					 }
					 getch();
					 break;

				 case 3:
					 clrscr();
					 if(b->obtenerEstado()==2){
					   printf("TU PERRO SE MURIO");
					   putimage(300,50,Dog[1],COPY_PUT);
					 }else{
						 printf("Que quiere darle al perro?\n");
						 printf("1-Agua\n");
						 printf("2-Vitalizador\n");
						 putimage(300,50,Dog[0],COPY_PUT);
						 scanf("%i",&tipo);
						 if(b->obtenerSed()!=0){
							 b->Tomar(tipo);
							 switch(tipo){
								case 1:
									 putimage(280,100,vecAgua[0],COPY_PUT);
									 delay(2000);
									 putimage(280,100,vecAgua[0],XOR_PUT);
									 break;
								case 2:
									 putimage(280,100,vecAgua[1],COPY_PUT);
									 delay(2000);
									 putimage(280,100,vecAgua[1],XOR_PUT);
									 break;
							 }
						 }else{
							outtextxy(300,35,"Su animal esta satisfecho");
						 }
					 }
					 getch();
					 break;

				 case 4:
					 clrscr();
					 if(b->obtenerEstado()==2){
					   printf("TU PERRO SE MURIO");
					   putimage(300,50,Dog[1],COPY_PUT);
					 }else{
						printf("Valor de x nuevo: \n");
						 scanf("%i",&x);
						 printf("Valor de y nuevo: \n");
						 scanf("%i",&y);
						 printf("Corriendo(1) o Caminando(2)\n");
						 putimage(300,50,Dog[0],COPY_PUT);
						 scanf("%i",&tipo);
						 distancia=sqrt((pow(b->obtenerX()-x,2))+(pow(b->obtenerY()-y,2)));
						 b->Moverse(x,y,tipo,distancia);
						 x=0;
						 switch(tipo){
							case 1:
								do{
									delay(100);
									putimage(300,50,Dog[0],XOR_PUT);
									putimage(290,50,Dog[0],COPY_PUT);
									delay(100);
									putimage(290,50,Dog[0],XOR_PUT);
									putimage(300,50,Dog[0],COPY_PUT);
									x++;
								 }while(x<10);
								 break;
							case 2:
								do{
									delay(300);
									putimage(300,50,Dog[0],XOR_PUT);
									putimage(290,50,Dog[0],COPY_PUT);
									delay(300);
									putimage(290,50,Dog[0],XOR_PUT);
									putimage(300,50,Dog[0],COPY_PUT);
									x++;
								 }while(x<10);
								 break;
						 }
					 }
					 getch();
					 break;
				}
			 }
		  }while(intopc!=5);
	closegraph();
}

/*
switch(cont){
   case 0://hueso
        circle(20,20,4);
        circle(20,15,4);
        line(25,20,35,20);
        line(25,15,35,15);
        circle(40,20,4);
        circle(40,15,4);

        setfillstyle(SOLID_FILL,WHITE);
        floodfill(20,20,WHITE);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(20,15,WHITE);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(20,17,WHITE);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(25,17,WHITE);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(40,20,WHITE);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(40,17,WHITE);
        setfillstyle(SOLID_FILL,WHITE);
        floodfill(40,15,WHITE);

        break;*//*
   case 1://Alimento Balanceado
        arc(20,40,220,319,15);
        line(9,49,9,45);
        line(31,49,31,45);
        arc(20,35,220,319,15);
        arc(20,55,48,128,15);
        circle(20,45,2);
        circle(24,45,2);
        circle(16,45,2);

        setfillstyle(SOLID_FILL,WHITE);
        floodfill(20,51,WHITE);
        setfillstyle(SOLID_FILL,RED);
        floodfill(20,45,WHITE);
        setfillstyle(SOLID_FILL,GREEN);
        floodfill(24,45,WHITE);
        setfillstyle(SOLID_FILL,BLUE);
        floodfill(16,45,WHITE);

        break;    */
/*   case 2://Carne
        arc(20,40,120,260,10);
        line(15,32,35,25);
        arc(35,35,355,90,10);
        arc(21,40,260,350,10);
        line(32,42,44,38);
        circle(20,40,2);

        setfillstyle(SOLID_FILL,RED);
        floodfill(23,40,WHITE);

        break;*/
/*   case 3://AGUA
        arc(20,40,220,319,15);
        line(9,49,9,45);
        line(31,49,31,45);
        arc(20,35,220,319,15);
        arc(20,55,48,128,15);

        setfillstyle(SOLID_FILL,WHITE);
        floodfill(20,51,WHITE);
        setfillstyle(SOLID_FILL,LIGHTBLUE);
        floodfill(20,45,WHITE);

        break;*/
/*   case 4://vitalizador
        arc(20,40,220,319,15);
        line(9,49,9,45);
        line(31,49,31,45);
        arc(20,35,220,319,15);
        arc(20,55,48,128,15);

        setfillstyle(SOLID_FILL,WHITE);
        floodfill(20,51,WHITE);
        setfillstyle(SOLID_FILL,GREEN);
        floodfill(20,45,WHITE);
*/
/*        break;
   case 5://Perrito
        //cabeza
        arc(50,40,230,140,15);
        line(37,32,20,35);
        line(40,52,27,50);
        line(20,35,27,50);
        line(24,44,34,46);
        circle(45,35,2);
        line(54,25,62,15);
        line(60,28,62,15);
        line(50,25,58,15);
        line(58,15,59,16);
        //cuerpo
        line(66,40,120,43);
        line(63,49,63,69);
        rectangle(66,69,55,73);
        line(66,55,66,69);
        line(66,60,100,60);
        line(100,55,100,60);
        line(100,60,110,65);
        line(110,65,110,69);
        line(115,55,113,69);
        rectangle(113,69,103,73);
        line(120,43,115,55);
        line(116,43,122,25);
        line(120,43,122,25);

        setfillstyle(SOLID_FILL,BROWN);
        floodfill(49,41,WHITE);
        setfillstyle(SOLID_FILL,BROWN);
        floodfill(70,45,WHITE);

        break;
}
}*/