/*


c console program for testing color gradient
uses a code from gnuplot


gcc h.c -lm -Wall
a@zelman:~/c/varia/outor/gradient/hsv$ ./a.out
===========================

h= 360.000000	 s=0.000000	 v=1.000000
r= 1.000000	 g=1.000000	 b=1.000000
-----------------------------------
h= 0.000000	 s=1.000000	 v=1.000000
r= 1.000000	 g=0.000000	 b=0.000000






*/



#include <stdio.h>
#include <string.h> // strncat
#include <stdlib.h> // malloc
#include <math.h>		// floor;  needs -lm also






// size of virtual 2D array of pixels
// each piexel has a RGB color
int iWidth = 600;
int iHeight ; // 


// size of the dynamic 1D array 
unsigned char * data;
size_t ColorSize = 3; // RGB = number of color components = channels
size_t ArrayLength; // number of 1D array's elements = ENumber = iWidth*iHeight*ColorSize
size_t ElementSize; // size of array's element in bytes
size_t ArraySize; // size of array in bytes = ElementSize*ArrayLength 

// ppm P6 file
size_t HeaderSize ; // size of the P6 file  header in bytes
size_t FileSize; // = HeaderSize +ArraySize [bytes]







// gives position of 2D point (ix,iy) in 1D array  ; uses also global variables: iWidth , ColorSize
int Give_i ( int iX, int iY)
{
  return (iX + iY * iWidth) * ColorSize;  
}







/* 

GNUPLOT : http://gnuplot.sourceforge.net/
file : getoutor.c 

 * Petr Mikulik, December 1998 -- June 1999
 * Copyright: open source as much as possible
 *
*/



// from colour.h
/* Contains a colour in RGB scheme.
   Values of  r, g and b  are all in range [0;1] */
typedef struct {
    double r, g, b;
} rgb;

/* hsv :
 h : deg [0,360]
 s : % [0.0,100.0]
 v : % [0.0,100]
*/ 
typedef struct {
    double h, s, v;
} hsv;





/*
 *  outor Conversion Algorithms
 *  taken from http://www.cs.rit.edu/~ncs/outor/t_convert.html
 *  each outor model should provide a conversion to RGB.
 *  RGB values are clipped to [0,1] as some outors in some
 *  models have no RGB value.
 */

static void
HSV_2_RGB(hsv in, rgb *out)
{
    double h,s,v, f,p,q,t;
    int i;

    h = in.h;
    s = in.s;
    v = in.v;
    if (s == 0) { /* achromatic (gray) */
        out->r = out->g = out->b = v;
	return;
    }

    h *= 6.;  /* h range in gnuplot is [0,1] and not the usual [0,360] */
    i = floor(h);
    f = h - i;
    p = v * (1.0 - s);
    q = v * (1.0 - s*f);
    t = v * (1.0 - s*(1.0-f));
    switch(i % 6) {
    case 0:
	out->r = v;
	out->g = t;
	out->b = p;
	break;
    case 1:
	out->r = q;
	out->g = v;
	out->b = p;
	break;
    case 2:
	out->r = p;
	out->g = v;
	out->b = t;
	break;
    case 3:
	out->r = p;
	out->g = q;
	out->b = v;
	break;
    case 4:
	out->r = t;
	out->g = p;
	out->b = v;
	break;
    default:
	out->r = v;
	out->g = p;
	out->b = q;
	break;
    }
}







void PrintColor( FILE *fp, double position, hsv in, rgb out){
  // normalized to [0.0, 1.0] range RGB color channels
  double R = out.r; 
  double G = out.g;
  double B = out.b;
  // [Relative luminance is formed as a weighted sum of linear RGB components](https://en.wikipedia.org/wiki/Luma_(video)) 
  // 
  //from function test_palette_subcommand from file gnuplot/src/command.c test_palette_subcommand
  //ntsc = 0.299 * rgb.r + 0.587 * rgb.g + 0.114 * rgb.b;
  double Y = 0.299*R + 0.587*G + 0.114*B;
  
  
  //print 
	fprintf(fp, "%f\t", position);
	fprintf(fp, "%f\t %f\t%f\t%f\t", R, G, B, Y);
	fprintf(fp, "%f\t %f\t %f\n", in.h, in.s, in.v);
	
	
  

}




