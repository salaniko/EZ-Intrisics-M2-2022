# ===================================================================
#           Author: Antoine CORNILLEAU et Nicolas SALAÜN
#            Email: antoine.cornilleau@etud.univ-angers.fr
#					nicolas.salaun@etud.univ-angers.fr
#      Institution: Université d'Angers
#			Projet: EZ - Intrinsics
#			  Date: Mai 2022
# ===================================================================

CXX = g++
OUT_FILE_NAME = ez_intrinsics.a
CFLAGS= -fPIC -O0 -g -Wall -c -fpermissive
SRC_DIR=src/
OBJ_DIR=obj/
OUT_DIR=bin/

# Enumerating of every *.cpp as *.o and using that as dependency
$(OUT_FILE_NAME): $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(wildcard *.cpp))
	ar -r -o $(OUT_DIR)/$@ $^

#Compiling every *.cpp to *.o
$(OBJ_DIR)/%.o: %.cpp dirmake
	@echo "$@"
	$(CC) -c $(CFLAGS) -o $@  $<

dirmake:
	@mkdir -p $(OUT_DIR)
	@mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o $(OUT_DIR)/$(OUT_FILE_NAME) makefile.bak
