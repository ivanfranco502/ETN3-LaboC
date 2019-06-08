class Vector{
	private:
		int *Pri;
		int cantElem;
		void cargarElem(int,int,int,int);
	public:
		Vector();
		Vector(int,int,int,int);
		int obtenerCantElem();
		int obtenerNumDeter(int);
		char  *obtenerCadena();
		void graficarVector();
		void ordenarVector(int);
};
