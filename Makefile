###########################################################################
##                      Makefile for (StringBST)                         ##
###########################################################################

CXX      = clang++
CXXFLAGS = -g3 -Wall -Wextra -std=c++11
LDFLAGS  = -g3

alphabetizer: StringBST.o Alphabetizer.o main.o
	${CXX} ${LDFLAGS} -o alphabetizer StringBST.o Alphabetizer.o main.o

StringBST.o:  	StringBST.h 	StringBST.cpp 
Alphabetizer.o:	Alphabetizer.h	Alphabetizer.cpp
main.o:     	main.cpp	StringBST.h	Alphabetizer.h

clean:
	rm -rf alphabetizer *.o *.dSYM