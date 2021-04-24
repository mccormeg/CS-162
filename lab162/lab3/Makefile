hospital.exe: PatientAccount.o Pharmacy.o Surgery.o main.o
	g++ PatientAccount.o Pharmacy.o Surgery.o main.o
PatientAccount.o: PatientAccount.cpp
	g++ -c PatientAccount.cpp
Pharmacy.o: Pharmacy.cpp
	g++ -c Pharmacy.cpp
Surgery.o: Surgery.cpp
	g++ -c Surgery.cpp
main.o: main.cpp
	g++ -c main.cpp
clean: 
	rm -f *.o *.cpp *.exe

