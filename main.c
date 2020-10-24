#include<stdio.h>
#include "CMatrixImp.h"
main()
{
	Matrix *m= newMatrix(2, 2, 'i');
	m->setN(m, 2.8);
	m->printM(m);
	m->setByDataSet(m, "DataSet.txt");
	
	printf("\n##########################\n");
	printf("Promedio: %.2f", m->avgM(m));
}
