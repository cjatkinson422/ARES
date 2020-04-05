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
CPPFLAGS = -g --std=c++2a -I$(IDIR) 
CFLAGS = -g -I$(IDIR) 

default: all

$(ODIR)/%.oc: $(SDIR)/%.c
	gcc $(CFLAGS) -c $< $(LDLIBS) -o $@

$(ODIR)/%.o: $(SDIR)/%.cc $(SDIR)/*.hh
	g++ $(CPPFLAGS) -c $< $(LDLIBS) -o $@

$(EXE): $(OBJ)
	g++ $(LDFLAGS) $(CPPFLAGS) $^ $(LIB) $(LDLIBS) -o $@

all: $(EXE)

libs:
	make -C third_party/GNClib/
	cp third_party/GNClib/liblinalg.a libs/
	cp third_party/GNClib/*.hh includes/GNClib/

	cmake -S third_party/glfw/ -B third_party/glfw/build/ -G "Unix Makefiles"
	make -C third_party/glfw/build/
	cp third_party/glfw/build/src/libglfw3.a libs/libglfw3.a

install:
	mkdir includes -p
	mkdir includes/GNClib -p
	mkdir libs/ -p
	git submodule init
	git submodule update
	cmake -S third_party/glfw/ -B third_party/glfw/build/ -G "Unix Makefiles"
	make -C third_party/glfw/build/
	cp third_party/glfw/build/src/libglfw3.a libs/libglfw3.a

clean:
	rm $(OBJ) || true
	rm $(EXE) || true

apocalypse:
	rm $(OBJ) || true
	rm $(EXE) || true
	rm -rf third_party/glfw
	rm -rf third_party/nanovg