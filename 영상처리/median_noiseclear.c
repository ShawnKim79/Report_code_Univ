/*---------------------------------------------------------------------------*/
/* Program:  median.c                                                        */
/*                                                                           */
/* Purpose:  This program performs median filtering of an image              */
/*           in KUIM format.                                                 */
/*                                                                           */
/* Author:   John Gauch, Edu Metz                                            */
/*                                                                           */
/* Date:     March 30, 1994 - Original program.                              */
/*           July 27, 1994  - Added color support.                           */
/*           July 31, 1997  - Simplified color, vector, scalar code.         */
/*                                                                           */
/* Note:     Copyright (C) The University of Kansas, 1994                    */
/*---------------------------------------------------------------------------*/
#include <IM.h>

/* Image variables */
char Name1[50];
char Name2[50];
IM_TYPE *Image1;
IM_TYPE *Image2;
int PixType, Xdim, Ydim, Zdim, DimCnt;
int Xsize = 3, Ysize = 3;
int Vector = FALSE;

/*---------------------------------------------------------------------------*/
/* Purpose:  This routine does simple selection sorting.                     */
/*---------------------------------------------------------------------------*/
void Sort(float *Array, int Count)
{
   int i, j, half, minpos;
   float minval;

   half = Count / 2;
   for (i = 0; i <= half; i++)
   {
      minpos = i;
      minval = Array[minpos];
      for (j = i + 1; j < Count; j++)
	 if (Array[j] < minval)
	 {
	    minpos = j;
	    minval = Array[j];
	 }
      Array[minpos] = Array[i];
      Array[i] = minval;
   }
}

/*---------------------------------------------------------------------------*/
/* Purpose:  This routine does median filtering for scalar images.           */
/*---------------------------------------------------------------------------*/
void MedianScalar()
{
   FLOAT_TYPE **Data1;
   FLOAT_TYPE **Data2;
   int i, x, y, dx, dy;
   int Xhalf, Yhalf;
   float Array[1000];

   /* Read input image */
   Data1 = (FLOAT_TYPE **) im_alloc2D(Image1, FLOAT);
   im_read(Image1, FLOAT, (char *) &(Data1[0][0]));

   /* Create output image */
   Image2 = im_create(Name2, FLOAT, Xdim, Ydim, Zdim);
   Data2 = (FLOAT_TYPE **) im_alloc2D(Image2, FLOAT);

   /* Perform median filtering */
   Xhalf = Xsize / 2;
   Yhalf = Ysize / 2;
   for (y = 0; y < Ydim; y++)
      for (x = 0; x < Xdim; x++)
      {
	 /* Load array with nearby pixel values */
	 i = 0;
	 for (dy = -Yhalf; dy <= (Ysize - Yhalf - 1); dy++)
	    for (dx = -Xhalf; dx <= (Xsize - Xhalf - 1); dx++)
	    {
	       if ((x + dx >= 0) && (y + dy >= 0) &&
		   (x + dx < Xdim) && (y + dy < Ydim))
		  Array[i++] = Data1[y + dy][x + dx];
	    }

	 /* Select median value */
	 Sort(Array, i);
	 Data2[y][x] = Array[i / 2];
      }

   /* Write information to output image */
   im_write(Image2, FLOAT, (char *) &(Data2[0][0]));
   im_free2D((char **) Data1);
   im_free2D((char **) Data2);
}

