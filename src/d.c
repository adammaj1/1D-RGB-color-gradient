/*
https://gitlab.com/adammajewski/color_gradient


  =============================
  gcc d.c -Wall -lm

  ./a.out 

  


  ===================
c program creates (fMax * jMax) images and txt files







change single wave ascending 
----------------
https://docs.paraview.org/en/latest/ReferenceManual/colorMapping.html





---------------------------------------------------
https://blog.kitware.com/using-the-color-map-editor-in-paraview-the-basics/

Color mapping is a common visualization technique that maps data to colors, and displays the colors in the rendered image. 
Of course, to map the data array to colors, we use a transfer function. 
A transfer function can also be used to map the data array to opacity for rendering translucent surfaces or for volume rendering. 

There are separate transfer functions for color and opacity. 
----------------------------------------------------------------

https://www.researchgate.net/publication/220868898_Empowering_ISO-surfaces_with_volume_data
The color and opacity transfer functions are responsible for computing the color and opacity associated
with a ray sample. VoS uses a simple user defined
intensity-based color transfer function, and two alternative types of opacity transfer functions, based on
sample intensity information and on sample spatial
information.





*/

#include <stdio.h>
#include <string.h> // strncat
#include <stdlib.h> // malloc
#include <math.h> // log10





// color = RGB =  in the order red, green, blue
// color component ( channel) = double number from 0.0 to 1.0 



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



int fMax; // =  sizeof(titles)/sizeof(titles[0]); // 18; // see GiveColor function, it should be one more then max n in GiveColor
  

// add new title here and new function to GiveColor

const char *titles[] = {
/* multihue */ "RainbowHSV","Linas","Linas2","RainbowFractalizer", "OrangeBlueFractalizer", "RainbowHSP", "HSP", "Magma","Cubehelix", "CoolWarm", 
/* single hue */ "GreenCubic", "GreenCubicInv", "GreenCubicRoot", "BlueCubicInv", "RedCubicInv", "GreenSin",
/* gray */ "Linear","Quadratic","Cubic", "CubicInv", "Sqrt", "Root", "Gamma", "LSin", "SinExp", "Sin" , "Smooth"};
	
// use s.c program to update enum from arrray	
typedef enum  {RainbowHSV , Linas , Linas2 , RainbowFractalizer , OrangeBlueFractalizer , RainbowHSP , HSP , Magma , Cubehelix , CoolWarm , GreenCubic , GreenCubicInv, GreenCubicRoot, BlueCubicInv, RedCubicInv, GreenSin, Linear , Quadratic , Cubic , CubicInv, Sqrt , Root,  Gamma , LSin , SinExp , Sin , Smooth } ColorTransferFunctionType; 



int segments = 4; // the number should be even, 2 segments create one "wave"}


const char * sGradientJoiningType[] = {"no" , "steps" , "tubes"};
// enum items are contiguous 
typedef enum  {no = 0 , steps = 1 , tubes = 2} GradientJoiningType; 


int jMax; // =  sizeof(sGradientJoiningType)/sizeof(sGradientJoiningType[0]); // 18; // see GiveColor function, it should be one more then max n in GiveColor


 
// ------------------------ functions ----------------------------------------------------------------------


// fractional part of real (double) number
double frac(double d){

	double fraction = d - ((long)d);
	return fraction;
}
        
/* 
 GNUPLOT - stdfn.h 
 Copyright 1986 - 1993, 1998, 2004   Thomas Williams, Colin Kelley 
*/
#ifndef clip_to_01
#define clip_to_01(val)	\
    ((val) < 0 ? 0 : (val) > 1 ? 1 : (val))
#endif


// gives position of 2D point (ix,iy) in 1D array  ; uses also global variables: iWidth , ColorSize
int Give_i ( int iX, int iY)
{
  return (iX + iY * iWidth) * ColorSize;  
}



// =================================== color =====================================================================



/*

power function
https://en.wikipedia.org/wiki/Exponentiation#Power_functions



double gamma = 2.2;
double X = pow(position, 1.0/gamma) =  position ^(1/gamma)
-----------------------------
p 

3.0 = NL3 = Non Linear ( cubic) = position ^3
2.0 = NL2 = Non Linear ( quadratic) = position ^2 = sqr(position)
1.0 = L = linear 
1/2 = sqrt    = position ^ {1/2)  = sqrt(position)
1/2.2 = = gamma =  = position ^ {1 / 2.2)


p^3 = p*p*p

p^(1/3) = 



*/







// linear function = identity function
double GiveLinear(double position){
	
	
  return position;
 
}


// Non Linear 2 = NL2 = quadratic
double GiveNL2(const double position){
	
	
  double s =  position*position;
  return s;	

}

// cubic = Non Linear 3 = NL3
double GiveNL3(const double position){
	
	
  double s =  position*position*position;
  return s;
}

// from green to black = 
double GiveCubicInv(const double position){


	double p = 1.0 - position; // inverse input -> ascending wave	
	p = 1.0 - p*p*p; // inverse function of p^3
  	return p;	
	

}





// only from 0 to 1
double GiveSqrt(const double position){
	
	
  double s =  sqrt(position);
  return s;	

}

