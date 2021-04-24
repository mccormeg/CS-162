vehicle.exe: vehicle.o bike.o car.o motorcycle.o skateboard.o main.o
	g++ vehicle.o bike.o car.o motorcycle.o skateboard.o main.o
vehicle.o: vehicle.cpp
	g++ -c vehicle.cpp
bike.o: bike.cpp
	g++ -c bike.cpp
car.o: car.cpp
	g++ -c car.cpp
motorcycle.o: motorcycle.cpp
	g++ -c motorcycle.cpp
skateboard.o: skateboard.cpp
	g++ -c skateboard.cpp
main.o: main.cpp
	g++ -c main.cpp
clean:
	rm -f *.exe *.o
