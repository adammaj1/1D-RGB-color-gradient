/*
https://gitlab.com/adammajewski/color_gradient

https://colormeasures.org/

  =============================
  gcc j.c -Wall -lm

  ./a.out 

  


  ===================
c program creates nMax 

----------------


Sample points of this colormap are not strictly monotonic increasing, but have to be. 



*/

#include <stdio.h>
#include <string.h> // strncat
#include <stdlib.h> // malloc
#include <math.h> // log10

// color = RGB =  in the order red, green, blue
// color component ( channel) = double number from 0.0 to 1.0 


// titles = "Rainbow Linas Magma GrayL GrayNL2 GrayNL3 GraySqrt Green NewLinas CoolWarm GrayGamma GrayNL3Wave2 GrayNL3Wave10 GraySqrtWave ColorLWave ColorLWaveInverted NL3Wave5NonInv Cubehelix"
const char *titles[] = {"RainbowHSV","Linas","Magma","GrayL","GrayNL2","GrayNL3","GraySqrt","Green","NewLinas","CoolWarm","GrayGamma","GrayNL3Wave2","GrayNL3Wave10","GraySqrtWave","GrayLWave","GrayLWaveInverted","NL3Wave5NonInv","Cubehelix"};


 




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
void GiveRainbowColor(double position, double rgb[])
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


   
void GiveLinasColor(double position ,  double c[])
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

