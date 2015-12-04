CXX=g++
CXXFLAGS=-W -Wall -ansi -pedantic -g
LDFLAGS=
EXEC=short_detour
SRC= detour.cpp main.cpp
OBJ= $(SRC:.cpp=.o)

re:	cc all

all:	$(EXEC)

short_detour:	$(OBJ)
		$(CXX) -o $@ $^ $(LDFLAGS)

main.o:	detour.hpp

%.o: %.c
	$(CXX) -o $@ -c $< $(CXXFLAGS)

.PHONY: clean cc

clean:
	rm -rf *.o; rm -rf *~

cc:	clean
	rm -rf $(EXEC)
