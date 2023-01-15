all: compiliar linkar

run:
	./bin/main.out

clean:
	rm ./obj/*.o ./bin/*.out ./csv/input/teste{?,??}.csv

compiliar:
	g++ -c ./src/main.cpp -o ./obj/main.o
	g++ -c ./src/Laplace.cpp -o ./obj/Laplace.o
	g++ -c ./src/Chio.cpp -o ./obj/Chio.o
	g++ -c ./src/Gauss.cpp -o ./obj/Gauss.o

linkar:
	g++ ./obj/*.o -o ./bin/main.out