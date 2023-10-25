all: executable.out

executable.out: Tableaudynamique.o ElementTD.o
	g++ Tableaudynamique.o ElementTD.o –o executable.out

Tableaudynamique.o: Tableaudynamique.h Tableaudynamique.cpp ElementTD.h
	g++ Tableaudynamique.cpp

ElementTD.o: ElementTD.h ElementTD.cpp
	g++ ElementTD.cpp

clean:
	rm *.o

veryclean: clean
	rm *.out