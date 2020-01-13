project4: Barbarian.o BlueMen.o HarryPotter.o inputValidation.o main.o Medusa.o Vampire.o Queue.o
	g++ -std=c++0x -g Barbarian.o BlueMen.o HarryPotter.o inputValidation.o main.o Medusa.o Vampire.o Queue.o -o project4

Barbarian.o: Barbarian.cpp
	g++ -std=c++0x -c Barbarian.cpp

BlueMen.o: BlueMen.cpp
	g++ -std=c++0x -c BlueMen.cpp

HarryPotter.o: HarryPotter.cpp
	g++ -std=c++0x -c HarryPotter.cpp

inputValidation.o: inputValidation.cpp
	g++ -std=c++0x -c inputValidation.cpp

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

Medusa.o: Medusa.cpp
	g++ -std=c++0x -c Medusa.cpp

Vampire.o: Vampire.cpp
	g++ -std=c++0x -c Vampire.cpp

Queue.o: Queue.cpp
	g++ -std=c++0x -c Queue.cpp

clean:
	rm *.o project4
