distance: main.o distance.o
	g++ main.o distance.o

main.o: main.cpp distance.h
	g++ -c main.cpp

distance.o: distance.cpp distance.h
	g++ -c distance.cpp

clean:
	rm *.o a.out
