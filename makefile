# Source: http://web.engr.oregonstate.edu/~rookert/cs162/03.mp4

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o Ant.o Board.o menu.o
SRCS = main.cpp  Ant.cpp Board.cpp menu.cpp
HEADERS = Ant.hpp Board.hpp menu.hpp

project2: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o project2

$(OBJS): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	rm *.o project2
