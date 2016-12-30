ICXX = g++
CXXFLAGS = -c -g -std=c++11 -Wall -W -Werror -pedantic
LDFLAGS =

kElement : kthElement.o
	$(CXX) $(LDFLAGS) -o kElement kthElement.o

kthElement.o : kthElement.cpp
	$(CXX) $(CXXFLAGS) kthElement.cpp

clean :
	rm -f kElement *.o
