#!smake
#  @@ Makefile for CMSC 435/634 - Project Something: Simple scene
#  @@ Jian Chen (jichen@umbc.edu)
#

MACHINE= $(shell uname -s)


ifeq ($(MACHINE),Darwin)
	OPENGL_INC= -FOpenGL
	OPENGL_LIB= -framework OpenGL -framework GLUT -framework Cocoa
else
	OPENGL_INC= -I/usr/include
	OPENGL_LIB= -L/usr/lib64 
	LLDLIBS = -lglut -lGL -lGLU -lGL -lXmu -lXext -lX11 -lm
endif

CXX=g++
COMPILER_FLAGS= -g

INCLUDE= $(OPENGL_INC)
LIBS= $(OPENGL_LIB) $(LLDLIBS) 

TARGETS = SpaceMountain

#SRCS = MyCoolModel.c 01primitives.c  01primitivesUtil.c trackball.c model.c
SRCS = SpaceMountain.cpp trackball.c

#default : $(TARGETS)
default: Everything

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CXX) -c $(COMPILER_FLAGS) -o $@ $< $(INCLUDE)

#SpaceMountain: SpaceMountain.o
#	$(CXX) $(COMPILER_FLAGS) $(LIBS) SpaceMountain.o -o ColorTest
Everything:
	$(CXX) $(COMPILER_FLAGS) $(LIBS) SpaceMountain.cpp trackball.c -o BrainScan

clean:
	rm -f SpaceMountain.cpp~ SpaceMountain.o ColorTest BrainScan Space
	rm *~
