main=extractdata	   

SOURCES:=$(wildcard *.cpp) 
OBJECTS=$(SOURCES:.cpp=.o) 
FLAGS=-std=c++11		   


all: $(SOURCES) $(main)	

$(main): $(OBJECTS)
	g++ $(FLAGS) $(OBJECTS) -o $@

.cpp.o:
	g++ $(FLAGS) -c $< -o $@

clean:
	rm *.o $(main)
