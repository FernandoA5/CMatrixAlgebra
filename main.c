#include<stdio.h>
#include<math.h>
#include "CMatrixImp.h"
main()
{
	Matrix *m= newMatrix(10, 15, 'i');
	m->printM(m);
}
