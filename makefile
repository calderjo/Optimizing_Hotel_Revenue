project2a.x: main.o inputToTuples.o DAG.o Topological_Sort.o max_rev_algo.o
	g++ -ggdb -o project2a.x max_rev_algo.o Topological_Sort.o DAG.o inputToTuples.o main.o

main.o: main.cpp inputToTuples.h DAG.h Topological_Sort.h max_rev_algo.h
	g++ -std=c++17 -ggdb main.cpp -o main.o -c

inputToTuples.o: inputToTuples.cpp inputToTuples.h
	g++ -std=c++17 -ggdb inputToTuples.cpp -o inputToTuples.o -c

DAG.o: DAG.cpp DAG.h
	g++ -std=c++17 -ggdb DAG.cpp -o DAG.o -c

Topological_Sort.o: Topological_Sort.cpp Topological_Sort.h DAG.h
	g++ -std=c++17 -ggdb Topological_Sort.cpp -o Topological_Sort.o -c

max_rev_algo.o: max_rev_algo.cpp max_rev_algo.h DAG.h
	g++ -std=c++17 -ggdb max_rev_algo.cpp -o max_rev_algo.o -c

clean:
	/bin/rm -f *.x *.o *~
