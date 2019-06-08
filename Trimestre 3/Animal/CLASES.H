class Animal{
	private:
		int extremidades;
		int calorias;
		char *nombre;
		int especie;
		int hambre;
		int sed;
		int estado;
	public:
		Animal();
		Animal(int,int,char *,int);
	int obtenerExtremidades();
	int obtenerCalorias();
	char *obtenerNombre();
	int obtenerEspecie();
	int obtenerHambre();
	int obtenerSed();
	int obtenerEstado();
	void asignarExtremidades(int);
	void asignarCalorias(int);
	void asignarNombre(char *);
	void asignarEspecie(int);
};