// only from 0 to 1
double GiveRoot(const double position){
	
  // input in [0,1] range	
  double s =  -1.0 + 2.0* position; // change range to [-1, 1] = s shape of function
  double e = 0.7;
  if (s<0.0) 
  	{  s = - pow(fabs(s) , e);}
  	else s = pow(s , e);
  // return to range [0,1]	
  s = (s + 1.0) / 2.0;
  return s;	

}




double GiveGamma(const double position){
  /*
    #from gnuplot
    gamma = 2.2
    color(gray) = gray**(1./gamma)
    set palette model RGB functions color(gray), color(gray), color(gray) # A gamma-corrected black and white palette
	
  */	
  double gamma = 2.2;
  double X = pow(position, 1.0/gamma);
  return X;

}





/*

https://peterkovesi.com/projects/colourmaps/colourmaptestimage.html

... a sine wave superimposed on a ramp function. 
The sine wave amplitude is set so that the range from peak to trough represents a series of features that are 10% of the total data range. 
The amplitude of the sine wave is modulated from its full value at the top of the image to 0 at the bottom. 


*/

double GiveLSin(const double position){
	
	// the commensts by P Kovesi
	// my values are slightly changed to get similar vusual effect
	double angle = position*2.0*M_PI; // input of the sin function is an angle in radians in range [0, 2*Pi]
	double f = iWidth/10.0; // frequency: The wavelength of the sine wave is set at 8 pixels 
	double s = 0.03*sin(f*angle); // wave range = amplitude of the sine wave = 10% of the total data range	
  	double X =  position +s;
  	
  	if (X>1.0 ||  X< 0.0) 
  		{X = clip_to_01(X);} // clipp to range [0,1]]
  	return X;

}

/*

only horizontal part of the 
Contrast Sensitivity and Campbell-Robson Chart 
CSF = COntrast Sensitivity Function


In this image, 
* horizontal axis
  * the luminance of pixels is modulated sinusoidally along the horizontal dimension. The frequency of modulation (spatial frequency) increases logarithmically, i.e., with exponential increase in frequency from left  to right.
  * spatial frequency from 0.5 to 50 ( or 100)


img = sin(exp(x)).*(y.^3);

*/ 


double GiveSinExp(double position){
	
	//
	//
	// range f(0) = 1 and f(1) = e  so [0,1] -> [1, e]
	double f = exp(5*position) ; // The frequency of modulation (spatial frequency) increases logarithmically, i.e., with exponential increase in frequency from left  to right  from 0.5 to 50 ( or 100)

	double angle = f; // input of the sin function is an angle in radians in range [0, 2*Pi]
	double s = (1.0+sin(angle))/2.0; // wave range from [-1,1] to [0,1]
  	return s;

}

/* 
compare 
* SmoothStep
* DarkLightWave from KFMovieMaker by Adam Sakareassen = 1/4 complete wave ie white to black 

Sin Wave Greyscale
The colours simply fade from black to white in a cycle.  This wave is generated with the sin function.  This method is useful when blending layers to create light to dark contrasts.

*/

double GiveSin(const double position){

	// input in [0,1] !!!!!
	// angle from -pi/2 to pi/2 = wave  ascending = from black to white
	// angle from -pi/2 to 3*pi/2 = wave is ascending + descending = from black thru white to black 
	
	
	// my values are slightly changed to get similar vusual effect
	//double angle = position*2.0*M_PI; // input of the sin function is an angle in radians in range [0, 2*Pi]
	//double angle = -M_PI/2.0 + 2.0*position*M_PI; // angle -pi/2 to pi/2 = half wave
	
	double angle = -M_PI/2.0 + position*M_PI; // angle -pi/2 to pi/2 = half wave ( only ascendig )
	double s = (1.0+sin(angle))/2.0; // map range from [-1,1] to [0,1]
  	return s;

}








/* 

Tt can be done directly in RGB space by a linear interpolation (in RGB) between each consecutive pair in this sequence:
* #ff0000 = red = rgb(255,0,0)
* #ffff00 = yellow = rgb (255,255,0)
* #00ff00 = green = rgb(0,255,0)
* #00ffff = cyan = rgb(0,255,255)
* #0000ff = blue = rgb(0,0,255)
* #ff00ff = magenta = rgb(255,0,255)
* #ff0000 = red = rgb (255,0,0)

Note that only one component changes for each interpolation, which simplifies things.


   input : position in [0,1]
   output: array rgb = RGB color 
   
   https://www.mathwarehouse.com/calculators/equation-line-from-2-points.php
   
   
   
*/
void GiveRGB_RainbowHSV(const double position, double rgb[])
{
  	// gradient with 6 segments
  	// from red to yellow
	  if (position < 0.16666666666){ // 1/6
		rgb[0] = 1.0; //R
  		rgb[1] = 6.0*position; //G
  		rgb[2] = 0.0; //B
  		return;}
  	
	// from yellow to green
	  if (position < 0.3333333333333){ // 2/6 = 1/3 
		rgb[0] = -6.0*position + 2.0; //R
  		rgb[1] = 1.0; //G
  		rgb[2] = 0.0; //B
  		return;}
  	  	
  	// from green to cyan
	  if (position < 0.5){ // 3/6 = 1/2
		rgb[0] = 0.0; //R
  		rgb[1] = 1.0; //G
  		rgb[2] = 6.0*position - 2.0; //B
  		return;}
  	
  	// from cyan to blue
	  if (position < 0.6666666666666){ // 4/6 = 2/3
		rgb[0] = 0.0; //R
  		rgb[1] = -6.0*position + 4.0; //G
  		rgb[2] = 1.0; //B
  		return;}

	// from blue to magenta
	 if (position < 0.8333333333333333333){ // 5/6 
		rgb[0] = 6.0*position - 4.0; //R
  		rgb[1] = 0.0; //G
  		rgb[2] = 1.0; //B
  		return;}
  		
  	// from blue to magenta
	 //if (position < 1.1){ // 6/6 
		rgb[0] = 1.0; //R
  		rgb[1] = 0.0; //G
  		rgb[2] = -6.0*position + 6.0; //B
  		
  		
  	
  	  	
  
}




