#
# PROGRAM:  assignment7
# AUTHOR:   Kenneth Harris
# Z-ID:     Z1733721
# DATE DUE: 4/2/2019
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assignment7: assignment7.o
	g++ $(CCFLAGS) -o assignment7.exe assignment7.o

# Rule to compile source code file to object code
assignment7.o: assignment7.cc
	g++ $(CCFLAGS) -c assignment7.cc

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assignment7.exe assignment7.o