// https://github.com/Gnuplotting/gnuplot-palettes/blob/master/magma.pal
void GiveMagmaColor(double position, double c[]){
	
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

void GiveGrayColorL(double position, double c[]){
	
	
  double X =  position;
  //  
  c[0] = X; //R
  c[1] = X; // G
  c[2] = X; // B	
	

}

void GiveGrayColorNL2(double position, double c[]){
	
	
  double X =  1.0 - (position*position);
  // 
  c[0] = X; //R
  c[1] = X; // G
  c[2] = X; // B	
	

}


void GiveGrayColorNL3(double position, double c[]){
	
	
  double X =  1.0 - (position*position*position);
  //  
  c[0] = X; //R
  c[1] = X; // G
  c[2] = X; // B	
	

}


void GiveGrayColorSqrt(double position, double c[]){
	
	
  double X =  sqrt(position);
  // change range 
  c[0] = X; //R
  c[1] = X; // G
  c[2] = X; // B	
	

}



// from green to black = 
void GiveColorGreen(double position, double c[]){
	
	
  double X =  1.0- (position*position*position);
  // change range 
  c[0] = 0; //R
  c[1] = X; // G
  c[2] = 0; // B	
	

}



void GiveLinas2Color(double position ,  double c[])
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



// http://www.kennethmoreland.com/color-maps/
void GiveColorCoolWarm(double position, double c[]){
	
	
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



void GiveGrayGammaColor(double position, double c[]){
  /*
    #from gnuplot
    gamma = 2.2
    color(gray) = gray**(1./gamma)
    set palette model RGB functions color(gray), color(gray), color(gray) # A gamma-corrected black and white palette
	
  */	double gamma = 2.2;
  double X = pow(position, 1.0/gamma);
  
  // change range 
  c[0] = X; //R
  c[1] = X; // G
  c[2] = X; // B	
	

}


void GiveGrayColorNL3Wave2(double position, double c[]){
	
  int segments=2;
  position= segments*position;
  /* if position > 1 then we have repetition of colors it maybe useful    */
  if (position>1.0)
    {	int p = (int)position;
      position=position-p; // fractional part 
      if (p % 2)
	{position = 1.0-position;} // reverse gradient
    }
				 

  double X =  1.0- (position*position*position);
  // change range 
  c[0] = X; //R
  c[1] = X; // G
  c[2] = X; // B	
	

}




void GiveGrayColorNL3Wave10(double position, double c[]){
	
  int segments=10;
  position= segments*position;
  /* if position > 1 then we have repetition of colors it maybe useful    */
  if (position>1.0)
    {	int p = (int)position;
      position=position-p; // fractional part 
      if (p % 2)
	{position = 1.0-position;} // reverse gradient
    }
				 

  double X =  1.0- (position*position*position);
  // 
  c[0] = X; //R
  c[1] = X; // G
  c[2] = X; // B	
	

}



void GiveGrayColorSqrtWave(double position, double c[]){
  int segments=10;
  position= segments*position;
  /* if position > 1 then we have repetition of colors it maybe useful    */
  if (position>1.0)
    {	int p = (int)position;
      position=position-p; // fractional part 
      if (p % 2)
	{position = 1.0-position;} // reverse gradient
    }
				 

	
  double X =  sqrt(position);
  // 
  c[0] = X; //R
  c[1] = X; // G
  c[2] = X; // B	
	

}





void GiveGrayColorLWave(double position, double c[]){
	
  int segments=10;
  position= segments*position;
  /* if position > 1 then we have repetition of colors it maybe useful    */
  if (position>1.0)
    {	int p = (int)position;
      position=position-p; // fractional part 
      			
    }
				 

  double X =  1.0 - position;
  // 
  c[0] = X; //R
  c[1] = X; // G
  c[2] = X; // B	
	

}



void GiveGrayColorLWaveInverted(double position, double c[]){
	
  int segments=10;
  position= segments*position;
  /* if position > 1 then we have repetition of colors it maybe useful    */
  if (position>1.0)
    {	int p = (int)position;
      position=position-p; // fractional part 
      if (p % 2)
	{position = 1.0-position;} // reverse gradient
    }
				 

  double X =  1.0 - position;
  
  c[0] = X; //R
  c[1] = X; // G
  c[2] = X; // B	
	

}




void GiveGrayColorNL3Wave5NonInv(double position, double c[]){
	
  int segments=5;
  position= segments*position;
  /* if position > 1 then we have repetition of colors it maybe useful    */
  if (position>1.0)
    {	int p = (int)position;
      position=position-p; // fractional part 
      			
    }
				 

  double X =  1.0 -(position*position*position);
  // change range 
  c[0] = X; //R
  c[1] = X; // G
  c[2] = X; // B	
	

}


// ----------------------------




/* 
 GNUPLOT - stdfn.h 
 Copyright 1986 - 1993, 1998, 2004   Thomas Williams, Colin Kelley 
*/
#ifndef clip_to_01
#define clip_to_01(val)	\
    ((val) < 0 ? 0 : (val) > 1 ? 1 : (val))
#endif

/*
 input : position
 output : c array ( rgb color)
 
the colour scheme spirals (as a squashed helix) around the diagonal of the RGB colour cube 

https://arxiv.org/abs/1108.5083
A colour scheme for the display of astronomical intensity images by D. A. Green 
*/
void GiveCubehelixColor(double position, double c[]){



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



/* 
   remember to update : 
   * nMax in main function
   * titles in plot.gp
   */

int GiveColor(double position, int n, double c[]){

  switch(n){
	
  case 0: {GiveRainbowColor(position, c); break;}
  case 1: {GiveLinasColor(position,c); break;}
  case 2: {GiveMagmaColor(position,c); break;}
  case 3: {GiveGrayColorL(position,c); break;}
  case 4: {GiveGrayColorNL2(position,c); break;}
  case 5: {GiveGrayColorNL3(position,c); break;}
  case 6: {GiveGrayColorSqrt(position,c); break;}
  case 7: {GiveColorGreen(position,c); break;}
  case 8: {GiveLinas2Color(position,c); break;}
  case 9: {GiveColorCoolWarm(position,c); break;}
  case 10: {GiveGrayGammaColor(position,c); break;}
  case 11: {GiveGrayColorNL3Wave2(position,c); break;}
  case 12: {GiveGrayColorNL3Wave10(position,c); break;}
  case 13: {GiveGrayColorSqrtWave(position,c); break;}
  case 14: {GiveGrayColorLWave(position,c); break;}
  case 15: {GiveGrayColorLWaveInverted(position,c); break;}
  case 16: {GiveGrayColorNL3Wave5NonInv(position,c); break;}
  case 17: {GiveCubehelixColor(position,c); break;}
  default:{GiveRainbowColor(position, c);}
  }
	
  return 0;


}



void PrintColor( FILE *fp,  double position, double rgb[]){
  // normalized to [0.0, 1.0] range RGB color channels
  // 
  fprintf(fp, "%f, %f, %f, %f,\n", position, rgb[0], rgb[1], rgb[2]);

}






int CreateGradientJsonFile(int  n){

	
  int iX;
  int iXmax = 255;
  
  double position; // number form 0.0 to 1.0 used for color gradient
  double  rgb[3]; // 
	
  // text file 
  char name [100]=""; /* name of file */
  strncat(name, titles[n], strlen(titles[n])); /*  */
  //printf("%s\n", name);
  // printf("%s\n", titles[n]);
  char *filename = strncat(name, ".json", 5);
  
  FILE *fp = fopen(filename, "w");
  if (fp==NULL) {
    printf("Error opening text file!\n");
    return 1;
  }
  
  
  
  /* header of the json file
[
{
"ColorSpace" : "RGB",
"Name" : "RARGBInterpolated",
"NanColor" : [ 1, 0, 0 ],
"RGBPoints" : [ 
*/
	fprintf(fp, "[\n{\n\"ColorSpace\" : \"RGB\",\n\"Name\" :\"%s\",\n\"NanColor\" : [ 1, 0, 0 ],\n\"RGBPoints\" : [\n", titles[n]);

	
  //
  for(iX=0; iX<iXmax; ++iX){    
    position = (double) iX / iXmax;
    GiveColor(position, n, rgb);
    PrintColor(fp, position, rgb); // 
   			
  }
  // last row
  position = 1.0;
  GiveColor(position, n, rgb);
  fprintf(fp, "%f, %f, %f, %f\n", position, rgb[0], rgb[1], rgb[2]);
  // end of the json file
  fprintf(fp, "]\n}\n]\n");
  fclose(fp);
  printf("file %s closed\n", filename);
  //printf("%s\n", titles[n]);
  //printf("%s\n", name);
  return 0;


}







// ================================== main ============================================

int main (){

  int n;
  int nMax = 18; // see GiveColor function, it should be one more then max n in GiveColor
  
  
   //
  for (n = 0; n< nMax; ++n)
    CreateGradientJsonFile( n);
	
  

  return 0;
}