/*
  Your new colormap is different and ugly-ish. The line between red-and-yellow is much much worse than before.  the red-yellow discontinuity is ... confusing, annoying. .. to me, at least.
  https://gitlab.com/adammajewski/LinasArtGallery_MandelbrotSet
  http://linas.org/art-gallery/index.html

  http://linas.org/art-gallery/src/fractal/image/flo2mtv.c


  struct rgb {
  char r;
  char g;
  char b;
  };

  static struct rgb vlt[256];





  void make_cmap (void) {
  int i, j;
  struct rgb black;
  black.r = black.g = black.b = 0x0;
  for (i=0; i<256; i++) vlt[i] = black;

  // set up a default look up table 
  // ramp up to blue 
  for (i=0; i<60; i++) {
  vlt[i].r = 0;
  vlt[i].g = 0;
  vlt[i].b = (char) i*3;
  }
  // ramp down from blue, up to green 
  for (i=60; i<120; i++) {
  vlt[i].r = 0;
  vlt[i].g = (char) (i-60)*3;
  vlt[i].b = (char) (120-i)*3;
  }
  // ramp from green to yellow 
  for (i=120; i<180; i++) {
  // vlt[i].r = (char) (((i-120)*7) / 2); 
  vlt[i].r = (char) (210 - (7*(180-i)*(180-i)) / 120);
  vlt[i].g = (char) (210 -i/4);
  vlt[i].b = 0;
  }
  // ramp from yellow to red (pink) 
  for (i=180; i<240; i++) {
  vlt[i].r = (char) (210 + (3*(i-180))/4);
  vlt[i].g = (char) (510 - 2*i);
  vlt[i].b = (char) (i-180)/3;
  }
  }


*/


  
  
   
void GiveRGB_Linas(const double position ,  double c[])
{
  /* based on the code by Linas Vepstas January 16 1994 : void make_cmap (void) */

   
  int i;
  int iMax = 239;
  i=(int)(iMax-1)*position;  
  c[0] = c[1] = c[2] = 0; /* set up a default look up table */
  
  
  // gradient with 4 segments 
  /* ramp from black to blue */
  if (i<60) {
    c[0] = 0;
    c[1] = 0;
    c[2] = i*3/255.0;
  }
  /* ramp down from blue, up to green */
  if (i>=60 && i<120) {
    c[0] = 0;
    c[1] = (i-60)*3/255.0;
    c[2] = (120-i)*3/355.0;
  }
  /* ramp from green to yellow */
  if (i >=120 && i<180) {
    /* vlt[i].r = (char) (((i-120)*7) / 2); */
    c[0] =  (210 - (7*(180-i)*(180-i)) / 120)/255.0;
    c[1] = (210 -i/4)/255.0;
    c[2] = 0;
  }
  /* ramp from yellow to red (pink) */
  if (i>=180 && i<iMax) {
    c[0] = (210 + (3*(i-180))/4)/255.0;
    c[1] = (510 - 2*i)/255.0;
    c[2] = (i-180)/(3*255.0);
  }
   
}




void GiveRGB_Linas2(const double position ,  double c[])
{
  /* based on the code by Linas Vepstas January 16 1994 : void make_cmap (void) */

  // gradient with 4 segments 0-0.25-0.5-0.75-1.0
  /* ramp from black to blue = (0.0 ; 0.25)) */
  if (position<0.25) {
    c[0] = 0;
    c[1] = 0;
    c[2] = 708*position/255.0; // B
    return;
  }
  /* ramp down from blue, up to green = (0.25 ; 0.5)*/
  if (position<0.5) {
  	  
    c[0] = 0; //R
    c[1] =  (-177+708*position)/255.0; // G
    c[2] =  (354 - 708* position)/255.0; // B
    return;
  }
  /* ramp from green to yellow  = (0.5 ; 0.75) */
  if (position<0.75) {
    	
    c[0] = (-420+840*position)/255.0; //R
    c[1] =  (219-84*position)/255.0; // G
    c[2] = 0;
    return;
  }
  /* position>0.75 :  ramp from yellow to red (pink) */
  	
  c[0] =  (84+168*position)/255.0; //R
  c[1] = (516-480*position)/255.0; // G
  c[2] = (-57 + 76*position)/255.0; // B

    
   
}




