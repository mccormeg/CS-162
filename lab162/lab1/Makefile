mult_div:
	g++ lab1.cpp prog.cpp -mult_div
	CC = g++
	exe_file= lab1
	$(exe_file): lab1.o prog.o
		$(CC) lab1.o prog.o -o $(exe_file)
	lab1.o: lab1.cpp
		$(CC) -c lab1.cpp
	prog.o: prog.cpp
		$(CC) -c prog.cpp

clean:
	rm -f *.out *.o $(exe_file)
