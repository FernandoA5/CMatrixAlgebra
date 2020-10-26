#include<stdio.h>
#include "CMatrixImp.h"
main()
{
	//CREAR EL 'OBJETO' MATRIZ (FILAS, COLUMNAS, TIPO 'f' O 'i')
	Matrix *m= newMatrix(1, 1, 'f');
	
	// TOMAR DATOS DE UN ARCHIVO DE TEXTO Y GUARDARLOS EN LA MATRIZ REDIMENCIONANDOLA SI ES NECESARIO (MATRIZ, PATH) SI SOBRAN ESPACIOS EN LA MATRIZ SE LLENAN CON EL PROMEDIO
	m->setByDataSet(m, "DataSet.txt");
	
	//IMPRIMIR MATRIZ (MATRIZ)
	m->printM(m);
	printf("\n##########################\n");
	printf("Promedio: %.2f", m->avgM(m));
	printf("\n");
	printf("Moda: %.2f", m->getModa(m));
}