// https://github.com/Gnuplotting/gnuplot-palettes/blob/master/magma.pal
void GiveRGB_Magma(const double position, double c[]){
	
  double x, x2, x3, x4,x5,x6, x7, x8;
	
  double R, G, B;
	
  // 
  x = position;
  x2 = x*x;
  x3 = x*x2;
  x4 = x*x3;
  x5 = x*x4;
  x6 = x*x5;
  x7 = x*x6;
  x8 = x*x7;
	
  // found using https://arachnoid.com/polysolve/
  R = -2.1104070317295411e-002 +  1.0825531148278227e+000 * x -7.2556742716785472e-002 * x2 + 6.1700693562312701e+000 * x3 -1.1408475082678258e+001*x4 +  5.2341915705822935e+000*x5;
  if (R<0.0) R = 0.0; // small correction
	
  G = (-9.6293819919380796e-003 +  8.1951407027674095e-001 * x -2.9094991522336970e+000 * x2 + 5.4475501043849874e+000 * x3 -2.3446957347481536e+000*x4);
  if (G<0.0) G = 0.0;
	
  B = 3.4861713828180638e-002 -5.4531128070732215e-001*x + 4.9397985434515761e+001*x2 -3.4537272622690250e+002*x3 + 1.1644865375431577e+003*x4 -2.2241373781645634e+003*x5 + 2.4245808412415154e+003*x6 -1.3968425226952077e+003*x7 
    +3.2914755310075969e+002*x8;
	
  // clip
  if (R>1.0) R=1.0;
  
  
  c[0] = R; //R
  c[1] = G; // G
  c[2] = B; // B	
	

}

/* 
====================================================================================================
======================== mono ( single) hue ==========================================================
======================================================================================================= 
*/ 

// from green to black = 
void GiveRGB_GreenCubic(const double position, double c[]){
	
	double p = position*position*position; 
  c[0] = 0; //R
  c[1] = p; // G = pow(p, 3)
  c[2] = 0; // B	
	

}


// from green to black = 
void GiveRGB_GreenCubicInv(const double position, double c[]){


	double p = 1.0 - position; // inverse input -> ascending wave	
	// output color
  	c[0] = 0; //R
  	c[1] = 1.0 - p*p*p; //G = inverse function of p^3
  	c[2] = 0; // B	
	

}

// from green to black = 
void GiveRGB_GreenCubicRoot(const double position, double c[]){
	
	double p = position;
	p = sqrt(sqrt(p));	
	// output color
  	c[0] = 0; //R
  	c[1] = p; // G = pow(p, 1/3)
  	c[2] = 0; // B	
	

}


// from green to black = 
void GiveRGB_BlueCubicInv(const double position, double c[]){


	double p = 1.0 - position; // inverse input -> ascending wave	
	// output color
  	c[0] = 0; //R
  	c[1] = 0; //G = inverse function of p^3
  	c[2] = 1.0 - p*p*p; // B	
	

}


// from green to black = 
void GiveRGB_RedCubicInv(const double position, double c[]){


	double p = 1.0 - position; // inverse input -> ascending wave	
	// output color
  	c[0] = 1.0 - p*p*p; //R
  	c[1] = 0; //G = inverse function of p^3
  	c[2] = 0; // B	
	

}



// from green to black = 
void GiveRGB_GreenSin(const double position, double c[]){
	
	double p = GiveSin(position);
	// output color 
  	c[0] = 0; //R
  	c[1] = p; // G = pow(p, 3)
  	c[2] = 0; // B	
	

}







// here c = rgb
// http://www.kennethmoreland.com/color-maps/
void GiveRGB_CoolWarm(double position, double c[]){
	
	
  double R,G,B;
  double x = position;
  double x2 = x*x;
  double x3 = x*x2;
  double x4 = x*x3;
  double x5 = x*x4;
  double x6 = x*x5;
	
	 
	
  R =  2.4070949725529692e-001 + 8.3340565013768031e-001*x + 2.6191922175556543e+000*x2 - 4.0994936709055061e+000*x3 + 1.1014553405733734e+000*x4;
  G =  2.8978300321243283e-001 + 2.2641158553110725e+000*x - 6.8483016873914799e+000*x2 + 3.0238558676188145e+001*x3 - 7.0431595279051223e+001*x4 + 6.8583306445298092e+001*x5 - 2.4054295028042432e+001*x6;
  B =  7.4391703318514535e-001 + 1.8345430120497781e+000*x - 3.1885763361607244e+000*x2 - 8.4015787106949880e-001*x3 + 1.6162754134259683e+000*x4;

  // change range 
  c[0] = R; //R
  c[1] = G; // G
  c[2] = B; // B	
	
	

}













// ----------------------------




