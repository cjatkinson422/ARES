#Makefile to test the program

IDIR = ./includes
ODIR = ./objs
SDIR = ./src
LDIR = ./libs

EXE := mainApp

SRC := $(wildcard $(SDIR)/*.cc)
OBJ := $(SRC:$(SDIR)/%.cc=$(ODIR)/%.o) 
SRC := $(wildcard $(SDIR)/*.c) 
OBJ := $(OBJ) $(SRC:$(SDIR)/%.c=$(ODIR)/%.oc)
LIB := $(wildcard $(LDIR)/*.a)
#HED := $(wildcard $(SDIR)/*.hh)

LDFLAGS = $()
LDLIBS = -ldl -lXrandr -lXext -lX11 -lpthread -lm
CPPFLAGS = -g --std=c++17 -I$(IDIR) 
CFLAGS = -g -I$(IDIR) 

default: all

$(ODIR)/%.oc: $(SDIR)/%.c
	gcc $(CFLAGS) -c $< $(LDLIBS) -o $@

$(ODIR)/%.o: $(SDIR)/%.cc $(SDIR)/*.hh
	g++ $(CPPFLAGS) -c $< $(LDLIBS) -o $@

$(EXE): $(OBJ) 
	make -C includes/GNClib/
	cp includes/GNClib/liblinalg.a libs/
	g++ $(LDFLAGS) $(CPPFLAGS) $^ $(LIB) $(LDLIBS) -o $@

all: $(EXE)

install:
	git clone https://github.com/glfw/glfw.git third_party/glfw/
	mkdir third_party/glfw/build/
	cmake -S third_party/glfw/ -B third_party/glfw/build/ -G "Unix Makefiles"
	make -C third_party/glfw/build/
	cp third_party/glfw/build/src/libglfw3.a libs/libglfw3.a

clean:
	rm $(OBJ)
	rm $(EXE)

apocalypse:
	rm -rf third_party/glfw