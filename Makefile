all: compiliar linkar

run:
	./bin/main.out

clean:
	rm -rf ./obj/*.o ./bin/*.out

compiliar: \
	./obj/main.o \
	./obj/Laplace.o \
	./obj/Chio.o \
	./obj/Gauss.o


./obj/%.o: ./src/%.cpp
	g++ -c $< -o $@


linkar:
	g++ ./obj/*.o -o ./bin/main.out

gerar-teste: 
	g++ -c ./app/gerador-testes.cpp -o ./app/gerador-testes.o
	g++ ./app/gerador-testes.o -o ./app/gerador-testes.out
	./app/gerador-testes.out
