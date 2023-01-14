all: compiliar linkar

run:
	./bin/main.out

compiliar:
	g++ -c ./src/main.cpp -o ./obj/main.o
	g++ -c ./src/Sarrus.cpp -o ./obj/Sarrus.o
	g++ -c ./src/Triangulo.cpp -o ./obj/Triangulo.o
	g++ -c ./src/Jacob.cpp -o ./obj/Jacob.o
	g++ -c ./src/Laplace.cpp -o ./obj/Laplace.o

linkar:
	g++ ./obj/*.o -o ./bin/main.out