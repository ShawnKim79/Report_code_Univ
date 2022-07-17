#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void CopyImage(int **, int **, int, int);

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

void PrewittEdgeDetection(int **IN, int **OUT, int thr, int width, int height)
{
	int i, j, count, incont;
	int gx=0, gy=0, g=0;

	int max_val, max_index, temp;

	int value[65535];
	int val_calcul[256][256];
	int **out_value;
	//value = (int **)Imalloc2(width,height); 
	out_value = (int **)Imalloc2(width,height); 
	
	for(count=0 ; count<65535 ; count++)
	{
		value[count]=0;
	}

	for(j=0 ; j<256 ; j++)
	{
		for(i=0 ; i<256 ; i++)
		{
			val_calcul[j][i]=0;
		}

	}

	for(j=1 ; j<height-1 ; j++)
	{
		for(i=1 ; i<width-1 ; i++)
		{
			gx = IN[j-1][i+1] + IN[j][i+1] + IN[j+1][i+1] - IN[j-1][i-1] - IN[j][i-1] - IN[j+1][i-1];
			gy = IN[j+1][i-1] + IN[j+1][i] + IN[j+1][i+1] - IN[j-1][i-1] - IN[j-1][i] - IN[j-1][i+1];
			g = (unsigned int)sqrt((double)(gx*gx + gy*gy));

			//value[g]++; // 픽셀 값 분포 저장.
			val_calcul[j][i]=g;
			//OUT[j][i] = (g>thr) ? 255:0;
		}
	}
	
	memcpy(value, val_calcul, 65535);

	for(count=0 ; count<65535 ; count++)
	{
		max_val=0;
		for(incont=0 ; incont<65535 ; incont++)
		{
			if(max_val=value[incont])
				max_index = incont;
		}
		temp = value[count];
		value[count] = value[max_index];
		value[max_index] = temp;
	}

	thr = value[(int)(65535*0.1)];

	for(j=0 ; j<height-1 ; j++)
	{
		for(i=0 ; i<width-1 ; i++)
		{
			OUT[j][i] = (val_calcul[j][i]>thr) ? 255:0;
		}
	}
	
}


int Clipping(int value)
{
    if(value<0) return(0);
    else if(value>255) return(255);
    else return(value);
}


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
	int width,height, **orgimg, **outnozimg, **outfiltimg, **nozimg, **nozfilter; 

	int ten=100;

	GetFileName(name,"Enter test image name : ");
	GetSize(&width,&height);
 
	orgimg = (int **)Imalloc2(width,height);

	nozimg = (int **)Imalloc2(width,height); 
	nozfilter = (int **)Imalloc2(width,height); 
	
	
	outnozimg = (int **)Imalloc2(width,height); 
	outfiltimg = (int **)Imalloc2(width,height); 

	ReadImage(name,orgimg,width,height);

//	GeometricTransform2D(orgimg,outimg,width,height);
	AddGaussianNoise(orgimg, nozimg, 10, 20, width, height);
	WriteImage("noise.dat",nozimg,width,height);

	SpatialAveraging3X3(nozimg, nozfilter, width, height);
	WriteImage("fillter_noise.dat",nozfilter,width,height);

	PrewittEdgeDetection(nozimg, outnozimg, ten, width, height);
	WriteImage("noise_edge.dat",outnozimg,width,height);

	PrewittEdgeDetection(nozfilter, outfiltimg, ten, width, height);
	WriteImage("filt_edge.dat",outfiltimg,width,height);

	

	Ifree2(orgimg,width,height);
	Ifree2(nozimg,width,height);
	Ifree2(nozfilter,width,height);
	Ifree2(outnozimg,width,height);
	Ifree2(outfiltimg,width,height);

	return 0;
}