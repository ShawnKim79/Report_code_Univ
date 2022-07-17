////////////////////////////////////////////////////
// raw���� ������ �ܼ��� byte���� �����̴�.
// �� �̹����� �ȼ� �����͸� ����ְ� �׿ܿ� ���������� �׸��� �׸����� �ɷ��� ����.


#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void ReadBlock(int **, int **, int , int , int , int , int , int);

void GetFileName(char *, char *);
void GetSize(int *,int *);

void ReadImage(char *, int **, int , int);
void WriteImage(char *, int **, int, int);

int **Imalloc2(int, int);
void Ifree2(int **, int, int);
float **Fmalloc2(int, int);

void WriteArray_1(unsigned long *, int, int);
void WriteArray_2(unsigned long *, int, int);

////////////////////////////////////////////////////////////////////////
// ������׷����� ������ �Լ�
// �ű⿡ ������ �׷��� �迭�� ����.

void Histogramming(unsigned int **, int, int, unsigned long *);
//                 ����    ���ۺ�  ���� ����  ������׷� ����  ������׷� ���.

void EncodeImage(unsigned int **, unsigned int **, int, int);

#define PI 3.1415

// Main function ////////////////////////////////////////////////////////
// �� �Լ����� ������ �۾��� ����ش�.
/* ���� -> ������׷�
    predictive�ڵ��ؼ� ���� ���� �׸�
   �̰͵� ������׷�
*/


int main(void) 
{
	char name[100]; // �����̸��� ������ �迭.

	int width,height;
	unsigned int **orgimg,**outimg; 
	// width, height : ���� ������ ���� ����.
	// **orgimg : ���� ������ ������ �迭.
	// **outimg : ������Ƽ�� ��Ų ����.	
	
	
	unsigned long histogram_org[256]; // ������׷��� ������ �迭
	//unsigned long sum_hist_org[256]; // ���� ������׷��� ������ �迭



	unsigned long histogram_pre[256]; // ��ȯ�� �̹��� ������׷��� ������ �迭
	

	GetFileName(name,"Enter test image name : "); // ���� ������ �̸��� �޴´�.
	GetSize(&width,&height); // �׸��� ���� ���� ũ�⸦ �����Ѵ�.

	// �� �ΰ��� ��ƾ�� ������ ������ �迭�� �޸𸮸� �Ҵ��Ѵ�.
	orgimg = (int **)Imalloc2(width,height); // �׸��� ���� ���� ũ�⸦ �ش�.
	outimg = (int **)Imalloc2(width,height); 

	ReadImage(name,orgimg,width,height); // ���� �̹��� �ҷ� �޸𸮿� ����.
	

//--������� ���� �Է�--------------------------------------------------------------------//

	Histogramming(orgimg, width, height, histogram_org);

	WriteArray_1(histogram_org, width, height);

	EncodeImage(orgimg, outimg, width, height);

	WriteImage("out.dat",outimg, width,height);

	Histogramming(outimg, width, height, histogram_pre);

	WriteArray_2(histogram_pre, width, height);

//--������� ���� ���--------------------------------------------------------------------//

//	GetFileName(name,"Enter output image name : ");
	
	Ifree2(orgimg,width,height);
	Ifree2(outimg,width,height);

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////
// ���� �̸� �޾� �����ϴ�  �Լ�.
void GetFileName(char *name,char *string)
{
    printf("\n\t[] %s \t",string);
    scanf("%s",name);
}

/////////////////////////////////////////////////////////////////////////////////////
// �׸� ������ �޾� �����ϴ� �Լ� 
void GetSize(int *width,int *height)
{
    printf("\n\t[] (width,height)\t");
    scanf("%d%d",width,height);
}

/////////////////////////////////////////////////////////////////////////////////////
// �̹��� �޸𸮿� �ε�
// ���ڰ� ( *name : ���� �̸�, **image : ������ �޸� ���� �ּ�, 
//			width&height : �޸𸮿� �����Ҷ� 2���� �迭 �������� �����ϱ� ���� ��.)
void ReadImage(char *name,int **image,int width,int height)
{
    FILE *fp; 
	int i,j;

	fp = fopen(name,"rb");
	if(fp==NULL)
	{
		printf("\n\t[] Open Failure !!");
		exit(0);
	}

	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			image[i][j] = getc(fp);
		}
	}
	fclose(fp); 
}

