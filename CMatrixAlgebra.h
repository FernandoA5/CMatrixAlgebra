//#include<math.h>
typedef struct{
	int **iM;
	float **fM;
	int filas;
	int columnas;
	char tipo;
}regMatrix;
regMatrix vtrMatrix;

void setMatrix(int f, int c, char t)
{
	vtrMatrix.filas=f;
	vtrMatrix.columnas=c;
	vtrMatrix.tipo=t;
}
void setSize()
{
	int i;
	if(vtrMatrix.tipo=='i')
	{
		vtrMatrix.iM=(int **)malloc(vtrMatrix.filas*sizeof(int *));
		for(i=0; i<vtrMatrix.filas; i++)
		{
			vtrMatrix.iM[i]=(int *)malloc(vtrMatrix.columnas*sizeof(int));
		}
	}
	else if(vtrMatrix.tipo=='f')
	{
		vtrMatrix.fM=(float **)malloc(vtrMatrix.filas*sizeof(float *));
		for(i=0; i<vtrMatrix.filas; i++)
		{
			vtrMatrix.fM[i]=(int *)malloc(vtrMatrix.columnas*sizeof(float));
		}
	}
}
void setN(float N)
{
	int i, j;
	if(vtrMatrix.tipo=='i')
	{
		for(i=0;i<vtrMatrix.filas; i++)
		{
			for(j =0; j<vtrMatrix.columnas; j++)
			{
				vtrMatrix.iM[i][j]=N;
			}
		}
	}
}
void printM()
{
	int i, j;
	if(vtrMatrix.tipo=='i')
	{
		for(i=0; i<vtrMatrix.filas; i++)
		{
			for(j=0; j<vtrMatrix.columnas; j++)
			{
				printf(" [%d] ", vtrMatrix.iM[i][j]);
			}
			printf("\n");
		}
	}
	else if(vtrMatrix.tipo=='f')
	{
		for(i=0; i<vtrMatrix.filas; i++)
		{
			for(j=0; j<vtrMatrix.columnas; j++)
			{
				printf(" [%f] ", vtrMatrix.fM[i][j]);
			}
			printf("\n");
		}
		
	}
}

