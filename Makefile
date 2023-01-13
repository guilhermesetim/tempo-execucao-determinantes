all: compiliar linkar

run:
	./bin/main.out

compiliar:
	g++ -c ./src/main.cpp -o ./obj/main.o
	g++ -c ./src/Sarrus.cpp -o ./obj/Sarrus.o
	g++ -c ./src/Triangulo.cpp -o ./obj/Triangulo.o

linkar:
	g++ ./obj/*.o -o ./bin/main.out