/*---------------------------------------------------------------------------*/
/* Purpose:  This routine does median filtering for vector images.           */
/*---------------------------------------------------------------------------*/
void MedianVector()
{
   FLOAT_TYPE ***Data1;
   FLOAT_TYPE ***Data2;
   int i, x, y, z, dx, dy, bx, by;
   int Xhalf, Yhalf;
   float Array[1000], dist, best;

   /* Read input image */
   Data1 = (FLOAT_TYPE ***) im_alloc3D(Image1, FLOAT);
   im_read(Image1, FLOAT, (char *) &(Data1[0][0][0]));

   /* Create output image */
   Image2 = im_create(Name2, PixType, Xdim, Ydim, Zdim);
   Data2 = (FLOAT_TYPE ***) im_alloc3D(Image2, FLOAT);

   /* Perform median filtering */
   Xhalf = Xsize / 2;
   Yhalf = Ysize / 2;
   for (z = 0; z < Zdim; z++)
      for (y = 0; y < Ydim; y++)
	 for (x = 0; x < Xdim; x++)
	 {
	    /* Load array with nearby pixel values */
	    i = 0;
	    for (dy = -Yhalf; dy <= (Ysize - Yhalf - 1); dy++)
	       for (dx = -Xhalf; dx <= (Xsize - Xhalf - 1); dx++)
	       {
		  if ((x + dx >= 0) && (y + dy >= 0) &&
		      (x + dx < Xdim) && (y + dy < Ydim))
		     Array[i++] = Data1[z][y + dy][x + dx];
	       }

	    /* Select median value */
	    Sort(Array, i);
	    Data2[z][y][x] = Array[i / 2];
	 }

   /* Find vector closest to mean */
   if (Vector == TRUE)
      for (y = 0; y < Ydim; y++)
	 for (x = 0; x < Xdim; x++)
	 {
	    /* Get distance to central pixel */
	    best = bx = by = 0;
	    for (z = 0; z < Zdim; z++)
	       best += (Data1[z][y][x] - Data2[z][y][x])
		  * (Data1[z][y][x] - Data2[z][y][x]);

	    /* Consider all nearby pixels */
	    for (dy = -Yhalf; dy <= (Ysize - Yhalf - 1); dy++)
	       for (dx = -Xhalf; dx <= (Xsize - Xhalf - 1); dx++)
		  if ((x + dx >= 0) && (y + dy >= 0) &&
		      (x + dx < Xdim) && (y + dy < Ydim))
		  {
		     /* Get distance to this pixel */
		     dist = 0;
		     for (z = 0; z < Zdim; z++)
			dist += (Data1[z][y + dy][x + dx] - Data2[z][y][x])
			   * (Data1[z][y + dy][x + dx] - Data2[z][y][x]);

		     /* Save coordinates of closest pixel */
		     if (best > dist)
		     {
			best = dist;
			bx = dx;
			by = dy;
		     }
		  }

	    /* Save new pixel value */
	    for (z = 0; z < Zdim; z++)
	       Data2[z][y][x] = Data2[z][y + by][x + bx];
	 }

   /* Write information to output image */
   im_write(Image2, FLOAT, (char *) &(Data2[0][0][0]));
   im_free3D((char ***) Data1);
   im_free3D((char ***) Data2);
}

