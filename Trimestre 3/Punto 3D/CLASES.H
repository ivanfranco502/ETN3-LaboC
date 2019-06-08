class Punto{
	private:
		int x;
		int y;
	public:
		Punto();
		Punto(int,int);
	void asignarX(int);
	void asignarY(int);
	int obtenerX();
	int obtenerY();
};

class Punto3D:public Punto{
	private:
		int z;
	public:
		Punto3D();
		Punto3D(int,int,int);
	void asignarZ(int);
	int obtenerZ();
};