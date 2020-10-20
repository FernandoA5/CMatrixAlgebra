#include<stdio.h>
#include "CMatrixAlgebra.c"
main()
{
	Matrix m = Matrix(3, 4, 'i');
	m.setN(1);
	m.printM();
}
