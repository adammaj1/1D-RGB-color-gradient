# save as a cubehelix.gp
# run : gnuplot cubehelix.gp
# https://gitlab.com/adammajewski/color_gradient



# Set the output file type
set terminal png

# list of gradient names;  update it maually
# gnuplot array is numbered from 1 to words(array), not like c arrays
# update list with order as in function GiveColor from p.c
titles = "Rainbow Linas Magma GrayL GrayNL2 GrayNL3 GraySqrt Green NewLinas CoolWarm GrayGamma GrayNL3Wave2 GrayNL3Wave10 GraySqrtWave ColorLWave ColorLWaveInverted NL3Wave5NonInv Cubehelix"
spaces = "RGB HSV"


# length of array spaces = nMax, but tex files are numbered from 0 to nMax-1 ( c style)
nMax = words(spaces)  


#  legend
set key inside bottom center horizontal
set key horizontal 
set key font ",8"

# remove upper and right axis
set border 3 back 
set xtics nomirror out
set ytics nomirror


set xlabel "gradient position"
set ylabel " intensity" 

# adjust y range to make a space for the legend 
set yrange [-0.2:1.1]


s=1 

# plot nMax images
# https://stackoverflow.com/questions/14946530/loop-structure-inside-gnuplot

do for [n=0:nMax] {

	print n 
	print 2 
	
	# Set the output file name
  	outfile = sprintf('%d.png',n)
  	set output outfile
  	
  	# Set the intput file name
  	infile = sprintf('%d.txt',n)

	# title of the image for the array of strings
	sTitle = sprintf(" 2D %s profiles of the %s colormap", word(spaces,s), word(titles,n+1) )
	set title sTitle
	
	
  	
  	
	# Now plot the data with lines and points
	plot infile using 1:2 with lines linecolor rgb 'red' title 'R', \
     	'' using 1:3 w lines linecolor rgb 'green' title 'G', \
     	'' using 1:4 w lines linecolor rgb 'blue' title 'B',\
     	'' using 1:5 w lines linecolor rgb 'black' title 'Y'
	
  
     	


     	
     	
     	



     	
# 3d plot of rgb profile

	
	print 3 
	
	
	set xlabel "R"
	set ylabel "G"
	set zlabel "B"

 	unset yrange
	set nokey	
	unset tics
	set xrange [0.0:1.0]
	set yrange [0.0:1.0]
	set zrange [0.0:1.0]
	set grid 
	set border 4095 ls 1 lc rgb "black" # Draw a complete box around a `splot`:
	
	set xzeroaxis
	set yzeroaxis
   	# set view <rot_x>{,{<rot_z>}{,{<scale>}{,<scale_z>}}}
   	# view is 60 rot_x, 30 rot_z, 1 scale, 1 scale_z
   	rot_x = 60
   	rot_z = 75
	set view rot_x,rot_z
	set view equal xyz # to get an orthographic projection with all of the axes scaled equally
	set xyplane at 0 # adjusts the position at which the xy plane is drawn in a 3D plot

	# Set the output file name
  	outfile = sprintf('%d_3d_%d_%d_v.png',n, rot_x, rot_z)
  	set output outfile
  	
  	

	# title of the image for the array of strings
	sTitle = sprintf("3D %s profile of the %s colormap", word(spaces,s), word(titles,n+1)  )
	set title sTitle
	
	# http://www.bersch.net/gnuplot-doc/linetypes,-colors,-and-styles.html
  	# There are several ways to specify color when one plots using gnuplot.
  	# Among them hex-string (like "#0000ff") and rgbvalue (like "256") 
  	# specification is very important.
  	# here rgb value is computed 
	rgb(r,g,b) = 65536*int(255*r) + 256*int(255*g) + int(255*b)
	
	
	
  	
	# Now plot the data with lines and points
	set label "(0,0,0)" at -0.1,0,0 right 
	#set label "0" at 1,-0.1,0 right
	#set label "1" at 1,+1.1,0 right 
	#set label "2" at 0,1.1,0 right 
	#set label "3" at 0,1,1 left 
	#set label "4" at 0,0,1 left 
	# set label "5" at 1,0,1 left 
	#set label "6" at 1,0,0 left 
	set label "(1,1,1)" at 1.1,1,1 left 
	splot 	infile using 1:1:1 with lines lw 3 lc rgb 'gray',\
		infile using 2:3:4:(rgb($2,$3,$4)) with points pt 7 ps 2 lc rgb variable ,\
		'-' w p pt 7 ps 2 lc rgb 'black'
		0 0 0
		1 1 1
		e


}



