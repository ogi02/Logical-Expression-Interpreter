CXX = g++
CXXFLAGS = -g -Wall
EXEC = lei
OBJECTS = main.o define_handler.o rpn_converter.o string_utils.o function.o vector.o

ifeq ($(OS), Windows_NT)
	CLEAN = del
	EXEC := $(EXEC).exe
else
	CLEAN = rm
endif

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJECTS)

main.o: main.cpp define_handler.hh string_utils.hh function.hh
	$(CXX) $(CXXFLAGS) -c main.cpp

define_handler.o: define_handler.hh define_handler.cpp rpn_converter.hh function.hh string_utils.hh
	$(CXX) $(CXXFLAGS) -c define_handler.cpp

rpn_converter.o: rpn_converter.hh rpn_converter.cpp vector.hh string_utils.hh
	$(CXX) $(CXXFLAGS) -c rpn_converter.cpp

function.o: function.hh function.cpp vector.hh
	$(CXX) $(CXXFLAGS) -c function.cpp

string_utils.o: string_utils.hh string_utils.cpp vector.hh
	$(CXX) $(CXXFLAGS) -c string_utils.cpp

vector.o: vector.hh vector.cpp
	$(CXX) $(CXXFLAGS) -c vector.cpp

clean:
	$(CLEAN) $(EXEC) $(OBJECTS)