typedef struct Matrix Matrix;

struct Matrix{
	int **iM;
	float **fM;
	int filas;
	int columnas;
	char tipo;
	
	//METODOS
	void (* setSize)(Matrix *this);
	void (* setN)(Matrix *this, float N);
	void (* printM)(Matrix *this);
	float (* avgM)(Matrix *this);
	void (* setByDataSet)(Matrix *this, char []);
	void (* setSmartSize)(Matrix *this, int);
	float (* getModa)(Matrix *this);
};
//DECLARACIÓN DE LOS METODOS

void mSetSize(Matrix *this);
void mPrintM(Matrix *this);
void mSetN(Matrix *this, float N);
float mAvgM(Matrix *this);
void mSetByDataSet(Matrix *this, char []);
void mSetSmartSize(Matrix *this, int);
float mGetModa(Matrix *this);
//CONSTRUCTOR
Matrix * newMatrix(int f, int c, char t);


