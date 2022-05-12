
CC = g++
LIB_FILE_NAME = ez_intrinsics.a

EXE_FILE_NAME = main.exe

CFLAGS= -fPIC -O0 -g -Wall -c -fpermissive

INC = -I../Import

SRC_DIR=./src

OBJ_DIR=./obj

OUT_DIR=./lib

BIN_DIR=./bin

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))


# Enumerating of every *.cpp as *.o and using that as dependency
#$(LIB_FILE_NAME): $(patsubst %.cpp,$(OBJ_DIR)/%.o,$(wildcard *.cpp))
#	ar -r -o $(OUT_DIR)/$@ $^

$(EXE_FILE_NAME): $(OBJ_FILES)
	$(CC) $^ -o $(BIN_DIR)/$@

#Compiling every *.cpp to *.o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp dirmake
	$(CC) -c $(INC) $(CFLAGS) -o $@  $<
	
dirmake:
	@mkdir -p $(OUT_DIR)
	@mkdir -p $(OBJ_DIR)
	
clean:
	rm -f $(OBJ_DIR)/*.o $(OUT_DIR)/$(OUT_FILE_NAME) Makefile.bak

rebuild: clean build