/*---------------------------------------------------------------------------*/
/* Purpose:  This routine does median filtering for color images.            */
/*---------------------------------------------------------------------------*/
void MedianColor()
{
   COLOR_TYPE **Data1;
   COLOR_TYPE **Data2;
   int i, x, y, dx, dy, bx, by;
   int Xhalf, Yhalf;
   float ArrRed[1000], ArrBlue[1000], ArrGreen[1000];
   float dist, best;

   /* Read input image */
   Data1 = (COLOR_TYPE **) im_alloc2D(Image1, COLOR);
   im_read(Image1, COLOR, (char *) &(Data1[0][0]));

   /* Create output image */
   Image2 = im_create(Name2, PixType, Xdim, Ydim, Zdim);
   Data2 = (COLOR_TYPE **) im_alloc2D(Image2, COLOR);

   /* Perform median filtering */
   Xhalf = Xsize / 2;
   Yhalf = Ysize / 2;
   for (y = 0; y < Ydim; y++)
      for (x = 0; x < Xdim; x++)
      {
	 /* Load array with nearby pixel values */
	 i = 0;
	 for (dy = -Yhalf; dy <= (Ysize - Yhalf - 1); dy++)
	    for (dx = -Xhalf; dx <= (Xsize - Xhalf - 1); dx++)
	    {
	       if ((x + dx >= 0) && (y + dy >= 0) &&
		   (x + dx < Xdim) && (y + dy < Ydim))
	       {
		  ArrRed[i] = (float) Data1[y + dy][x + dx].r;
		  ArrGreen[i] = (float) Data1[y + dy][x + dx].g;
		  ArrBlue[i] = (float) Data1[y + dy][x + dx].b;
		  i++;
	       }
	    }

	 /* Select median value */
	 Sort(ArrRed, i);
	 Sort(ArrGreen, i);
	 Sort(ArrBlue, i);
	 Data2[y][x].r = (BYTE_TYPE) ArrRed[i / 2];
	 Data2[y][x].g = (BYTE_TYPE) ArrGreen[i / 2];
	 Data2[y][x].b = (BYTE_TYPE) ArrBlue[i / 2];
      }

   /* Find vector closest to mean */
   if (Vector == TRUE)
      for (y = 0; y < Ydim; y++)
	 for (x = 0; x < Xdim; x++)
	 {
	    /* Get distance to central pixel */
	    bx = by = 0;
	    best = ((float) Data1[y][x].r - (float) Data2[y][x].r)
	       * ((float) Data1[y][x].r - (float) Data2[y][x].r)
	       + ((float) Data1[y][x].g - (float) Data2[y][x].g)
	       * ((float) Data1[y][x].g - (float) Data2[y][x].g)
	       + ((float) Data1[y][x].g - (float) Data2[y][x].g)
	       * ((float) Data1[y][x].g - (float) Data2[y][x].g);

	    /* Consider all nearby pixels */
	    for (dy = -Yhalf; dy <= (Ysize - Yhalf - 1); dy++)
	       for (dx = -Xhalf; dx <= (Xsize - Xhalf - 1); dx++)
		  if ((x + dx >= 0) && (y + dy >= 0) &&
		      (x + dx < Xdim) && (y + dy < Ydim))
		  {
		     /* Get distance to this pixel */
		     dist = ((float) Data1[y + dy][x + dx].r
			     - (float) Data2[y][x].r)
			* ((float) Data1[y + dy][x + dx].r
			   - (float) Data2[y][x].r)
			+ ((float) Data1[y + dy][x + dx].g
			   - (float) Data2[y][x].g)
			* ((float) Data1[y + dy][x + dx].g
			   - (float) Data2[y][x].g)
			+ ((float) Data1[y + dy][x + dx].g
			   - (float) Data2[y][x].g)
			* ((float) Data1[y + dy][x + dx].g
			   - (float) Data2[y][x].g);

		     /* Save coordinates of closest pixel */
		     if (best > dist)
		     {
			best = dist;
			bx = dx;
			by = dy;
		     }
		  }

	    /* Save new pixel value */
	    Data2[y][x].r = Data2[y + by][x + bx].r;
	    Data2[y][x].g = Data2[y + by][x + bx].g;
	    Data2[y][x].b = Data2[y + by][x + bx].b;
	 }

   /* Write information to output image */
   im_write(Image2, COLOR, (char *) &(Data2[0][0]));
   im_free2D((char **) Data1);
   im_free2D((char **) Data2);
}

/*---------------------------------------------------------------------------*/
/* Purpose:  This is the main program.                                       */
/*---------------------------------------------------------------------------*/
int main(int argc, char *argv[])
{
   /* Program variables */
   int i = 0;
   int Debug = FALSE;

   /* Interpret program options */
   printf("MEDIAN Program - KUIM Version 2.1\n\n");
   while ((++i < argc) && (argv[i][0] == '-'))
      switch (argv[i][1])
      {
      case 's':
	 if (sscanf(argv[++i], "%d", &Xsize) == 0)
	    Error("Could not get X size");
	 if (sscanf(argv[++i], "%d", &Ysize) == 0)
	    Error("Could not get Y size");
	 if ((Xsize < 0) || (Ysize <= 0))
	    Error("Must have sizes > 0");
	 break;
      case 'v':
	 Vector = TRUE;
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
      fprintf(stderr, "Usage: median [options] infile outfile\n");
      fprintf(stderr, "       [-d]      Print debugging information\n");
      fprintf(stderr, "       [-v]      Calculate vector median\n");
      fprintf(stderr, "       [-s # #]  Size of sorting window (3,3)\n");
      exit(1);
   }

   /* Get image file names from argument list */
   if (sscanf(argv[i++], "%s", Name1) == 0)
      Error("Could not get input file name");
   if (sscanf(argv[i++], "%s", Name2) == 0)
      Error("Could not get output file name");

   /* Process input image */
   Image1 = im_open(Name1, &PixType, &Xdim, &Ydim, &Zdim, &DimCnt);

   /* Handle color images */
   if (PixType == COLOR || PixType == PSEUDO || PixType == JPEG_RGB)
      MedianColor();

   /* Handle scalar images */
   else if (DimCnt == 2)
      MedianScalar();

   /* Handle vector images */
   else if (DimCnt == 3)
      MedianVector();

   /* Unsupported image type */
   else
      Error("Can not process image");
   return (0);
}

