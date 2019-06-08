class Animal{
	private:
		int extremidades;
		int calorias;
		char *nombre;
		int hambre;
		int sed;
		int estado;
	public:
		Animal();
		Animal(int,int,char *);
	int obtenerExtremidades();
	int obtenerCalorias();
	char *obtenerNombre();
	int obtenerHambre();
	int obtenerSed();
	int obtenerEstado();
	void asignarHambre(int);
	void asignarSed(int);
	void asignarEstado(int);
	void asignarCalorias(int);
	void asignarNombre(char *);
};

class Perro: public Animal{
	private:
		int peso;
		int x;
		int y;
		int altura;
	public:
		Perro();
		Perro(int,int, char *,int);
	int obtenerPeso();
	int obtenerX();
	int obtenerY();
	int obtenerAltura();
	void asignarAltura();
	void asignarPeso(int);
	void Alimentar(int);
	void Moverse(int,int,int,int);
	void Tomar(int);
};
