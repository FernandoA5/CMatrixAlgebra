#include "CMatrixAlgebra.h"
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

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
	m->avgM=mAvgM;
	m->setByDataSet=mSetByDataSet;
	m->setSmartSize=mSetSmartSize;
	
	
	m->setSize(m);
	return m;
}
//METODOS
/*------------------------SETBYDATASET---------------------------------------*/
void mSetByDataSet(Matrix *this, char dir[])
{
	char aux[10]; int contador=0, i, sub1=0, sub2; float *nums;
	//ABRIMOS EL ARCHIVO
	FILE *f=fopen(dir, "r");
	printf("%s", (f==NULL)?"Error al abrir el archivo\n":"Archivo Abierto con exito\n");
	//CONTAMOS LOS NUMEROS Y LOS GUARDAMOS EN UN ARREGLO
	while(!feof(f))
	{
		fgets(aux, 10, f);
		contador++;
		nums=realloc(nums, sizeof(float)*contador);
		nums[contador-1]=atof(aux);
	}
	rewind(f);
	//CAMBIAMOS EL TAMAÑO DE LA MATRIZ PARA ALMACENAR LOS DATOS OBTENIDOS DEL ARCHIVO
	mSetSmartSize(this, contador);
	//GUARDAMOS LOS DATOS DEL ARCHIVO
	printf("\n");
	if(this->tipo=='i')
	{
		for(i=0; i<this->filas*this->columnas; i++)
		{
			sub1=(sub2==this->columnas-1)?sub1+1:sub1;
			sub2=i%this->columnas;
			this->iM[sub1][sub2]=(i<contador)?(int)nums[i]:0;				
		}
	}
	else if(this->tipo=='f')
	{
		for(i=0; i<this->filas*this->columnas; i++)
		{
			sub1=(sub2==this->columnas-1)?sub1+1:sub1;
			sub2=i%this->columnas;
			this->fM[sub1][sub2]=(i<contador)?nums[i]:0;				
		}
	}
	
	fclose(f);
}
/*------------------------SETSMARTSIZE---------------------------------------*/
void mSetSmartSize(Matrix *this, int n)
{
	int a, b;
	a=(int)sqrt(n);
	do{
		b++;
	}while(a*b<n);
	this->filas=a;
	this->columnas=b;
	mSetSize(this);
	printf("Fil:%d || Col: %d", a, b);
}
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
//------------------------------------PROMEDIO------------------------------------------
float mAvgM(Matrix *this)
{
	int i, j; float sum=0;
	if(this->tipo=='i')
	{
		for(i=0;i<this->filas; i++)
		{
			for(j=0; j<this->columnas; j++)
			{
				sum+=this->iM[i][j];
			}
		}
	}
	else if(this->tipo=='f')
	{
		for(i=0;i<this->filas; i++)
		{
			for(j=0; j<this->columnas; j++)
			{
				sum+=this->fM[i][j];
			}
		}
	}
	return (sum/(this->filas*this->columnas));
}
//------------------------------------ASIGNAR N A TODOS LOS CAMPOS DE LA MATRIZ------------------------------------------
void mSetN(Matrix *this, float N){
	int i, j;
	if(this->tipo=='i')
	{
		for(i=0; i<this->filas; i++)
		{
			for(j=0; j<this->columnas; j++)
			{
				this->iM[i][j]=floor(N);
			}
		}
	}
	else if(this->tipo=='f')
	{
		for(i=0; i<this->filas; i++)
		{
			for(j=0; j<this->columnas; j++)
			{
				this->fM[i][j]=N;
			}
		}
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
				printf(" [%d] ", this->iM[i][j]);
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
				printf(" [%.2f] ", this->fM[i][j]);
			}
			printf("\n");
		}
	}
}