/* 
 GNUPLOT - stdfn.h 
 Copyright 1986 - 1993, 1998, 2004   Thomas Williams, Colin Kelley 

#ifndef clip_to_01
#define clip_to_01(val)	\
    ((val) < 0 ? 0 : (val) > 1 ? 1 : (val))
#endif


 input : position
 output : c array ( rgb color)
 
the colour scheme spirals (as a squashed helix) around the diagonal of the RGB colour cube 

https://arxiv.org/abs/1108.5083
A colour scheme for the display of astronomical intensity images by D. A. Green 


*/
void GiveRGB_Cubehelix(const double position, double c[]){



	/* GNUPLOT - color.h 
	 * Petr Mikulik, December 1998 -- June 1999
	 * Copyright: open source as much as possible
	*/

	// t_sm_palette 
  	/* gamma for gray scale and cubehelix palettes only */
  	double gamma = 1.5;

  	/* control parameters for the cubehelix palette scheme */
  	//set palette cubehelix start 0.5 cycles -1.5 saturation 1
	//set palette gamma 1.5
  	double cubehelix_start = 0.5;	/* offset (radians) from colorwheel 0 */
  	double cubehelix_cycles = -1.5;	/* number of times round the colorwheel */
  	double cubehelix_saturation = 1.0;	/* color saturation */
	double r,g,b;
	double gray = position; 
 


	
	/*
 	 Petr Mikulik, December 1998 -- June 1999
 	* Copyright: open source as much as possible
 	*/
	// /* Map gray in [0,1] to color components according to colorMode */
	// function color_components_from_gray
	// from gnuplot/src/getcolor.c
	double phi, a;
	
	phi = 2. * M_PI * (cubehelix_start/3. +  gray * cubehelix_cycles);
	
	// gamma correction
	if (gamma != 1.0)    gray = pow(gray, 1./gamma);
	
	
	a = cubehelix_saturation * gray * (1.-gray) / 2.;
	
	// compute
	r = gray + a * (-0.14861 * cos(phi) + 1.78277 * sin(phi));
	g = gray + a * (-0.29227 * cos(phi) - 0.90649 * sin(phi));
	b = gray + a * ( 1.97294 * cos(phi));
	
	// normalize to [0,1] range
	//r = clip_to_01(r);
	//g = clip_to_01(g);
	//b = clip_to_01(b);
	
	
  	c[0] = r; //R
  	c[1] = g; // G
  	c[2] = b; // B	

}


// ----------------------- HSP -------------------------------------------------

#define  Pr  .299
#define  Pg  .587
#define  Pb  .114



//  public domain function by Darel Rex Finley, 2006
//
//  This function expects the passed-in values to be on a scale
//  of 0 to 1, and uses that same scale for the return values.
//
//  See description/examples at alienryderflex.com/hsp.html

void RGBtoHSP(
double  R, double  G, double  B,
double *H, double *S, double *P) {

  //  Calculate the Perceived brightness.
  *P=sqrt(R*R*Pr+G*G*Pg+B*B*Pb);

  //  Calculate the Hue and Saturation.  (This part works
  //  the same way as in the HSV/B and HSL systems???.)
  if      (R==G && R==B) {
    *H=0.; *S=0.; return; }
  if      (R>=G && R>=B) {   //  R is largest
    if    (B>=G) {
      *H=6./6.-1./6.*(B-G)/(R-G); *S=1.-G/R; }
    else         {
      *H=0./6.+1./6.*(G-B)/(R-B); *S=1.-B/R; }}
  else if (G>=R && G>=B) {   //  G is largest
    if    (R>=B) {
      *H=2./6.-1./6.*(R-B)/(G-B); *S=1.-B/G; }
    else         {
      *H=2./6.+1./6.*(B-R)/(G-R); *S=1.-R/G; }}
  else                   {   //  B is largest
    if    (G>=R) {
      *H=4./6.-1./6.*(G-R)/(B-R); *S=1.-R/B; }
    else         {
      *H=4./6.+1./6.*(R-G)/(B-G); *S=1.-G/B; }}}



//  public domain function by Darel Rex Finley, 2006
//
//  This function expects the passed-in values to be on a scale
//  of 0 to 1, and uses that same scale for the return values.
//
//  Note that some combinations of HSP, even if in the scale
//  0-1, may return RGB values that exceed a value of 1.  For
//  example, if you pass in the HSP color 0,1,1, the result
//  will be the RGB color 2.037,0,0.
//
//  See description/examples at alienryderflex.com/hsp.html

void HSPtoRGB(
double  H, double  S, double  P,
double *R, double *G, double *B) {

  double  part, minOverMax=1.-S ;

  if (minOverMax>0.) {
    if      ( H<1./6.) {   //  R>G>B
      H= 6.*( H-0./6.); part=1.+H*(1./minOverMax-1.);
      *B=P/sqrt(Pr/minOverMax/minOverMax+Pg*part*part+Pb);
      *R=(*B)/minOverMax; *G=(*B)+H*((*R)-(*B)); }
    else if ( H<2./6.) {   //  G>R>B
      H= 6.*(-H+2./6.); part=1.+H*(1./minOverMax-1.);
      *B=P/sqrt(Pg/minOverMax/minOverMax+Pr*part*part+Pb);
      *G=(*B)/minOverMax; *R=(*B)+H*((*G)-(*B)); }
    else if ( H<3./6.) {   //  G>B>R
      H= 6.*( H-2./6.); part=1.+H*(1./minOverMax-1.);
      *R=P/sqrt(Pg/minOverMax/minOverMax+Pb*part*part+Pr);
      *G=(*R)/minOverMax; *B=(*R)+H*((*G)-(*R)); }
    else if ( H<4./6.) {   //  B>G>R
      H= 6.*(-H+4./6.); part=1.+H*(1./minOverMax-1.);
      *R=P/sqrt(Pb/minOverMax/minOverMax+Pg*part*part+Pr);
      *B=(*R)/minOverMax; *G=(*R)+H*((*B)-(*R)); }
    else if ( H<5./6.) {   //  B>R>G
      H= 6.*( H-4./6.); part=1.+H*(1./minOverMax-1.);
      *G=P/sqrt(Pb/minOverMax/minOverMax+Pr*part*part+Pg);
      *B=(*G)/minOverMax; *R=(*G)+H*((*B)-(*G)); }
    else               {   //  R>B>G
      H= 6.*(-H+6./6.); part=1.+H*(1./minOverMax-1.);
      *G=P/sqrt(Pr/minOverMax/minOverMax+Pb*part*part+Pg);
      *R=(*G)/minOverMax; *B=(*G)+H*((*R)-(*G)); }}
  else {
    if      ( H<1./6.) {   //  R>G>B
      H= 6.*( H-0./6.); *R=sqrt(P*P/(Pr+Pg*H*H)); *G=(*R)*H; *B=0.; }
    else if ( H<2./6.) {   //  G>R>B
      H= 6.*(-H+2./6.); *G=sqrt(P*P/(Pg+Pr*H*H)); *R=(*G)*H; *B=0.; }
    else if ( H<3./6.) {   //  G>B>R
      H= 6.*( H-2./6.); *G=sqrt(P*P/(Pg+Pb*H*H)); *B=(*G)*H; *R=0.; }
    else if ( H<4./6.) {   //  B>G>R
      H= 6.*(-H+4./6.); *B=sqrt(P*P/(Pb+Pg*H*H)); *G=(*B)*H; *R=0.; }
    else if ( H<5./6.) {   //  B>R>G
      H= 6.*( H-4./6.); *B=sqrt(P*P/(Pb+Pr*H*H)); *R=(*B)*H; *G=0.; }
    else               {   //  R>B>G
      H= 6.*(-H+6./6.); *R=sqrt(P*P/(Pr+Pb*H*H)); *B=(*R)*H; *G=0.; }}}



