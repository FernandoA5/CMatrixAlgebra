#include "CMatrixAlgebra.h"
#include<stdlib.h>
#include<stdio.h>

//CONSTRUCTOR
Matrix * newMatrix(int f, int c, char t){
	Matrix *m;
	m = malloc(sizeof(struct Matrix));
	m->filas=f;
	m->columnas=c;
	m->tipo=t;
	m->setSize= mSetSize;
	m->printM=mPrintM;
	m->setN=mSetN;
	
	
	m->setSize(m);
	return m;
}
//METODOS

//--------------------------------ASIGNAR TAMAÑO A LA MATRIZ-----------------------------------
void mSetSize(Matrix *this){
	int i;
	if(this->tipo=='i')
	{
		this->iM=(int **)malloc(this->filas*sizeof(int *));
		for(i=0; i<this->filas; i++)
		{
			this->iM[i]=(int *)malloc(this->columnas*sizeof(int));
		}
	}
	else if(this->tipo=='f'){
		this->fM=(float **)malloc(this->filas*sizeof(float *));
		for(i=0; i<this->filas; i++)
		{
			this->fM[i]=(float *)malloc(this->columnas*sizeof(float));
		}
	}
}
void mSetN(Matrix *this, int N){
	int i, j;
	if(this->tipo='i')
	{
		
	}
	else if()
	{
		
	}
}
//------------------------------------IMPRIMIR MATRIZ------------------------------------------
void mPrintM(Matrix *this)
{
	int i, j;
	if(this->tipo=='i')
	{
		for(i=0; i<this->filas; i++)
		{
			for(j=0; j<this->columnas; j++)
			{
				printf(" [] ");
			}
			printf("\n");
		}
	}
	else if(this->tipo=='f')
	{
		for(i=0; i<this->filas; i++)
		{
			for(j=0; j<this->columnas; j++)
			{
				printf(" [] ");
			}
			printf("\n");
		}
	}
}
