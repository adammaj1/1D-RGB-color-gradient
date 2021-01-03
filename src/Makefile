all: 
	printf "make ppm and txt files"
	gcc d.c -lm -Wall
	./a.out
	printf "convert text files to png"
	gnuplot plot.gp
	printf "convert all ppm files to png using Image Magic convert"
	chmod +x g.sh
	./g.sh
	printf "delete all ppm and txt files"
	rm *.ppm
	rm *.txt
