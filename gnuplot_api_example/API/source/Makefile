CPPFLAGS= -c -g -Wall -pedantic -std=c++17 

__start__: example.out
	./example.out

example.out: Dr3D_gnuplot_api.o example.o Wektor.o Macierz.o
	g++ -o example.out example.o Dr3D_gnuplot_api.o Wektor.o Macierz.o  -lpthread

#example.out: Dr3D_gnuplot_api.o example.o
#	g++ -o example.out example.o Dr3D_gnuplot_api.o -lpthread

example.o: example.cpp Dr3D_gnuplot_api.hh Wektor.hh Macierz.hh
	g++ ${CPPFLAGS} -o example.o example.cpp

#example.o: example.cpp Dr3D_gnuplot_api.hh 
#	g++ ${CPPFLAGS} -o example.o example.cpp

Dr3D_gnuplot_api.o: Dr3D_gnuplot_api.cpp Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o Dr3D_gnuplot_api.o Dr3D_gnuplot_api.cpp

Dr3D_gnuplot_api.hh: Draw3D_api_interface.hh
	touch Dr3D_gnuplot_api.hh

Macierz.o: Macierz.cpp Macierz.hh 
	g++ ${CPPFLAGS} -o Macierz.o Macierz.cpp

Wektor.o: Wektor.cpp SWektor.cpp Wektor.hh
	g++ ${CPPFLAGS} -o Wektor.o SWektor.cpp

clear:
	rm example.out example.o Dr3D_gnuplot_api.o
