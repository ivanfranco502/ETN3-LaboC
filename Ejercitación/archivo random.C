//--------------------------------------------------------------------------
// Ejemplo de Escritura y lectura de archivos binarios.
// by SDi(c)
//--------------------------------------------------------------------------
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char  Ape[11];
	char  Nom[11];
	float Sueldo;
} EMPLEADOS;

void altaEmpleado(void);
void listEmpleado(void);

void main(void) {
	int opc;

	clrscr();

	gotoxy(5, 3); puts("1) Alta de Empleados   ");
	gotoxy(5, 4); puts("2) Listado de Empleados");
	gotoxy(5, 5); puts("0) Salir               ");
	gotoxy(5, 6); puts("Ingrese Opci¢n: ");

	do {
		gotoxy(25, 6);
		scanf("%i", &opc);

		switch(opc) {
			case 1:
				altaEmpleado();
				break;
			case 2:
				listEmpleado();
				break;
		}
	} while(opc != 0);
	puts("Bye...");
}

void altaEmpleado(void) {
	FILE 		*pf;
	EMPLEADOS	e;

	pf = fopen("c:\\temp\\empleado.dat","rb");
	if(pf == NULL) {
		fclose(pf);
		pf = fopen("c:\\temp\\empleado.dat","wb");
	} else {
		fclose(pf);
		pf = fopen("c:\\temp\\empleado.dat","ab");
	}

	gotoxy( 5, 10); puts("Apellido: ");
	gotoxy(25, 10); scanf("%s", e.Ape);
	gotoxy( 5, 11); puts("Nombre  : ");
	gotoxy(25, 11); scanf("%s", e.Nom);
	gotoxy( 5, 12); puts("Sueldo  : ");
	gotoxy(25, 12); scanf("%f", &e.Sueldo);

	fseek(pf,0L, SEEK_END);
	fwrite(&e, sizeof(EMPLEADOS), 1, pf);

	fclose(pf);

	gotoxy(1, 10); clreol();
	gotoxy(1, 11); clreol();
	gotoxy(1, 12); clreol();
}

void listEmpleado(void) {

	FILE 		*pf;
	EMPLEADOS	e;
	int			fila = 10;
	int			i;

	pf = fopen("c:\\temp\\empleado.dat","rb");

	gotoxy(5, 8); puts("Apellido\tNombre\tSueldo");
	gotoxy(5, 9); puts("-----------------------------------------------------------");

	fseek(pf, 0L, SEEK_SET);
	fread(&e, sizeof(EMPLEADOS), 1, pf);

	while(!feof(pf)) {
		gotoxy(5, fila);
		printf("%s\t\t%s\t\t%.2f", e.Ape, e.Nom, e.Sueldo);
		fila++;
		fread(&e, sizeof(EMPLEADOS), 1, pf);
	}

	fclose(pf);

	getch();

	for(i = 7; i < 23; i++) {
		gotoxy(1, i);
		clreol();
	}

}
