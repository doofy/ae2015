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

GENERATOR       = generator
GENERATOR_EXE   = $(BIN_DIR)/$(GENERATOR)
GENERATOR_SRC   = $(SRC_DIR)/generator/generator.cpp
GENERATOR_OBJ   = $(GENERATOR_SRC:%.cpp=%.o)

TESTDATA_IN     = testdata
TESTDATA_OUT    = testdata.out

.PHONY: all clean distclean
.PHONY: run run-testdata  eval-testdata eval-testdata.out clean-testdata

all: $(EXE)

$(PROG): $(EXE)

$(EXE): $(OBJ)
	$(CPP) $(LDFLAGS) -o $@ $^

%.o: %.h %.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<

clean:
	$(RM) -f $(OBJ)
	$(RM) -f $(GENERATOR_OBJ)

distclean: clean clean-testdata
	$(RM) -f $(EXE) $(EXE).exe
	$(RM) -f $(GENERATOR_EXE) $(GENERATOR_EXE).exe

run: $(EXE)
	./$(EXE)

run-testdata: $(EXE) $(TESTDATA_IN)
	$(RM) -f $(TESTDATA_OUT)
	$(EXE) -in $(TESTDATA_IN) -out $(TESTDATA_OUT)

eval-testdata: $(EXE) $(TESTDATA_IN)
	$(EXE) -eval $(TESTDATA_IN)

eval-testdata.out: $(EXE) $(TESTDATA_OUT)
	$(EXE) -eval $(TESTDATA_OUT)

$(GENERATOR): $(GENERATOR_EXE)

$(GENERATOR_EXE): $(GENERATOR_OBJ)
	$(CPP) $(LDFLAGS) -o $@ $^

$(TESTDATA_IN): $(GENERATOR_EXE)
	$(RM) -f $(TESTDATA_IN)
	$(RM) -f $(TESTDATA_OUT)
	./$(GENERATOR_EXE) 10 1000 3000 > $(TESTDATA_IN)

clean-testdata:
	$(RM) -f $(TESTDATA_IN)
	$(RM) -f $(TESTDATA_OUT)