/* position -> hsv -> rgb 
 input position  double [0.0, 1.0]
 output rgb = unsigned char c array
 
 rainbow gradient = Rainbow colormap or sawtooth rainbow or hsv
*/
void ComputeAndPrintColor( FILE *fp, double position, unsigned char c[]){

	// "cyclic colormap traversing HSV color space. The map is obtained by linearly varying the hue through all possible values while keeping constant maximum saturation and value."
  
        hsv in = {position, 1.0, 1.0}; // set palette model HSV functions gray,1,1
	rgb out;
	
	// compute hsv from position 
	
	HSV_2_RGB(in, &out); // convert hsv to rgb 
	
	//
	PrintColor( fp, position, in, out);
  
  	//  change range
  	c[0] = 255*out.r; //R
  	c[1] = 255*out.g; // G
  	c[2] = 255*out.b; // B	
	

}













int PlotPoint(unsigned char A[], int i, unsigned char color[]){

  A[i]   = color[0]; /* Red*/
  A[i+1] = color[1]; /* Green */
  A[i+2] = color[2];  /* Blue */
  return 0;


}



// --------------------
int FillArray (unsigned char A[] , int n){

  int iX;
  int iXmax = iWidth;
  int iY;
  int iYmax = iHeight;
  int i; //  index of 1D array  
  double position; // number form 0.0 to 1.0 used for color gradient
  unsigned char color[3]; // 
	
  // text file used by the gnuplot for creating images
  char name [100]; /* name of file */
  snprintf(name, sizeof name, "%d", n); /*  */
  char *filename =strncat(name,".txt", 4);
  FILE *fp = fopen(filename, "w");
  if (fp==NULL) {
    printf("Error opening text file!\n");
    return 1;
  }
  fprintf(fp, "# position \t\t R \t\t G \t\tB \t\tY \t h\ts\tv\n"); // header of the text file
	
	
  //
  for(iX=0; iX<iXmax; ++iX){    
    position = (double) iX / iXmax;
    ComputeAndPrintColor(fp, position, color);
    
    // vertical   		
    for(iY=0; iY<iYmax; ++iY){
      i = Give_i(iX, iY);
      PlotPoint(A, i , color);
    }
        		
         			
  }


  fclose(fp);
  return 0;
}





// --------------- save dynamic "A" array of uinsigned char to the binary ppm file ( P6 ) --------------------------------
int SaveArray2PPM (unsigned char A[], size_t ASize,   int k)
{

  FILE *fp;
  const unsigned char MaxColorComponentValue = 255;	/* color component is coded from 0 to 255 ;  it is 8 bit color file */
  
  char name [100]; /* name of file */
  snprintf(name, sizeof name, "%d", k); /*  */
  char *filename =strncat(name,".ppm", 4);
  
  

  /* save image to the pgm file  */
  fp = fopen (filename, "wb");	/*create new file,give it a name and open it in binary mode  */
  if (fp == NULL) 
    {	printf("File open error"); 
      return 1;}
  else {
    fprintf (fp, "P6\n%u %u\n%u\n", iWidth, iHeight, MaxColorComponentValue);	/*write header to the file */
    fwrite (A, ASize, 1, fp);	// write dynamic A array to the binary file in one step  
 
    printf ("File %s saved. \n", filename);
    fclose (fp);
    return 0;}
  
}



// n = nummber of the gradient function
int MakeGradientImage(unsigned char A[],  int n){


  FillArray(data, n);
  SaveArray2PPM(data, ArraySize, n+iWidth);
  return 0;

}



int setup(){

  iHeight = iWidth/3; 
  // 1D array
  ArrayLength = iWidth*iHeight*ColorSize;
  ElementSize = sizeof(unsigned char);
  ArraySize = ElementSize*ArrayLength ; 
  HeaderSize = 11 + (size_t) (log10(iHeight) +log10(iWidth)); 
	
  FileSize = HeaderSize + ArraySize; 
	
  /* create dynamic 1D array for RGB colors  */
  data = malloc (ArraySize);
  if (data == NULL ){
    printf ( "Could not allocate memory for the array\n");
    return 1;}

	
  return 0;
}


void info(){

  printf("ppm (P6) header size = %zu bytes\n", HeaderSize);
  printf("Array Size  = %zu bytes\n", ArraySize);
  printf("PPM file size  = %zu bytes\n", FileSize);

	
}



int end(){


  printf (" allways free memory (deallocate )  to avoid memory leaks \n"); // https://en.wikipedia.org/wiki/C_dynamic_memory_allocation
  free (data);
  info();
  return 0;

}



int main(){

	setup();
      MakeGradientImage(data, 0);
	
  end();

	
	return 0;
}


