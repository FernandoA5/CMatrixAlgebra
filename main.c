#include<stdio.h>
#include "CMatrixImp.h"
main()
{
	Matrix *m= newMatrix(4, 3, 'f');
	//m->setN(m, 2);
	m->setByDataSet(m, "DataSet.txt");
	m->printM(m);
	printf("\n##########################\n");
	printf("Promedio: %.2f", m->avgM(m));
}
