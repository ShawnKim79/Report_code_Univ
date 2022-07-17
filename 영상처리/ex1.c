#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "fn.h"

int main(void)
{
	char name[100];
	int width,height,**orgimg,**outimg;

	GetFileName(name,"Enter test image name : ");
	GetSize(&width,&height);
 
	orgimg = (int **)Imalloc2(width,height);
	outimg = (int **)Imalloc2(width,height); 

	ReadImage(name,orgimg,width,height);

	GeometricTransform2D(orgimg,outimg,width,height);

	GetFileName(name,"Enter output image name : ");
	WriteImage(name,outimg,width,height);

	Ifree2(orgimg,width,height);
	Ifree2(outimg,width,height);

	return 0;
}

int BilinearInterpolation(int **img, double x, double y, int width, int height)
{
	int i,j;
    double a,b,del_x,del_y;

	i = (int)x;
	j = (int)y;

   	del_x = x-i;
   	del_y = y-j;

	a = (1.-del_x)*img[j][i] + del_x*img[j][(i+1)%width];
	b = (1.-del_x)*img[(j+1)%height][i] + del_x*img[(j+1)%height][(i+1)%width];
	return((int)((1.-del_y)*a+del_y*b+.5));
}


void GetAttackParam(double *dx, double *dy, double *degree, double *scale)
{
    printf("\n\t[] (dx,dy,degree,scale)\t");
    scanf("%lf%lf%lf%lf",dx,dy,degree,scale);
}

void GeometricTransform2D(int **img, int **out, int width, int height)
{
	int i,j;
	double x,y,radian;
	double dx,dy,degree,scale;

	GetAttackParam(&dx,&dy,&degree,&scale);
	printf("\n\t%f\t%f\t%f\t%f", dx,dy,degree,scale);
	radian = degree/360.0*2.0*PI;
	for(j=0; j<height; j++)  
		for(i=0; i<width; i++)  {
			x = scale*cos((double)radian)*(i-width/2.) + scale*sin((double)radian)*(j-height/2.)+dx+width/2.;
			y = -scale*sin((double)radian)*(i-width/2.) + scale*cos((double)radian)*(j-height/2.)+dy+height/2.;
			x = x>0. ? (x<width-1. ? x : width-1.) : 0.;
			y = y>0. ? (y<height-1. ? y : height-1.) : 0.;
			out[j][i] = BilinearInterpolation(img,x,y,width,height);
		}
}

void ReadBlock(int **img, int **block, int a, int b, int wx, int wy, int width, int height)
{
	int i,j,x,y;

	for(j=0; j<wy; j++)
		for(i=0; i<wx; i++)  {
			x = ((a+i)<width) ? a+i : width-1;
			y = ((b+j)<height) ? b+j : height-1;
			block[j][i] = img[y][x];
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
    for(i=0;i<height;i++) for(j=0;j<width;j++) OUT[i][j] = IN[i][j];
}

void MakeDiffImage(int **image1, int **image2, int **imageout, int width, int height)
{
    int i,j;
    for(i=0;i<height;i++) for(j=0;j<width;j++)
       imageout[i][j] = abs(image1[i][j]-image2[i][j]);
}

void ReadHorizLine(int **img, int x, int y, int width, int *array)
{
	int i;

	for(i=x; i<width; i++)
		array[i] = img[y][i];
}

void WriteHorizLine(int **img, int x, int y, int width, int *array)
{
	int i;

	for(i=x; i<width; i++)
		img[y][i] = array[i];
}
