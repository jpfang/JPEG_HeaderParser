PROJECTDIR=$(PWD)

CROSSCOMPILE=
CC=gcc
STRIP=strip
 
#for include file
INCLUDEDIR=-I ./inc
 
#for Library file
LIBRARYDIR=-L ./

#for math function
LIBRARYS=-lm

#define compile parameters
#:= and = is the same
FALGS:=-O2

#we can add a new parameter
FALGS+=-g
