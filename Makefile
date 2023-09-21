.PHONY: test clean
CH_DIR=./cherno-cpp-trainings

pointers:
	g++ -std=c++17 ${CH_DIR}/pointers.cpp -o ${CH_DIR}/main && ${CH_DIR}/main

networking:
	g++ -std=c++17 ${CH_DIR}/networking.cpp -o ${CH_DIR}/main && ${CH_DIR}/main

clean:
