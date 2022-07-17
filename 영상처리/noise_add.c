/*--------------------------------------------------------------------------*/
/* Program:  noise.c                                                        */
/*                                                                          */
/* Purpose:  This program adds noise to an image.  A number of different    */
/*           noise models are currently supported: Gaussian, Exponential,   */
/*           Poisson, Impulse, and Uniform.  The amount of noise to add     */
/*           in each case is determined by the desired noise variance.      */
/*           The mean noise value can also be set.                          */
/*                                                                          */
/* Author:   John Gauch                                                     */
/*                                                                          */
/* Date:     August 8, 1997  - Program rewritten.                           */
/*                                                                          */
/* Note:     Copyright (C) The University of Kansas, 1997                   */
/*--------------------------------------------------------------------------*/
#include <IM.h>

#define GAUSSIAN    0
#define EXPONENTIAL 1
#define POISSON     2
#define IMPULSE     3
#define UNIFORM     4
#define SIZE        1000

/* Image variables */
int Debug = FALSE;
int Method = GAUSSIAN;
double Variance = 100;
double Mean = 0;
char Name1[50];
char Name2[50];
IM_TYPE *Image1;
IM_TYPE *Image2;
int PixType, Xdim, Ydim, Zdim, DimCnt;

/*---------------------------------------------------------------------------*/
/* Purpose:  Return a noise value from the specified distribution.           */
/*---------------------------------------------------------------------------*/
int Noise(double *Prob)
{
   int Low = 0;
   int Mid = (SIZE - 1) / 2;
   int High = SIZE - 1;
   int Random = 1 + rand() % (SIZE - 1);

   while (Low < High)
   {
      Mid = (Low + High) / 2;
      if (Prob[Mid] * SIZE < Random)
	 Low = Mid + 1;
      else if (Prob[Mid] * SIZE > Random)
	 High = Mid - 1;
      else
	 Low = High = Mid;
   }

   return (Mid);
}

/*---------------------------------------------------------------------------*/
/* Purpose:  Add noise to a float image.                                     */
/*---------------------------------------------------------------------------*/
void NoiseFloat()
{
   /* Local variables */
   FLOAT_TYPE *Data1;
   FLOAT_TYPE *Data2;
   double StdDev = 10;
   double Area = 0;
   double prob[SIZE];
   double Prob[SIZE];
   int Range = 0;
   int Count = 0;
   int i = 0, j = 0;

   /* Read input image */
   Data1 = (FLOAT_TYPE *) im_alloc1D(Image1, FLOAT);
   im_read(Image1, FLOAT, (char *) Data1);

   /* Create output image */
   Image2 = im_create(Name2, PixType, Xdim, Ydim, Zdim);
   Data2 = (FLOAT_TYPE *) im_alloc1D(Image2, FLOAT);
   Count = Xdim * Ydim * Zdim;

   /* ----- Add Gaussian noise ----- */
   if (Method == GAUSSIAN)
   {
      /* Initialize probability arrays */
      j = -SIZE / 2;
      Area = 1.0 / sqrt(2 * M_PI * Variance);
      prob[0] = Area * exp(-(j * j) / (2 * Variance));
      Prob[0] = 0;
      for (i = 1; i < SIZE; i++, j++)
      {
	 prob[i] = Area * exp(-(j * j) / (2 * Variance));
	 Prob[i] = Prob[i - 1] + (prob[i - 1] + prob[i]) / 2;
      }

      /* Add noise to each point */
      for (i = 0; i < Count; i++)
	 Data2[i] = Data1[i] + Noise(Prob) - SIZE / 2 + Mean;
   }

   /* ----- Add Exponential noise ----- */
   else if (Method == EXPONENTIAL)
   {
      /* Initialize probability arrays */
      StdDev = sqrt(Variance);
      prob[0] = 1 / StdDev;
      Prob[0] = 0;
      for (i = 1; i < SIZE; i++)
      {
	 prob[i] = exp(-i / StdDev) / StdDev;
	 Prob[i] = Prob[i - 1] + (prob[i - 1] + prob[i]) / 2;
      }

      /* Add noise to each point */
      for (i = 0; i < Count; i++)
	 Data2[i] = Data1[i] + Noise(Prob) - StdDev + Mean;
   }

   /* ----- Add Poisson noise ----- */
   else if (Method == POISSON)
   {
      /* Initialize probability arrays */
      prob[0] = exp(-Variance);
      Prob[0] = 0;
      for (i = 1; i < SIZE; i++)
      {
	 prob[i] = prob[i - 1] * Variance / i;
	 Prob[i] = Prob[i - 1] + (prob[i - 1] + prob[i]) / 2;
      }

      /* Add noise to each point */
      for (i = 0; i < Count; i++)
	 Data2[i] = Data1[i] + Noise(Prob) - Variance + Mean;
   }

   /* ----- Add Impulse noise ----- */
   else if (Method == IMPULSE)
   {
      Range = 256;
      for (i = 0; i < Count; i++)
      {
	 if ((rand() % 10000) < Variance)
	    Data2[i] = rand() % Range;
	 else
	    Data2[i] = Data1[i];
      }
   }

   /* ----- Add Uniform noise ----- */
   else if (Method == UNIFORM)
   {
      Range = (int) sqrt(Variance * 3) * 2;
      for (i = 0; i < Count; i++)
	 Data2[i] = Data1[i] + rand() % Range - Range / 2 + Mean;
   }

   /* Write information to output image */
   im_write(Image2, FLOAT, (char *) Data2);
   im_free1D((char *) Data1);
   im_free1D((char *) Data2);
}

/*---------------------------------------------------------------------------*/
/* Purpose:  Add noise to a color image.                                     */
/*---------------------------------------------------------------------------*/
void NoiseColor()
{
   /* Local variables */
   COLOR_TYPE *Data1;
   COLOR_TYPE *Data2;
   double StdDev = 10;
   double Area = 0;
   double prob[SIZE];
   double Prob[SIZE];
   int Range = 0;
   int Count = 0;
   int Random = 0;
   int i = 0, j = 0;
   int temp = 0;

   /* Read input image */
   Data1 = (COLOR_TYPE *) im_alloc1D(Image1, COLOR);
   im_read(Image1, COLOR, (char *) Data1);

   /* Create output image */
   Image2 = im_create(Name2, PixType, Xdim, Ydim, Zdim);
   Data2 = (COLOR_TYPE *) im_alloc1D(Image2, COLOR);
   Count = Xdim * Ydim * Zdim;

   /* ----- Add Gaussian noise ----- */
   if (Method == GAUSSIAN)
   {
      /* Initialize probability arrays */
      j = -SIZE / 2;
      Area = 1.0 / sqrt(2 * M_PI * Variance);
      prob[0] = Area * exp(-(j * j) / (2 * Variance));
      Prob[0] = 0;
      for (i = 1; i < SIZE; i++, j++)
      {
	 prob[i] = Area * exp(-(j * j) / (2 * Variance));
	 Prob[i] = Prob[i - 1] + (prob[i - 1] + prob[i]) / 2;
      }

      /* Add noise to each point */
      for (i = 0; i < Count; i++)
      {
	 temp = Data1[i].r + Noise(Prob) - SIZE / 2 + Mean;
	 if (temp < 0)
	    temp = 0;
	 else if (temp > 255)
	    temp = 255;
	 Data2[i].r = temp;
	 temp = Data1[i].g + Noise(Prob) - SIZE / 2 + Mean;
	 if (temp < 0)
	    temp = 0;
	 else if (temp > 255)
	    temp = 255;
	 Data2[i].g = temp;
	 temp = Data1[i].b + Noise(Prob) - SIZE / 2 + Mean;
	 if (temp < 0)
	    temp = 0;
	 else if (temp > 255)
	    temp = 255;
	 Data2[i].b = temp;
      }
   }

   /* ----- Add Exponential noise ----- */
   else if (Method == EXPONENTIAL)
   {
      /* Initialize probability arrays */
      StdDev = sqrt(Variance);
      prob[0] = 1 / StdDev;
      Prob[0] = 0;
      for (i = 1; i < SIZE; i++)
      {
	 prob[i] = exp(-i / StdDev) / StdDev;
	 Prob[i] = Prob[i - 1] + (prob[i - 1] + prob[i]) / 2;
      }

      /* Add noise to each point */
      for (i = 0; i < Count; i++)
      {
	 temp = Data1[i].r + Noise(Prob) - StdDev + Mean;
	 if (temp < 0)
	    temp = 0;
	 else if (temp > 255)
	    temp = 255;
	 Data2[i].r = temp;
	 temp = Data1[i].g + Noise(Prob) - StdDev + Mean;
	 if (temp < 0)
	    temp = 0;
	 else if (temp > 255)
	    temp = 255;
	 Data2[i].g = temp;
	 temp = Data1[i].b + Noise(Prob) - StdDev + Mean;
	 if (temp < 0)
	    temp = 0;
	 else if (temp > 255)
	    temp = 255;
	 Data2[i].b = temp;
      }
   }

   /* ----- Add Poisson noise ----- */
   else if (Method == POISSON)
   {
      /* Initialize probability arrays */
      prob[0] = exp(-Variance);
      Prob[0] = 0;
      for (i = 1; i < SIZE; i++)
      {
	 prob[i] = prob[i - 1] * Variance / i;
	 Prob[i] = Prob[i - 1] + (prob[i - 1] + prob[i]) / 2;
      }

      /* Add noise to each point */
      for (i = 0; i < Count; i++)
      {
	 temp = Data1[i].r + Noise(Prob) - Variance + Mean;
	 if (temp < 0)
	    temp = 0;
	 else if (temp > 255)
	    temp = 255;
	 Data2[i].r = temp;
	 temp = Data1[i].g + Noise(Prob) - Variance + Mean;
	 if (temp < 0)
	    temp = 0;
	 else if (temp > 255)
	    temp = 255;
	 Data2[i].g = temp;
	 temp = Data1[i].b + Noise(Prob) - Variance + Mean;
	 if (temp < 0)
	    temp = 0;
	 else if (temp > 255)
	    temp = 255;
	 Data2[i].b = temp;
      }
   }

   /* ----- Add Impulse noise ----- */
   else if (Method == IMPULSE)
   {
      Range = 256;
      for (i = 0; i < Count; i++)
      {
	 if ((rand() % 10000) < Variance)
	 {
	    Data2[i].r = rand() % Range;
	    Data2[i].g = rand() % Range;
	    Data2[i].b = rand() % Range;
	 }
	 else
	 {
	    Data2[i].r = Data1[i].r;
	    Data2[i].g = Data1[i].g;
	    Data2[i].b = Data1[i].b;
	 }
      }
   }

   /* ----- Add Uniform noise ----- */
   else if (Method == UNIFORM)
   {
      Range = (int) sqrt(Variance * 3) * 2;
      for (i = 0; i < Count; i++)
      {
	 temp = Data1[i].r + rand() % Range - Range / 2 + Mean;
	 if (temp < 0)
	    temp = 0;
	 else if (temp > 255)
	    temp = 255;
	 Data2[i].r = temp;
	 temp = Data1[i].g + rand() % Range - Range / 2 + Mean;
	 if (temp < 0)
	    temp = 0;
	 else if (temp > 255)
	    temp = 255;
	 Data2[i].g = temp;
	 temp = Data1[i].b + rand() % Range - Range / 2 + Mean;
	 if (temp < 0)
	    temp = 0;
	 else if (temp > 255)
	    temp = 255;
	 Data2[i].b = temp;
      }
   }

   /* Write information to output image */
   im_write(Image2, COLOR, (char *) Data2);
   im_free1D((char *) Data1);
   im_free1D((char *) Data2);
}

