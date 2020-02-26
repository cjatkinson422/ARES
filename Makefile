#Makefile to test the program

IDIR = ./includes
ODIR = ./objs
SDIR = ./src
LDIR = ./libs

EXE := mainApp

SRC := $(wildcard $(SDIR)/*.cpp)
OBJ := $(SRC:$(SDIR)/%.cpp=$(ODIR)/%.o) 
SRC := $(wildcard $(SDIR)/*.c) 
OBJ := $(OBJ) $(SRC:$(SDIR)/%.c=$(ODIR)/%.oc)
LIB := $(wildcard $(LDIR)/*.a)
#HED := $(wildcard $(SDIR)/*.hpp)

LDFLAGS = $()
LDLIBS = -ldl -lXrandr -lXext -lX11 -lpthread -lm
CPPFLAGS = -g --std=c++17 -I$(IDIR) 
CFLAGS = -g -I$(IDIR) 

default: all

$(ODIR)/%.oc: $(SDIR)/%.c
	gcc $(CFLAGS) -c $< $(LDLIBS) -o $@

$(ODIR)/%.o: $(SDIR)/%.cpp $(SDIR)/*.hpp
	g++ $(CPPFLAGS) -c $< $(LDLIBS) -o $@

$(EXE): $(OBJ) 
	cp includes/GNClib/liblinalg.a libs/
	g++ $(LDFLAGS) $(CPPFLAGS) $^ $(LIB) $(LDLIBS) -o $@

all: $(EXE)

clean:
	rm $(OBJ)
	rm $(EXE)
