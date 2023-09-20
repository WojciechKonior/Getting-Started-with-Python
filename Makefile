.PHONY: test clean

pointers:
	g++ -std=c++17 ./cherno-cpp-trainings/pointers.cpp -o ./cherno-cpp-trainings/main && ./cherno-cpp-trainings/main

clean:
