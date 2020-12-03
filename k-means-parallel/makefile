
CC = g++
CXXFLAGS = -Wall -lrt -O3 -fopt-info -fopenmp -march=native -std=c++17

kmeans: k-means-release.o Vec.o Class.o Center.o Distance.o Optimize.o Benchmark.o Interface.o Validation.o
	$(CC) $(CXXFLAGS) -o kmeans k-means-release.o Vec.o Class.o Center.o Distance.o Optimize.o Benchmark.o Interface.o Validation.o

kmeans.o: k-means-release.cpp kmeans.h Vec.h Class.h Center.h Distance.h Optimize.h Benchmark.h Interface.h Validation.h
	$(CC) $(CXXFLAGS) -c k-means-release.cpp

Vec.o: Vec.h Common.h
Class.o: Class.h Common.h
Common.o: Common.h
Center.o: Center.h Common.h
Distance.o: Distance.h Common.h
Optimize.o: Optimize.h Common.h
Benchmark.o: Benchmark.h Common.h
Interface.o: Interface.h Common.h
Validation.o: Validation.h Common.h