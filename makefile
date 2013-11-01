all:
	g++ TextQuery.cpp QueryResult.cpp RunQuery.cpp Query.cpp OrQuery.cpp AndQuery.cpp NotQuery.cpp main.cpp -std=c++0x -Wall -o main.o
	