/////////////////////////////////////////////////////////////////////////////////////
// ���Ͽ� ����ϴ� ��ƾ.
void WriteImage(char *name,int **image,int width,int height)
{
	FILE *fp; int i,j;

	fp = fopen(name,"wb");
	if(fp==NULL)
	{ 
		printf("\n\t[] Open Failure !!");
		exit(0);
	}
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			putc((unsigned char)image[i][j],fp);
		}
	}
	fclose(fp); 
}

/////////////////////////////////////////////////////////////////////////////////////
// ���Ͽ� �迭 ����ϴ� ��ƾ.
void WriteArray_1(unsigned long target[], int width, int height)
{
	FILE *fp; 
	int i,j, index;
	unsigned char on = 255;
	unsigned char off = 0;

	unsigned long array[256][256];

    //unsigned long *array = (unsigned long *)malloc(256);

	//array = target;
		
	fp = fopen("org_array.dat","wb");
	if(fp==NULL)
	{ 
		printf("\n\t[] Open Failure !!");
		exit(0);
	}

	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			array[i][j] = 255;
			
		}
	}

	for(j=255;j>=0;j--)
	{
		index = (int)(target[j]/100);
		array[index][j] = 0;
	}
	


	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			putc((unsigned char)array[i][j], fp );
			
		}
	}
	fclose(fp); 
	
}

/////////////////////////////////////////////////////////////////////////////////////
// ���Ͽ� �迭 ����ϴ� ��ƾ.
void WriteArray_2(unsigned long target[], int width, int height)
{
	FILE *fp; 
	int i,j, index;
	unsigned char on = 255;
	unsigned char off = 0;

	unsigned long array[256][256];

    //unsigned long *array = (unsigned long *)malloc(256);

	//array = target;
		
	fp = fopen("com_array.dat","wb");
	if(fp==NULL)
	{ 
		printf("\n\t[] Open Failure !!");
		exit(0);
	}

	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			array[i][j] = 255;
			
		}
	}

	for(j=255;j>=0;j--)
	{
		index = (int)(target[j] / 100);
		array[index][j] = 0;
	}
	


	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			putc((unsigned char)array[i][j], fp );
			
		}
	}
	fclose(fp); 
	
}



/////////////////////////////////////////////////////////////////////////////////////
// �̹����� ������ �޸� �Ҵ�.
int **Imalloc2(int x,int y)
{
	int i; int **tmp;

	tmp = (int **)malloc(sizeof(int *)*y);
	for(i=0;i<y;i++) tmp[i] = (int *)malloc(sizeof(int)*x);
	return(tmp);
}

/////////////////////////////////////////////////////////////////////////////////////
// �Ҵ��� �޸� ����.
void Ifree2(int **array, int x, int y)
{
    int i;
    for(i=0;i<y;i++) free(array[i]);
    free(array);
}

/////////////////////////////////////////////////////////////////////////////////////

float **Fmalloc2(int x,int y)
{
	int i; float **tmp;

	tmp = (float **)malloc(sizeof(float *)*y);
	for(i=0;i<y;i++) tmp[i] = (float *)malloc(sizeof(float)*x);
	return(tmp);
}

/////////////////////////////////////////////////////////////////////////////////////

void Histogramming(unsigned int **img, int width, int height, unsigned long his_array[])
{
//	float scale_factor;
	int i, j, index; 
	
	unsigned long sum=0;

	// histogram�� ������ �迭 �ʱ�ȭ.
	for(i=0 ; i<256 ; i++)
		his_array[i]=0;

	i=0;
	j=0;

	// histogram ����
	for(i=0 ; i<255 ; i++)
	{
		for(j=0 ; j<255 ; j++)
		{
			index = (unsigned char)img[i][j];
			his_array[index]++;			
		}
	}

/*
	scale_factor = 255.0 / (width*height);

	// histogram ���
	for(i=0 ; i<256 ; i++)
	{
		sum += his_array[i];
		sum_array[i] = (sum * scale_factor)+0.5;
	}
*/
	

}

////////////////////////////////////////////////////////////////////////////////////////

void EncodeImage(unsigned int **orgimg, unsigned int **outimg, int width, int height)
{
	int i, j;

	for(i=0 ; i<height-1 ; i++)
	{
		for(j=0 ; j<width ; j++)
		{
			outimg[i][j] = (orgimg[i][j] - orgimg[i+1][j])+127;
		}
	}
}
/////////////////////////////////////////////////////////////////////////////////////