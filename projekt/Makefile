CPP		= g++
CPPFLAGS	= -Wall -g -I $(SRC_DIR)
LDFLAGS		=

RM		= rm

BIN_DIR		= bin
SRC_DIR		= src
PROG		= parser
EXE		= $(BIN_DIR)/$(PROG)
SRC		= $(SRC_DIR)/parser.cpp
OBJ		= $(SRC:%.cpp=%.o)

.PHONY: all clean distclean run

all: $(EXE)

$(EXE): $(OBJ)
	$(CPP) $(LDFLAGS) -o $@ $^

%.o: %.h %.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<

clean:
	$(RM) -f $(SRC_DIR)/*.o

distclean: clean
	$(RM) -f $(EXE) $(EXE).exe

run: $(EXE)
	./$(EXE)
