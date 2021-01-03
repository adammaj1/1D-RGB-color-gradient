/*

create enum from array of strings
lazy and naive method


gcc s.c -Wall 
./a.out


typedef enum  {RainbowHSV , Linas , Linas2 , RainbowFractalizer , OrangeBlueFractalizer , RainbowHSP , HSP , Magma , Cubehelix , CoolWarm , Green , Linear , Quadratic , Cubic , Sqrt , Gamma , LSine , SineExp , Sine , Smooth } ColorTransferFunctionType; 

typedef enum  {no = 0, steps = 1, tubes = 2} GradientJoiningType;



titles = "RainbowHSV  Linas  Linas2  RainbowFractalizer  OrangeBlueFractalizer  RainbowHSP  HSP  Magma  Cubehelix  CoolWarm  Green  Linear  Quadratic  Cubic  Sqrt  Gamma  LSine  SineExp  Sine  Smooth  "

sGradientJoiningType = "no  steps  tubes  "



*/


#include <stdio.h>
#include <stdlib.h>		// malloc
#include <string.h>		// strcat



		
const char *titles[] = {
/* multihue */ "RainbowHSV","Linas","Linas2","RainbowFractalizer", "OrangeBlueFractalizer", "RainbowHSP", "HSP", "Magma","Cubehelix", "CoolWarm", 
/* single hue */ "Green",
/* gray */ "Linear","Quadratic","Cubic","Sqrt", "Gamma", "LSine", "SineExp", "Sine" , "Smooth"};

const char * sGradientJoiningType[] = {"no" , "steps" , "tubes"};		

// print enum type
void PrintEnums(){

	// titles
	int i = 0;
	int iMax = sizeof(titles)/ sizeof(titles[0]);
	printf("typedef enum  {");
	for (i =0; i< iMax; ++i){
		printf("%s ", titles[i]);
		if ( i<iMax-1) printf(", ");
	}
	printf("} ColorTransferFunctionType; \n\n");
	
	// sGradientJoiningType
	i = 0;
	iMax = sizeof(sGradientJoiningType)/ sizeof(sGradientJoiningType[0]);
	printf("typedef enum  {");
	for (i =0; i< iMax; ++i){
		printf("%s = %d", sGradientJoiningType[i], i);
		if ( i<iMax-1) printf(", ");
	}
	printf("} GradientJoiningType;\n\n\n\n");
	
}

/*
gnuplot 
titles = "RainbowHSV Linas GraySineStep"
*/

// print gnuplot array for use in plot.gp 
void PrintGnuplot(){
	// titles
	int i = 0;
	int iMax = sizeof(titles)/ sizeof(titles[0]);
	printf("titles = \"");
	for (i =0; i< iMax; ++i){
		printf("%s  ", titles[i]);
		
	}
	printf("\"\n\n");

	// sGradientJoiningType
	i = 0;
	iMax = sizeof(sGradientJoiningType)/ sizeof(sGradientJoiningType[0]);
	printf("sGradientJoiningType = \"");
	for (i =0; i< iMax; ++i){
		printf("%s  ", sGradientJoiningType[i]);
		
	}
	printf("\"\n\n");




}
		

		
int main (){

	PrintEnums();
	PrintGnuplot();
	return 0;
}

