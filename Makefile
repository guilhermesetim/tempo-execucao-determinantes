all: compiliar linkar

run:
	./bin/main.out

clean:
	rm ./obj/*.o ./bin/*.out

compiliar: main.o Laplace.o Chio.o Gauss.o


%.o: ./src/%.cpp
	g++ -c $< -o ./obj/$@


linkar:
	g++ ./obj/*.o -o ./bin/main.out