/*--------------------------------------------------------------------------*/
/* Purpose:  This is the main program.                                      */
/*--------------------------------------------------------------------------*/
main(int argc, char *argv[])
{
   /* Program variables */
   int i = 0;

   /* Interpret program options */
   printf("NOISE Program - KUIM Version 3.0\n\n");
   while ((++i < argc) && (argv[i][0] == '-'))
      switch (argv[i][1])
      {
      case 'm':
	 if (sscanf(argv[++i], "%lf", &Mean) == 0)
	    Error("Could not get mean argument");
	 break;
      case 'g':
	 Method = GAUSSIAN;
	 if (sscanf(argv[++i], "%lf", &Variance) == 0)
	    Error("Could not get variance argument");
	 break;
      case 'e':
	 Method = EXPONENTIAL;
	 if (sscanf(argv[++i], "%lf", &Variance) == 0)
	    Error("Could not get variance argument");
	 break;
      case 'p':
	 Method = POISSON;
	 if (sscanf(argv[++i], "%lf", &Variance) == 0)
	    Error("Could not get variance argument");
	 if (Variance > 700)
	    Error("Variance must be less than 700");
	 break;
      case 'i':
	 Method = IMPULSE;
	 if (sscanf(argv[++i], "%lf", &Variance) == 0)
	    Error("Could not get variance argument");
	 if (Variance > 10000)
	    Error("Variance must be less than 10000");
	 break;
      case 'u':
	 Method = UNIFORM;
	 if (sscanf(argv[++i], "%lf", &Variance) == 0)
	    Error("Could not get variance argument");
	 break;
      case 'd':
	 Debug = TRUE;
	 break;
      default:
	 Error("Invalid option encountered");
	 break;
      }

   /* Check number of file names */
   if (argc - i != 2)
   {
      fprintf(stderr, "Usage: noise [options] infile outfile\n");
      fprintf(stderr, "       [-m #]  Mean of noise (0)\n");
      fprintf(stderr, "       [-g #]  Gaussian noise variance (100)\n");
      fprintf(stderr, "       [-e #]  Exponential noise variance\n");
      fprintf(stderr, "       [-p #]  Poisson noise variance\n");
      fprintf(stderr, "       [-i #]  Impulse noise variance\n");
      fprintf(stderr, "       [-u #]  Uniform noise variance\n");
      return (1);
   }

   /* Get image file names from argument list */
   if (sscanf(argv[i++], "%s", Name1) == 0)
      Error("Could not get input file name");
   if (sscanf(argv[i++], "%s", Name2) == 0)
      Error("Could not get output file name");

   /* Open input image */
   Image1 = im_open(Name1, &PixType, &Xdim, &Ydim, &Zdim, &DimCnt);

   /* Handle color images */
   if (PixType == COLOR || PixType == PSEUDO || PixType == JPEG_RGB)
      NoiseColor();

   /* Handle float images */
   else
      NoiseFloat();
   return (0);
}

