# ===================================================================
#           Author: Antoine CORNILLEAU et Nicolas SALAÜN
#            Email: antoine.cornilleau@etud.univ-angers.fr
#					nicolas.salaun@etud.univ-angers.fr
#      Institution: Université d'Angers
# ===================================================================


CXX = g++
objects = hello.o func.o

all: hello

hello: $(objects)
    $(CXX) -o $(objects)

clean:
	rm -rf bin/*.exe obj/*.o