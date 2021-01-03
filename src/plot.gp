# save as a plot.gp
# run : gnuplot plot.gp

# Set the output file type
set terminal png

# list of gradient names;  update it maually
# gnuplot array is numbered from 1 to words(array), not like c arrays
# use s.c program to update lists from titles and sGradientJoiningType arrays

titles = "RainbowHSV  Linas  Linas2  RainbowFractalizer  OrangeBlueFractalizer  RainbowHSP  HSP  Magma  Cubehelix  CoolWarm GreenCubic GreenCubicInv GreenCubicRoot BlueCubicInv RedCubicInv GreenSin Linear  Quadratic  Cubic  CubicInv Sqrt  Root Gamma  LSin  SinExp  Sin  Smooth  "

sGradientJoiningType = "no  steps  tubes  "







# length of array titles = nMax, but tex files are numbered from 0 to nMax-1 ( c style)
nMax = words(titles) -1 
jMax = words(sGradientJoiningType) -1 


#  legend
set key inside bottom center horizontal
set key horizontal 
set key font ",8"

# remove upper and right axis
set border 3 back 
set xtics nomirror out
set ytics nomirror


set xlabel "gradient position"
set ylabel "color channel intensity" 

# adjust y range to make a space for the legend 
set yrange [-0.2:1.1]


# plot nMax images
# https://stackoverflow.com/questions/14946530/loop-structure-inside-gnuplot

do for [n=0:nMax]{

	do for [j=0:jMax] {
		# Set the output file name
  		outfile = sprintf('%s_%s_2D.png',word(titles,n+1), word(sGradientJoiningType, j+1))
  		set output outfile
  	
  		# Set the intput file name
  		infile = sprintf('%s_%s.txt',word(titles,n+1), word(sGradientJoiningType, j+1))

		# title of the image for the array of strings
		sTitle = sprintf(" 2D RGB profiles of the %s colormap with %s GradientJoiningType", word(titles,n+1), word(sGradientJoiningType, j+1) )
		set title sTitle
		
		# Now plot the data with lines and points
		plot infile using 1:2 with lines linecolor rgb 'red' title 'R', \
     		'' using 1:3 w lines linecolor rgb 'green' title 'G', \
     		'' using 1:4 w lines linecolor rgb 'blue' title 'B',\
     		'' using 1:5 w lines linecolor rgb 'black' title 'Y'
	
  
	}
}
