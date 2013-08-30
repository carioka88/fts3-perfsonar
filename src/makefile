### Author: Rocio Rama Ballesteros 
### OpenLab Summer Student 2013

# Which compiler should be used
CXX = g++
CC = $(CXX)

# What flags should be passed to the compiler
DEBUG_LEVEL = -g
EXTRA_CCFLAGS = -Wall
CXXFLAGS = $(DEBUG_LEVEL) $(EXTRA_CCFLAGS)
CCFLAGS = $(CXXFLAGS)
OBJECTS = main.o TcpOptimizer.o INetworkLink.o UtilsPerfSonar.o UtilsJson.o
LIBS = -lcurl

# all is the default rule
all: main

main: $(OBJECTS)
	$(CXX) -o main $(OBJECTS) $(LIBS)

TcpOptimizer.o: TcpOptimizer.h TcpOptimizer.cpp
	$(CXX) $(CXXFLAGS) -c TcpOptimizer.cpp

INetworkLink.o: INetworkLink.h INetworkLink.cpp
	$(CXX) $(CXXFLAGS) -c INetworkLink.cpp

UtilsPerfsonar.o: UtilsPerfSonar.h UtilsPerfSonar.cpp
	$(CXX) $(CXXFLAGS) -c UtilsPerfSonar.cpp

UtilsJson.o: UtilsJson.h UtilsJson.cpp
	$(CXX) $(CXXFLAGS) -c UtilsJson.cpp

main.o: main.cpp TcpOptimizer.h INetworkLink.h UtilsPerfSonar.h UtilsJson.h
	$(CXX) $(CXXFLAGS) -c main.cpp


clean:
	rm -rf main $(OBJECTS)

