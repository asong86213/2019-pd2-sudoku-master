all: Sudoku.o generate.cpp solve.cpp transform.cpp
	g++ -o generate generate.cpp Sudoku.o
	g++ -o solve solve.cpp Sudoku.o
	g++ -o transform transform.cpp Sudoku.o

sudoku.o: Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp

clean:
	rm *.o test