// here c = rgb
void GiveRGB_RainbowHSP(const double position, double c[]){

	double r;
	double g;
	double b;
	double h = position;
	double s = 1.0;
	double p = 1.0;
	
	
	// var color = HSPtoRGB({h: i / canv.width, s: 0.8, p: lerp(0.2,0.5,bright)});
	// hue = h is changing from 0 to 1
	// s and p are fixed to 1
	HSPtoRGB(h,s,p, &r, &g, &b);
	
	// normalize to [0,1] range
	r = clip_to_01(r);
	g = clip_to_01(g);
	b = clip_to_01(b);
	
	
  	c[0] = r; //R
  	c[1] = g; // G
  	c[2] = b; // B	


}



// here c = rgb
void GiveRGB_HSP(const double position, double c[]){

	double r;
	double g;
	double b;
	double h = 1.0;
	double s = 0.5;
	double p = position;
	
	
	// var color = HSPtoRGB({h: i / canv.width, s: 0.8, p: lerp(0.2,0.5,bright)});
	// p is changing from 0 to 1
	// s and h are fixed to 1
	HSPtoRGB(h,s,p, &r, &g, &b);
	
	// normalize to [0,1] range
	r = clip_to_01(r);
	g = clip_to_01(g);
	b = clip_to_01(b);
	
	
  	c[0] = r; //R
  	c[1] = g; // G
  	c[2] = b; // B	


}



/*
http://www.fractalizer.de/en/


*/
void GiveRGB_RainbowFractalizer(const double position, double rgb[]){

	double p = position*7; //relative posiion
	
	// gradient with 7 segments
  	// from magenta to black
	  if (position < 0.1428571428571429){ // 1/7
		rgb[0] = 1.0 - p; //R from 1 to 0
  		rgb[1] = 0.0; //G
  		rgb[2] = 1.0 - p; //B
  		return;}
  	
	// from black to red
	  if (position < 0.2857142857142857){ // 2/7 
		rgb[0] = p - 1.0; //R from
  		rgb[1] = 0.0; //G
  		rgb[2] = 0.0; //B
  		return;}
  	  	
  	// from red to yellow{ // 3/7
  	if (position  < 0.4285714285714286){ //3/7
		rgb[0] = 1.0; //R
  		rgb[1] = p - 2.0; //G
  		rgb[2] = 0.0; //B
  		return;}
  	
  	// from yellow to green
	  if (position < 0.5714285714285714){ // 4/7
		rgb[0] = 4.0 - p ; //R
  		rgb[1] = 1.0; //G
  		rgb[2] = 0.0; //B
  		return;}

	// from green to cyan
	 if (position < 0.7142857142857143){ // 5/7 
		rgb[0] = 0.0; //R
  		rgb[1] = 1.0; //G
  		rgb[2] = p - 4.0; //B from 0 to 1
  		return;}
  		
  	// from cyan to blue
	 if (position < 0.8571428571428571){ // 6/7 
		rgb[0] = 0.0; //R
  		rgb[1] = 6.0 - p ; //G from 1 to 0
  		rgb[2] = 1.0; //B 
  		return;}
  		
  	// from blue to magenta
	 //if (position < 1.1){ //  
		rgb[0] = p - 6.0; //R
  		rgb[1] = 0.0; //G
  		rgb[2] = 1.0; //B
  		





}

