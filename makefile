# OK - according to GNU standard:
# https://www.gnu.org/software/make/manual/html_node/Implicit-Variables.html

# Reason for compiling .o files
# https://stackoverflow.com/questions/18777326/compiling-multiple-c-files-with-gcc
#  STEPS
#  =====
#   -- C vs CPP:
#           change all appearences of .cpp to .c or vice versa
#	- compile each .c file to .o file (-c: stop after compilation phase, without linking)
#			gcc -c module_n.c -o module_n.o
#	- link .o files
#			gcc -o myprog module_1.o module_2.o module_3.o


CC = g++ # OK
# -g - enable debug symbols
CFLAGS = -Wall -g # OK

TARGET = exec

INC = -I./src/include/
LDFLAGS = -L./src/lib/ # OK
SOURCE_DIR = ./src/files/
BUILD_DIR = ./build

LDLIBS =  # OK
RES = main.cpp \
      lab1.cpp \
#      lab1.h   # No headers!!!

SOURCES = $(addprefix $(SOURCE_DIR),$(RES))
OBJECTS = $(RES:.cpp=.o) # :s/.c/.o/

$(info "SRC:"$(SOURCES))
$(info "OBJ:"$(OBJECTS))


.PHONY: all
all: $(OBJECTS) $(TARGET)

# CHANGE .c TO .cpp; MIGHT BE NECESSARY
# compile object files
%.o: $(SOURCE_DIR)%.cpp
	$(CC) $(INC) $(LDFLAGS) $(CFLAGS) -c -o $@ $< $(LDLIBS)


# link object files
$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

# TODO: compile shared libraries
#.PHONY: build
#	

.PHONY: clean
clean:
	rm -rf *.o

