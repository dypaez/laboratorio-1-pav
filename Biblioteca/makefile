todo: main.o dtfecha.o dtlibro.o dtmaterial.o dtrevista.o lector.o libro.o material.o prestamo.o revista.o
	g++ -Wall -o main main.o dtfecha.o dtlibro.o dtmaterial.o dtrevista.o lector.o libro.o material.o prestamo.o revista.o
main.o: main.cpp
	g++ -Wall -c main.cpp
dtfecha.o: dtfecha.cpp dtfecha.h
	g++ -Wall -c dtfecha.cpp
dtlibro.o: dtlibro.cpp dtlibro.h constantes.h
	g++ -Wall -c dtlibro.cpp
dtmaterial.o: dtmaterial.cpp dtmaterial.h
	g++ -Wall -c dtmaterial.cpp
dtrevista.o: dtrevista.cpp dtrevista.h constantes.h
	g++ -Wall -c dtrevista.cpp
lector.o: lector.cpp lector.h
	g++ -Wall -c lector.cpp
libro.o: libro.cpp libro.h
	g++ -Wall -c libro.cpp
material.o: material.cpp material.h 
	g++ -Wall -c material.cpp
prestamo.o: prestamo.cpp prestamo.h 
	g++ -Wall -c prestamo.cpp
revista.o: revista.cpp revista.h 
	g++ -Wall -c revista.cpp

limpiar:
	rm -f main.exe
	rm -f *.o