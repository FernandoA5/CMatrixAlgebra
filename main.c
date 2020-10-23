#include<stdio.h>
#include<math.h>
#include "CMatrixAlgebra.h"
main()
{
	/*Matrix m = Matrix(5, 5, 'i');
	m.determinante();
	m.printM();*/
	
	setMatrix(5,5, 'i');
	setSize();
	setN(2);
	printM();
}
