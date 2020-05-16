CPPFLAGS= -c -g -Wall -pedantic -std=c++17 

__start__: example.out
	./example.out

example.out: Dr3D_gnuplot_api.o example.o Wektor.o Macierz.o MacierzRot.o Prostopadloscian.o GraniastoslupSzesc.o Dron.o Sruba.o Plaszczyzna.o Dno.o Woda.o Bryla.o
	g++ -o example.out example.o Dr3D_gnuplot_api.o Wektor.o Macierz.o MacierzRot.o Prostopadloscian.o GraniastoslupSzesc.o Dron.o Sruba.o Plaszczyzna.o Dno.o Woda.o Bryla.o -lpthread

example.o: example.cpp Dr3D_gnuplot_api.hh Wektor.hh Macierz.hh MacierzRot.hh Prostopadloscian.hh GraniastoslupSzesc.hh Dron.hh Sruba.hh Plaszczyzna.hh Dno.hh Woda.hh Bryla.hh
	g++ ${CPPFLAGS} -o example.o example.cpp

Dr3D_gnuplot_api.o: Dr3D_gnuplot_api.cpp Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o Dr3D_gnuplot_api.o Dr3D_gnuplot_api.cpp

Dr3D_gnuplot_api.hh: Draw3D_api_interface.hh
	touch Dr3D_gnuplot_api.hh

Bryla.o: Bryla.cpp Bryla.hh
	g++ ${CPPFLAGS} -o Bryla.o Bryla.cpp

Dno.o: Dno.cpp Dno.hh Plaszczyzna.hh
	g++ ${CPPFLAGS} -o Dno.o Dno.cpp

Woda.o: Woda.cpp Woda.hh Plaszczyzna.hh
	g++ ${CPPFLAGS} -o Woda.o Woda.cpp

Sruba.o: Sruba.cpp Sruba.hh
	g++ ${CPPFLAGS} -o Sruba.o Sruba.cpp

Dron.o: Dron.cpp  Dron.hh Sruba.hh
	g++ ${CPPFLAGS} -o Dron.o Dron.cpp

Plaszczyzna.o: Plaszczyzna.cpp Plaszczyzna.hh
	g++ ${CPPFLAGS} -o Plaszczyzna.o Plaszczyzna.cpp

GraniastoslupSzesc.o: GraniastoslupSzesc.cpp GraniastoslupSzesc.hh Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o GraniastoslupSzesc.o GraniastoslupSzesc.cpp

Prostopadloscian.o: Prostopadloscian.cpp Prostopadloscian.hh Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o Prostopadloscian.o Prostopadloscian.cpp

MacierzRot.o: MacierzRot.cpp MacierzRot.hh 
	g++ ${CPPFLAGS} -o MacierzRot.o MacierzRot.cpp

Macierz.o: Macierz.cpp Macierz.hh 
	g++ ${CPPFLAGS} -o Macierz.o Macierz.cpp

Wektor.o: Wektor.cpp SWektor.cpp Wektor.hh
	g++ ${CPPFLAGS} -o Wektor.o SWektor.cpp

clear:
	rm example.out example.o Dr3D_gnuplot_api.o Wektor.o Macierz.o MacierzRot.o Prostopadloscian.o GraniastoslupSzesc.o Dron.o Sruba.o Plaszczyzna.o Dno.o Woda.o Bryla.o
