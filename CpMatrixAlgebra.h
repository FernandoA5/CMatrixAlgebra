#include<stdio.h>
#include<stdlib.h>
struct Matrix{
	int **iM;
	float **fM;
	int filas;
	int columnas;
	char tipo;
	
	public:Matrix(int f, int c, char t)
	{
		this->filas=f;
		this->columnas=c;
		this->tipo=t;
		setSize(this->tipo);
	}
	void setSize(char t)
	{
		if(t=='i')
		{
			iM=(int **)malloc(this->filas*sizeof(int *));
			for(auto int i=0; i<this->filas; i++)
			{
				iM[i]=(int *)malloc(this->columnas*sizeof(int));
			}	
		}
		else if(t=='f')
		{
			fM=(float **)malloc(this->filas*sizeof(float *));
			for(auto int i=0; i<this->filas;i++)
			{
				fM[i]=(float *)malloc(this->columnas*sizeof(float));
			}
		}
	}
	void setN(float n)
	{
		if(this->tipo=='i')
		{
			for(auto int i=0; i<this->filas; i++)
			{
				for(auto int j=0; j<this->columnas; j++)
				{
					iM[i][j]=n;
				}
			}
		}
		else if(this->tipo=='f')
		{
			for(auto int i=0; i<this->filas; i++)
			{
				for(auto int j=0; j<this->columnas; j++)
				{
					fM[i][j]=n;
				}
			}
		}
	}
	void set1toN()
	{
		if(this->tipo=='i')
		{
			for(auto int i=0; i<this->filas; i++)
			{
				for(auto int j=0; j<this->columnas; j++)
				{
					iM[i][j]=(i*this->columnas)+(j+1);
				}
			}
		}
		else if(this->tipo=='f')
		{
			for(auto int i=0; i<this->filas; i++)
			{
				for(auto int j=0; j<this->columnas; j++)
				{
					fM[i][j]=(i*this->columnas)+(j+1);
				}
			}
		}
	}
							////////DETERMINANTE
	void determinante()
	{
		int sub1=-1, sub2=0;
		//indice=(i>n)?(n-i):(i)
		for(auto int i=0;i<(this->filas*this->columnas); i++)
		{
			//control de subindices
			sub1=(i%this->filas==0)?sub1+1:sub1;
			sub2=i%this->columnas;
			
			iM[sub1][sub2]=5;
			
			
			//Dibujarlo
			/*
			printf("[%d][%d] ", sub1, sub2);
			if(i%this->filas==4)
				printf("\n");
			*/	
		}
	}
	void printM()
	{
		printf("MATRIZ");
		if(this->tipo=='i')
		{
			for(auto int i=0; i<this->filas; i++)
			{
				for(auto int j=0; j<this->columnas; j++)
				{
					printf(" [%d] ", iM[i][j]);
				}
				printf("\n");
			}
		}
		else if(this->tipo=='f')
		{
			for(auto int i=0; i<this->filas; i++)
			{
				for(auto int j=0; j<this->columnas; j++)
				{
					printf("[%.2f]", fM[i][j]);
				}
				printf("\n");
			}
		}
	}
};