RPS.exe: Tool.o Paper.o Rock.o Scissors.o RPSGame.o main.o
	g++ Tool.o Paper.o Rock.o Scissors.o RPSGame.o main.o
Tool.o: Tool.cpp
	g++ -c Tool.cpp
Paper.o: Paper.cpp
	g++ -c Paper.cpp
Rock.o: Rock.cpp
	g++ -c Rock.cpp
Scissors.o: Scissors.cpp
	g++ -c Scissors.cpp
RPSGame.o: RPSGame.cpp
	g++ -c RPSGame.cpp
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm -f *.o *.exe
