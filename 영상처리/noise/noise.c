#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.1415

void CopyImage(int **, int **, int, int);

void AddGaussianNoise(int ** IN, int **OUT, float mean, float std, int width, int height)
{
	int i, j, k, sum;
	float A=65536/2-1;

	for (j=0; j<height; j++)
		for (i=0; i<width; i++)
			for (k=0, sum=0; k<12; k++) {
				sum += rand();
				OUT[j][i] = Clipping(IN[j][i] + (int)(std/A*(sum-6*A)));
			}
}

void AddSpotNoise(int **orgimg, int **outimg, int val, float density, int width, int height)
{
	int i, x, y, num, rr;
	float A=65536/2-1;

	num = (int)(width*height*density);

	CopyImage(orgimg, outimg, width, height);

	for (i=0; i<num; i++) {
		rr = rand();
		y = (int)(rr/A*(height-1));
		x = rr % width;
		outimg[y][x] = val;
	}
}

void SpatialAveraging3X3(int **inimg, int **outimg, int width, int height)
{
	int i, j, k, l;
	float sumf;

	CopyImage(inimg, outimg, width, height);

	for (j=1; j<height-1; j++)
		for (i=1; i<width-1; i++) {
			for (l=-1, sumf=0.; l<=1; l++)
				for (k=-1; k<=1; k++)
					sumf += (float)(inimg[j+l][i+k] / 9.);
				outimg[j][i] = (int)(sumf+.5);
		}
}

void Medianfilter(int **inimg, int **outimg, int width, int height)
{
	int i, j, k, l;
	int temp;

	CopyImage(inimg, outimg, width, height);

	for(j=1 ; j<height-1 ; j++)
	{
		for(i=1 ; i<width ; i++)
		{
			for(k=-1 ; k<2 ; k++)
			{
				for(l=-1 ; l<2 ; l++)
				{
					if(inimg[j][i] < inimg[j+k][i+l])
					{
						temp=inimg[j+k][i+l];
						inimg[j+k][i+l] = inimg[j][k];
						//outimg[j][i] = temp;
					}

				}

			}
			outimg[j][i] = temp;
		}
	}
}

int Clipping(int value)
{
    if(value<0) return(0);
    else if(value>255) return(255);
    else return(value);
}

void GetFileName(char *name,char *string)
{
    printf("\n\t[] %s \t",string);
    scanf("%s",name);
}

void GetSize(int *width,int *height)
{
    printf("\n\t[] (width,height)\t");
    scanf("%d%d",width,height);
}

void ReadImage(char *name,int **image,int width,int height)
{
    FILE *fp;  int i,j;

	fp = fopen(name,"rb");
	if(fp==NULL){ printf("\n\t[] Open Failure !!"); exit(0);}
	for(i=0;i<height;i++) for(j=0;j<width;j++)
		 image[i][j] = getc(fp);
	fclose(fp); 
}

void WriteImage(char *name,int **image,int width,int height)
{
	FILE *fp; int i,j;

	fp = fopen(name,"wb");
	if(fp==NULL){ printf("\n\t[] Open Failure !!"); exit(0);}
	for(i=0;i<height;i++) for(j=0;j<width;j++)
		putc((unsigned char)image[i][j],fp);
	fclose(fp); 
}

int **Imalloc2(int x,int y)
{
	int i; int **tmp;

	tmp = (int **)malloc(sizeof(int *)*y);
	for(i=0;i<y;i++) tmp[i] = (int *)malloc(sizeof(int)*x);
	return(tmp);
}

void Ifree2(int **array, int x, int y)
{
    int i;
    for(i=0;i<y;i++) free(array[i]);
    free(array);
}

float **Fmalloc2(int x,int y)
{
	int i; float **tmp;

	tmp = (float **)malloc(sizeof(float *)*y);
	for(i=0;i<y;i++) tmp[i] = (float *)malloc(sizeof(float)*x);
	return(tmp);
}


void CopyImage(int **IN, int **OUT, int width, int height)
{
    int i,j;
    for(i=0;i<height;i++) 
		for(j=0;j<width;j++) 
			OUT[i][j] = IN[i][j];
}


int main(void)
{
	char name[100];

	// 필요 버퍼 : gaussian 노이즈, impluse 노이즈(노이즈 있는 거, 제거 처리된거)
	int width,height,**orgimg, **gauss_noise, **impulse_noise, **out_gauss_median, **out_impulse_median, **out_gauss_linear, **out_impulse_linear;

	GetFileName(name,"Enter test image name : ");
	GetSize(&width,&height);
 
	orgimg = (int **)Imalloc2(width,height); // 원본 이미지 읽어 오기.
	
	gauss_noise = (int **)Imalloc2(width,height); // 가우시안 노이즈 추가 
	impulse_noise = (int **)Imalloc2(width,height); // 임펄스 노이즈 추가 

	out_gauss_linear = (int **)Imalloc2(width,height); // 가우스 -> 라이너 필터
	out_gauss_median = (int **)Imalloc2(width,height); // 가우스 -> 메디안 필터

	out_impulse_linear = (int **)Imalloc2(width,height); // 임펄스 -> 라이너 필터
	out_impulse_median = (int **)Imalloc2(width,height); // 임펄스 -> 메디안 필터
	
	ReadImage(name,orgimg,width,height);

	// 노이즈를 추가할 함수
	AddGaussianNoise(orgimg, gauss_noise, 0., 10., width, height);
	AddSpotNoise(orgimg, impulse_noise, 0, 0.05, width, height);

	WriteImage("gauss_noise.dat", gauss_noise,width,height);
	WriteImage("impulse_noise.dat", impulse_noise,width,height);

	// 노이즈 제거 함수 -> 라이너 필터(에버러징)
	SpatialAveraging3X3(gauss_noise, out_gauss_linear, width, height);
	SpatialAveraging3X3(impulse_noise, out_impulse_linear, width, height);

	// 노이즈 제거 함수 -> 논-라이너 필터(메디안)
	Medianfilter(gauss_noise, out_gauss_median, width, height);
	Medianfilter(impulse_noise, out_impulse_median, width, height);
	
	WriteImage("out_gauss_linear.dat", out_gauss_linear,width,height);
	WriteImage("out_impulse_linear.dat", out_impulse_linear,width,height);
	WriteImage("out_gauss_median.dat", out_gauss_median,width,height);
	WriteImage("out_impulse_median.dat", out_impulse_median,width,height);

	Ifree2(orgimg,width,height);
	Ifree2(gauss_noise,width,height);
	Ifree2(impulse_noise,width,height);

	Ifree2(out_gauss_linear,width,height);
	Ifree2(out_impulse_linear,width,height);

	Ifree2(out_gauss_median,width,height);
	Ifree2(out_impulse_median,width,height);

	return 0;
}