/*
http://www.fractalizer.de/en/

It is orange-blue gradient from the [Fractalizer program](http://www.fractalizer.de/en/).   

It has 5 segments:
* black 
* orange (255,80,0) = (1, 0.3137254901960784, 0)
* yellow ( 255, 255,128) = Unmellow Yellow = canary  = (1,1,0.5019607843137255)
* white
* blue
* black
*/
void GiveRGB_OrangeBlueFractalizer(const double position, double rgb[]){

	double p = position*5; //relative posiion
	
	// 2 points defining line
	double y0 = 80.0/255.0;
	double x0 = 1.0;
	double y1 = 1.0;
	double x1 = 2.0;
	double y2 = 128.0/255.0;
	double x2 = 2.0;
	
	// y = a*x + b 
	// https://planetcalc.com/8110/
	double a = (y1-y0)/(x1-x0);
	double b = y0 - a*x0;
	
	
	
	
	// gradient with 5 segments
  	// from black orange
	  if (position < 0.2){ // 1/5
		rgb[0] = p; //R from 0 to 1
  		rgb[1] = p*y0; //G from 0 to 80/255 = 0.3137254901960784
  		rgb[2] = 0.0 ; //B
  		return;}
  	
	// from orange to yellow
	  if (position < 0.4){ // 2/5 
	  
	  	a = (y1-y0)/(x1-x0);
		b = y0 - a*x0;
		rgb[0] = 1.0 ; //R 
  		rgb[1] = a*p +b; //G line from y1 to 1.0
  		rgb[2] = y2*(p - 1.0); //B from 0 to y2
  		return;}
  	  	
  	// from yellow to white{ // 3/5
  	if (position  < 0.6){ //3/5
  	
  		a = 1.0 - y2;
  		b = y2 - a*x2;
		rgb[0] = 1.0; //R
  		rgb[1] = 1.0; //G
  		rgb[2] = a*p+b; //B from y2 to 1.0
  		return;}
  	
  	// from white to blue
	  if (position < 0.8){ // 4/5
		rgb[0] = 4.0 - p ; // R from 1 to 0
  		rgb[1] = 4.0 - p; //G
  		rgb[2] = 1.0; //B
  		return;}

		
  	// from blue to black
	 //if (position < 1.1){ //  
		rgb[0] = 0.0; //R
  		rgb[1] = 0.0; //G
  		rgb[2] = 5.0 - p; //B
  		





}


















double ModifyPosition(const double position, const GradientJoiningType GradientJoining){
	
	// input position  should be in  [0,1] range 
	double p = position; // p = local copy of position
	// if position > 1 then we have repetition of colors = periodic function = wave   
	
	
	switch(GradientJoining){
	
		case no : {break;} // return input position witout modifications
		
		// periodic waves with different joinings
		case steps : {	p = p * segments; // periodic  = change range
				p = frac(p); 
    				break;}
    				
		case tubes : {	p = p * segments; // periodic = change range
				int ip = (int)p;
      				p = p-ip; // fractional part 
      				if (ip % 2) {p = 1.0-p;} // reverse gradient
				break;}
		default:{}
	}
	
	return p; // output in [0,1] range

}


void GiveRGB_Gray(const double position, const ColorTransferFunctionType ColorTransferFunction, double rgb[]){


	double s; // shade, color intensity
	double p = position; // p = local copy of position
	
	// compute color intensity ( shade) by applying ColorTransfer Function
	switch(ColorTransferFunction){ 
		case Linear : { s = p; break;}
    				
		case Quadratic : { s = p*p; break;}
		
		case Cubic : { s = p*p*p; break; }
		
		case CubicInv : { s = GiveCubicInv(p); break; }
		
		case Sqrt : { s = sqrt(p); break; } 
		
		case Root : { s = GiveRoot(p); break; } // range mapped from [0,1] to [-1,1] = s shaped function
		
		case Gamma : { s = GiveGamma(p); break;}
    				
		case Sin : { s = GiveSin(p); break;}
		
		case LSin : { s = GiveLSin(p); break; }
		
		case SinExp : { s = GiveSinExp(p); break; } 
		
		case Smooth : { s = (3.0 -2.0*p)*p*p; break; } // Smooth
	/* https://www.youtube.com/watch?v=60VoL-F-jIQ  Smoothstep: The most useful function by The Art of Code  = sinusoidal wave from 0.0 to 1.0 , gives similar effect as GraySine */

		
		
		default:{ }
	}
	
	// compute output gray (color )
	rgb[0] = s; //R
  	rgb[1] = s; //G
  	rgb[2] = s; //B
	
	
	
}







// **********************************************************************************************************************



/* 
   remember to update : 
   *  add new title in titles array
   * titles in plot.gp
*/

