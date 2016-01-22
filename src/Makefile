build:
	g++ Battle.cpp -c --std=c++11
	g++ Team.cpp -c --std=c++11
	g++ Character.cpp -c --std=c++11
tests: build
	g++ Battle.o Team.o Character.o SimpleBattleTest.cpp --std=c++11 -o SimpleBattleTestExec
	g++ Battle.o Team.o Character.o CharacterHungerTest.cpp --std=c++11 -o CharacterHungerTestExec
clean:
	rm *.o
	rm *TestExec