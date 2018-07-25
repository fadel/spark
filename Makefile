CXXFLAGS=-O2 -Wall

all: spark

spark: src/main.cpp
	g++ $(CXXFLAGS) -o spark src/main.cpp

clean:
	rm -f spark
