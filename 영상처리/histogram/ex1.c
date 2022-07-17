////////////////////////////////////////////////////
// raw파일 포맷은 단순한 byte들의 집합이다.
// 즉 이미지의 픽셀 데이터만 들어있고 그외에 독자적으로 그림을 그릴만한 능력은 없다.


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
// 히스토그래밍을 수행할 함수
// 거기에 히스토 그램할 배열도 주자.

void Histogramming(int **, int **, int, int, unsigned long *, unsigned long *);
//                 원본    조작본  가로 세로  히스토그램 저장  히스토그램 계산.

#define PI 3.1415

// Main function ////////////////////////////////////////////////////////
// 이 함수에서 수행할 작업을 골라준다.

int main(void) 
{
	char name[100]; // 파일이름을 저장할 배열.
	int width,height,**orgimg,**outimg; 
	// width, height : 원본 파일의 가로 세로.

	// **orgimg : 원본 파일을 저장한 배열.
	// **outimg : 나갈 파일을 저장할 배열. 
	
//	int **outarray_1, **outarray_2;
	// 배열의 값을 그림으로 변환시킬 배열.

	unsigned long histogram[256]; // 히스토그램을 저장할 배열
	unsigned long sum_hist[256]; // 계산된 히스토그램을 저장할 배열


	GetFileName(name,"Enter test image name : "); // 원본 파일의 이름을 받는다.
	GetSize(&width,&height); // 그림의 가로 세로 크기를 저장한다.

	// 이 두개의 루틴은 파일을 저장할 배열에 메모리를 할당한다.
	orgimg = (int **)Imalloc2(width,height); // 그림의 가로 세로 크기를 준다.
	outimg = (int **)Imalloc2(width,height); 

	ReadImage(name,orgimg,width,height); // 실제 이미지 불러 메모리에 저장.
	

//--여기까지 파일 입력--------------------------------------------------------------------//

// 이미지 처리 function call.
	//GeometricTransform2D(orgimg,outimg,width,height);

// Histogram 처리 요구사항
//	1. 원본파일과 바뀐 파일을 출력할 것.
//	2. 원본과 바뀐 파일의 히스토그램 그래프를 출력할 것.
// 해결책
//  1. 이것은 기본으로 제공된 소스에서 해결 해준다
//  2. 이것은 배열을 이용해서 처리.

	Histogramming(orgimg, outimg, width, height, histogram, sum_hist);
//--여기부터 파일 출력--------------------------------------------------------------------//

	GetFileName(name,"Enter output image name : ");
	WriteImage(name,outimg,width,height);

//Histogram 배열의 값을 출력.
	// 인수 ( 인쇄할 배열, 원본 이미지)
	WriteArray_1(histogram, width, height);
	WriteArray_2(sum_hist, width, height);


	Ifree2(orgimg,width,height);
	Ifree2(outimg,width,height);

	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////
// 파일 이름 받아 저장하는  함수.
void GetFileName(char *name,char *string)
{
    printf("\n\t[] %s \t",string);
    scanf("%s",name);
}

/////////////////////////////////////////////////////////////////////////////////////
// 그림 사이즈 받아 저장하는 함수 
void GetSize(int *width,int *height)
{
    printf("\n\t[] (width,height)\t");
    scanf("%d%d",width,height);
}

/////////////////////////////////////////////////////////////////////////////////////
// 이미지 메모리에 로드
// 인자값 ( *name : 파일 이름, **image : 저장할 메모리 공간 주소, 
//			width&height : 메모리에 저장할때 2차원 배열 형식으로 저장하기 위한 것.)
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
// 파일에 출력하는 루틴.
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
// 파일에 배열 출력하는 루틴.
void WriteArray_1(unsigned long target[], int width, int height)
{
	FILE *fp; 
	unsigned long i,j;
	unsigned char on = 255;
	unsigned char off = 0;

    unsigned long *array = (unsigned long *)malloc(256);

	array = target;
	

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
			putc((unsigned char)array[j], fp );
			
		}
	}
	fclose(fp); 
	
}

/////////////////////////////////////////////////////////////////////////////////////
// 파일에 배열 출력하는 루틴.
void WriteArray_2(unsigned long target[], int width, int height)
{
	FILE *fp; 
	unsigned long i,j;
	unsigned char on = 255;
	unsigned char off = 0;

    unsigned long *array = (unsigned long *)malloc(256);

	array = target;
	

	fp = fopen("his_array.dat","wb");
	if(fp==NULL)
	{ 
		printf("\n\t[] Open Failure !!");
		exit(0);
	}
	for(i=0;i<height;i++)
	{
		for(j=0;j<width;j++)
		{
			putc((unsigned char)array[j], fp );
		}
	}
	fclose(fp); 
	
}



/////////////////////////////////////////////////////////////////////////////////////
// 이미지를 저장할 메모리 할당.
int **Imalloc2(int x,int y)
{
	int i; int **tmp;

	tmp = (int **)malloc(sizeof(int *)*y);
	for(i=0;i<y;i++) tmp[i] = (int *)malloc(sizeof(int)*x);
	return(tmp);
}

/////////////////////////////////////////////////////////////////////////////////////
// 할당한 메모리 해제.
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

void Histogramming(int **img, int **out, int width, int height, unsigned long his_array[], unsigned long sum_array[])
{
	float scale_factor;
	unsigned long i; 
	unsigned long j;
	unsigned long sum=0;

	// histogram을 저장할 배열 초기화.
	for(i=0 ; i<256 ; i++)
		his_array[i]=0;

	// histogram 저장
	for(i=0 ; i<height ; i++)
	{
		for(j=0 ; j<width ; j++)
		{
			his_array[img[i][j]]++;
		}
	}


	scale_factor = 255.0 / (width*height);

	// histogram 계산
	for(i=0 ; i<256 ; i++)
	{
		sum += his_array[i];
		sum_array[i] = (sum * scale_factor)+0.5;
	}

	for(i=0 ; i<height ; i++)
	{
		for(j=0 ; j<width ; j++)
		{
			out[i][j] = sum_array[img[i][j]];
		}
	}


}

/////////////////////////////////////////////////////////////////////////////////////