todo: main.o dtfecha.o dtlibro.o dtmaterial.o dtrevista.o lector.o libro.o material.o prestamo.o revista.o
	g++ -Wall -o main main.o dtfecha.o dtlibro.o dtmaterial.o dtrevista.o lector.o libro.o material.o prestamo.o revista.o
main.o: main.cpp
	g++ -Wall -c main.cpp
dtfecha.o: dtfecha.h dtfecha.cpp
	g++ -Wall -c dtfecha.cpp
dtlibro.o: dtlibro.h dtlibro.cpp
	g++ -Wall -c dtlibro.cpp
dtmaterial.o: dtmaterial.h dtmaterial.cpp
	g++ -Wall -c dtmaterial.cpp
dtrevista.o: dtrevista.h dtrevista.cpp
	g++ -Wall -c dtrevista.cpp
lector.o: lector.h lector.cpp
	g++ -Wall -c lector.cpp
libro.o: libro.h libro.cpp
	g++ -Wall -c libro.cpp
material.o: material.h material.cpp
	g++ -Wall -c material.cpp
prestamo.o: prestamo.h prestamo.cpp
	g++ -Wall -c prestamo.cpp
revista.o: revista.h revista.cpp
	g++ -Wall -c revista.cpp

limpiar:
	rm -f main.exe
	rm -f *.o