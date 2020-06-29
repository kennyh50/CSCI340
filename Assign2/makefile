
#
# PROGRAM:  assignment2
# AUTHOR:   Kenneth Harris
# Z-ID:     Z1733721
# DATE DUE: 2/6/2019
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignment2: assignment2.o
	g++ $(CCFLAGS) -o assignment2.exe assignment2.o

# Rule to compile source code file to object code
assignment2.o: assignment2.cc
	g++ $(CCFLAGS) -c assignment2.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment2.exe

