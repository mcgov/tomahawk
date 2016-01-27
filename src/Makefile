CPPflags = -std=c++11 
build:
	g++ $(CPPflags) Battle.cpp -c 
	g++ $(CPPflags) Team.cpp -c 
	g++ $(CPPflags) Character.cpp -c 
	g++ $(CPPflags) TestTools.cpp -c
tests: build
	g++ $(CPPflags) TestTools.o Battle.o Team.o Character.o SimpleBattleTest.cpp -o SimpleBattleTestExec
	g++ $(CPPflags) TestTools.o Battle.o Team.o Character.o CharacterHungerTest.cpp -o CharacterHungerTestExec
clean:
	rm *.o
	rm *TestExec
