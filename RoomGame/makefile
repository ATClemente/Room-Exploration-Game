

#Makefile for Final Project - 6/9/17
#Assembled with the help of the following references: 
#http://mrbook.org/blog/tutorials/make/ (Course material found in Canvas) and "makefile1" TA example provided in Canvas
#Consulted the make documentation referenced in this link as well: https://www.gnu.org/software/make/manual/make.html

CC = g++
CFLAGS =-c -std=c++0x
LDFLAGS=-g
SOURCES =$(wildcard *.cpp)
HEADERS =$(wildcard *.hpp)
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE =ClementeFinalProject

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm *o ClementeFinalProject
	
zip:
	zip -D Clemente_Anthony_Final_Project.zip ${SOURCES} ${HEADERS} makefile *.pdf