int GiveColor(const double position, const ColorTransferFunctionType ColorTransferFunction, const GradientJoiningType GradientJoining, double rgb[]){

	// input position is double number in range [0,1] = normalized
			 
	double p = position; // local copy of position
	p = ModifyPosition(p, GradientJoining); // modify the position - GradientJoiningType 
		
	

  	switch(ColorTransferFunction){

		// multihue		
  		case RainbowHSV: 	{GiveRGB_RainbowHSV(p, rgb); break;}
  		case Linas: 		{GiveRGB_Linas(p, rgb); break;}
  		case Linas2: 		{GiveRGB_Linas2(p, rgb); break;}
  		case RainbowFractalizer:{GiveRGB_RainbowFractalizer(p, rgb); break;} //
  		case OrangeBlueFractalizer: {GiveRGB_OrangeBlueFractalizer(p, rgb); break;} 
  		case Magma: 		{GiveRGB_Magma(p, rgb); break;}
  		case Cubehelix:	{GiveRGB_Cubehelix(p, rgb); break;}
  		case RainbowHSP: 	{GiveRGB_RainbowHSP(p, rgb); break;}
  		case HSP:	 	{GiveRGB_HSP(p, rgb); break;}
  		// diverging 
  		case CoolWarm: 	{GiveRGB_CoolWarm(p, rgb); break;}
  		// single hue
  		case GreenCubic: 		{GiveRGB_GreenCubic(p, rgb); break;}
  		case GreenCubicInv: 		{GiveRGB_GreenCubicInv(p, rgb); break;}
  		case GreenCubicRoot: 		{GiveRGB_GreenCubicRoot(p, rgb); break;}
  		case BlueCubicInv: 		{GiveRGB_BlueCubicInv(p, rgb); break;}
  		case RedCubicInv: 		{GiveRGB_RedCubicInv(p, rgb); break;}
  		case GreenSin: 		{GiveRGB_GreenSin(p, rgb); break;}
  		 
  		// no hue = gray, one function for all gray gradients
  		case Linear: 	
  		case Quadratic: 	
  		case Cubic: 
  		case CubicInv:		
  		case Sqrt: 
  		case Root:		
  		case Gamma: 		
  		case Sin: 		
  		case LSin: 		
  		case SinExp: 	
  		case Smooth: 	{GiveRGB_Gray(p, ColorTransferFunction, rgb); break;}
  
    		default:{}
  	}
	
	return 0;
}



void PrintRGBColor( FILE *fp,  double position, double rgb[]){


	// normalized to [0.0, 1.0] range RGB color channels
  double R = rgb[0]; 
  double G = rgb[1];
  double B = rgb[2];
  
  // normalized to [0.0, 1.0] range RGB color channels
  
  // [Relative luminance is formed as a weighted sum of linear RGB components](https://en.wikipedia.org/wiki/Luma_(video)) 
  // 
  //from function test_palette_subcommand from file gnuplot/src/command.c test_palette_subcommand
  //ntsc = 0.299 * rgb.r + 0.587 * rgb.g + 0.114 * rgb.b;
  double Y = 0.299*R + 0.587*G + 0.114*B;

   
  fprintf(fp, "%f, %f, %f, %f, %f\n", position, R, G, B, Y);

}







int PlotPoint(unsigned char A[], int i, double rgb[]){

  // conversion from [0,1] range to [0,255]
  A[i]   = (unsigned char) (255*rgb[0]); /* Red*/
  A[i+1] = (unsigned char) (255*rgb[1]); /* Green */
  A[i+2] = (unsigned char) (255*rgb[2]);  /* Blue */
  return 0;


}




// --------------------
int FillArrayAndTextFile (unsigned char A[] , ColorTransferFunctionType f,  GradientJoiningType j){

  int iX;
  int iXmax = iWidth;
  int iY;
  int iYmax = iHeight;
  int i; //  index of 1D array  
  double position; // number form 0.0 to 1.0 used for color gradient
  double rgb[3]; // 
	
  // text file used by the gnuplot for creating images
  char filename[50]; 
  sprintf (filename, "%s_%s.txt", titles[f], sGradientJoiningType[j]);
  
  
  
  
  
  
  FILE *fp = fopen(filename, "w");
  if (fp==NULL) {
    printf("Error opening text file!\n");
    return 1;
  }
  fprintf(fp, "# position \t\t R \t\t G \t\tB \t\tY\n"); // header of the text file
	
	
  //
  for(iX=0; iX<iXmax; ++iX){    
    position = (double) iX / iXmax;
    GiveColor(position, f, j, rgb);
    PrintRGBColor(fp, position, rgb); // 
      		
    for(iY=0; iY<iYmax; ++iY){
      i = Give_i(iX, iY);
      PlotPoint(A, i , rgb);
    }
        		
         			
  }


  fclose(fp);
  return 0;
}





// --------------- save dynamic "A" array of uinsigned char to the binary ppm file ( P6 ) --------------------------------
int SaveArray2PPM (unsigned char A[], size_t ASize,   ColorTransferFunctionType f,  GradientJoiningType j)
{

  FILE *fp;
  const unsigned char MaxColorComponentValue = 255;	/* color component is coded from 0 to 255 ;  it is 8 bit color file */
  
  
  
  
  
  char filename[50] ; 
  sprintf (filename, "%s_%s.ppm", titles[f], sGradientJoiningType[j]);
  
  

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
int MakeGradientImage(unsigned char A[],  ColorTransferFunctionType f,  GradientJoiningType j){


  FillArrayAndTextFile(A, f, j);
  SaveArray2PPM(A, ArraySize, f, j);
  return 0;

}



int setup(){


	fMax =  sizeof(titles)/sizeof(titles[0]); // 18; // see GiveColor function, it should be one more then max n in GiveColor
  	jMax =  sizeof(sGradientJoiningType)/sizeof(sGradientJoiningType[0]); 

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



// ================================== main ============================================

int main (){

  ColorTransferFunctionType f;
  GradientJoiningType j;
	
  setup();
  //
  for (f = 0; f< fMax; ++f)
  	for (j = 0; j < jMax; ++j)
    		MakeGradientImage(data, f, j);
	
  end();

  return 0;
}


















