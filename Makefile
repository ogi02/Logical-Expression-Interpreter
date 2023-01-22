CXX = g++
CXXFLAGS = -g -Wall
EXEC = lei
LDFLAGS = -lbgi -lgdi32 -lcomdlg32 -luuid -loleaut32 -lole32

OPERATION_HANDLERS = define_handler.o solve_handler.o truth_table_handler.o find_handler.o
UTILS = rpn_converter.o string_utils.o file_utils.o graphics_utils.o
DATA_TYPES = function.o vector.o queue.o truth_table.o implicant.o
NODES = node.o operand_node.o operator_node.o
ENUMERATIONS = command.o

OBJECTS = main.o $(OPERATION_HANDLERS) $(UTILS) $(DATA_TYPES) $(NODES) $(ENUMERATIONS)

ifeq ($(OS), Windows_NT)
	CLEAN = del
	EXEC := $(EXEC).exe
else
	CLEAN = rm
endif

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJECTS) $(LDFLAGS)

#---------------------------------------MAIN---------------------------------------------

OPERATION_HANDLER_HEADERS = operation_handlers/define_handler.hh operation_handlers/solve_handler.hh operation_handlers/truth_table_handler.hh operation_handlers/find_handler.hh
MAIN_DEPS = $(OPERATION_HANDLER_HEADERS) utils/file_utils.hh utils/string_utils.hh data_types/function.hh data_types/queue.hh enumerations/command.hh
main.o: main.cpp $(MAIN_DEPS)
	$(CXX) $(CXXFLAGS) -c main.cpp

#--------------------------------OPERATION HANDLERS--------------------------------------

DEFINE_HANDLER_DEPS = utils/rpn_converter.hh utils/string_utils.hh data_types/queue.hh data_types/function.hh
define_handler.o: operation_handlers/define_handler.hh operation_handlers/define_handler.cpp $(DEFINE_HANDLER_DEPS)
	$(CXX) $(CXXFLAGS) -c operation_handlers/define_handler.cpp

SOLVE_HANDLER_DEPS = data_types/queue.hh data_types/function.hh
solve_handler.o: operation_handlers/solve_handler.hh operation_handlers/solve_handler.cpp $(SOLVE_HANDLER_DEPS)
	$(CXX) $(CXXFLAGS) -c operation_handlers/solve_handler.cpp

TRUTH_TABLE_HANDLER_DEPS = utils/string_utils.hh data_types/vector.hh data_types/queue.hh data_types/function.hh
truth_table_handler.o: operation_handlers/truth_table_handler.hh operation_handlers/truth_table_handler.cpp $(TRUTH_TABLE_HANDLER_DEPS)
	$(CXX) $(CXXFLAGS) -c operation_handlers/truth_table_handler.cpp

FIND_HANDLER_DEPS = utils/string_utils.hh data_types/truth_table.hh data_types/implicant.hh data_types/queue.hh
find_handler.o: operation_handlers/find_handler.hh operation_handlers/find_handler.cpp $(FIND_HANDLER_DEPS)
	$(CXX) $(CXXFLAGS) -c operation_handlers/find_handler.cpp

#------------------------------------UTILITIES-------------------------------------------

RPN_CONVERTER_DEPS = data_types/vector.hh utils/string_utils.hh
rpn_converter.o: utils/rpn_converter.hh utils/rpn_converter.cpp $(RPN_CONVERTER_DEPS)
	$(CXX) $(CXXFLAGS) -c utils/rpn_converter.cpp

STRING_UTILS_DEPS = data_types/vector.hh
string_utils.o: utils/string_utils.hh utils/string_utils.cpp $(STRING_UTILS_DEPS)
	$(CXX) $(CXXFLAGS) -c utils/string_utils.cpp

FILE_UTILS_DEPS = data_types/vector.hh
file_utils.o: utils/file_utils.hh utils/file_utils.cpp $(FILE_UTILS_DEPS)
	$(CXX) $(CXXFLAGS) -c utils/file_utils.cpp

GRAPHICS_UTILS_DEPS = nodes/node.hh utils/string_utils.hh
graphics_utils.o: utils/graphics_utils.hh utils/graphics_utils.cpp $(GRAPHICS_UTILS_DEPS)
	$(CXX) $(CXXFLAGS) -c utils/graphics_utils.cpp

#------------------------------------DATA TYPES------------------------------------------

FUNCTION_DEPS = data_types/vector.hh nodes/operand_node.hh nodes/operator_node.hh utils/file_utils.hh utils/string_utils.hh utils/graphics_utils.hh utils/rpn_converter.hh
function.o: data_types/function.hh data_types/function.cpp $(FUNCTION_DEPS)
	$(CXX) $(CXXFLAGS) -c data_types/function.cpp

VECTOR_DEPS = nodes/node.hh
vector.o: data_types/vector.hh data_types/vector.cpp $(VECTOR_DEPS)
	$(CXX) $(CXXFLAGS) -c data_types/vector.cpp

QUEUE_DEPS = data_types/function.hh data_types/implicant.hh
queue.o: data_types/queue.hh data_types/queue.cpp
	$(CXX) $(CXXFLAGS) -c data_types/queue.cpp

TRUTH_TABLE_DEPS = data_types/vector.hh
truth_table.o: data_types/truth_table.hh data_types/truth_table.cpp $(TRUTH_TABLE_DEPS)
	$(CXX) $(CXXFLAGS) -c data_types/truth_table.cpp

IMPLICANT_DEPS = data_types/vector.hh
implicant.o: data_types/implicant.hh data_types/implicant.cpp $(IMPLICANT_DEPS)
	$(CXX) $(CXXFLAGS) -c data_types/implicant.cpp

#---------------------------------------NODES--------------------------------------------

node.o: nodes/node.hh nodes/node.cpp
	$(CXX) $(CXXFLAGS) -c nodes/node.cpp

OPERAND_NODE_DEPS = nodes/node.hh
operand_node.o: nodes/operand_node.hh nodes/operand_node.cpp $(OPERAND_NODE_DEPS)
	$(CXX) $(CXXFLAGS) -c nodes/operand_node.cpp

OPERATOR_NODE_DEPS = nodes/node.hh
operator_node.o: nodes/operator_node.hh nodes/operator_node.cpp $(OPERATOR_NODE_DEPS)
	$(CXX) $(CXXFLAGS) -c nodes/operator_node.cpp

#------------------------------------ENUMERATIONS----------------------------------------

COMMAND_DEPS = utils/string_utils.hh
command.o: enumerations/command.hh enumerations/command.cpp $(COMMAND_DEPS)
	$(CXX) $(CXXFLAGS) -c enumerations/command.cpp

#---------------------------------------CLEAN--------------------------------------------

clean:
	$(CLEAN) $(EXEC) $(OBJECTS) functions.csv