#include<stdio.h>
#include "CMatrixImp.h"
main()
{
	Matrix *m= newMatrix(4, 5, 'f');
	m->setN(m, 2.8);
	m->printM(m);
}
