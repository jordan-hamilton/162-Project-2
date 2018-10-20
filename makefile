# Source: http://web.engr.oregonstate.edu/~rookert/cs162/03.mp4

CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o Animal.o Menu.o Penguin.o Tiger.o Turtle.o Zoo.o
SRCS = main.cpp  Animal.cpp Menu.cpp Penguin.cpp Tiger.cpp Turtle.cpp Zoo.cpp
HEADERS = Animal.hpp Menu.hpp Penguin.hpp Tiger.hpp Turtle.hpp Zoo.hpp

project2: $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o project2

$(OBJS): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $(@:.o=.cpp)

clean:
	rm *.o project2
