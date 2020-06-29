#
# PROGRAM:  assignment1
# AUTHOR:   Kenneth Harris
# Z-ID:     Z1733721
# DATE DUE: 1/25/2019
#
    
# Compiler variables
CCFLAGS = -Wall -std=c++11
    
# Rule to link object code files to create executable file
assignment1: assignment1.o
	g++ $(CCFLAGS) -o assignment1.exe assignment1.o
    
# Rule to compile source code file to object code
assignment1.o: assignment1.cc
	g++ $(CCFLAGS) -c assignment1.cc
    
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment1.exe
