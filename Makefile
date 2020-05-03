#Makefile to test the program

rwildcard=$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

IDIR = ./includes
ODIR = ./objs
SDIR = ./src
LDIR = ./libs

EXE := mainApp

SRC := $(call rwildcard, $(SDIR), *.cc)
OBJ := $(SRC:$(SDIR)/%.cc=$(ODIR)/%.o) 
SRC := $(call rwildcard, $(SDIR), *.c)
OBJ := $(OBJ) $(SRC:$(SDIR)/%.c=$(ODIR)/%.oc)
LIB := $(wildcard $(LDIR)/*.a)

UNAME := $(shell uname)

# Third Party libraries
NANO_SRC := $(wildcard ./third_party/nanovg/src/*.c)
NANO_OBJS := $(NANO_SRC:./third_party/nanovg/src/%.c=$(ODIR)/nanovg/%.oc)
IMGUI_OBJS := $(wildcard ./objs/imgui/*.o)

LDFLAGS = $()
ifeq ($(UNAME), Linux)
LDLIBS = -ldl -lXrandr -lXext -lX11 -lpthread -lm -lGL
endif
ifeq ($(UNAME), Darwin)
LDLIBS = -lbz2 -lz -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo
endif

CPPFLAGS = -g --std=c++2a -I$(IDIR) -I./ -I./src/
CFLAGS = -g -I$(IDIR) 

default: main

$(ODIR)/nanovg/%.oc: ./third_party/nanovg/src/%.c
	gcc $(CFLAGS) -c $< -o $@

$(ODIR)/%.oc: $(SDIR)/%.c
	gcc $(CFLAGS) -c $< -o $@

$(ODIR)/%.o: $(SDIR)/%.cc $(call rwildcard, $(SDIR), *.hh) | $(ODIR)
	g++ $(CPPFLAGS) -c $< -o $@

$(ODIR):
	mkdir -p $@

$(EXE): $(OBJ) $(IMGUI_OBJS)
	g++ $(LDFLAGS) $(CPPFLAGS) $^ $(LIB) $(LDLIBS) -o $@


executable: $(EXE)


setup:
	git submodule init
	git submodule update
	
	mkdir includes || true
	mkdir includes/GNClib || true
	mkdir libs/ || true
	mkdir objs/ || true
	mkdir objs/nanovg || true

libraries:
	make -C ./third_party/GNClib/
	cp ./third_party/GNClib/liblinalg.a libs/
	cp ./third_party/GNClib/*.hh includes/GNClib/

	cmake -S third_party/glfw/ -B third_party/glfw/build/ -G "Unix Makefiles"
	make -C third_party/glfw/build/
	cp third_party/glfw/build/src/libglfw3.a libs/libglfw3.a

proprietary:
	make -C ./third_party/GNClib/
	cp ./third_party/GNClib/liblinalg.a libs/
	cp ./third_party/GNClib/*.hh includes/GNClib/

	echo $(OBJ)


main: proprietary executable

install: setup libraries



clean:
	#rm $(OBJ) || true
	rm $(EXE) || true

apocalypse:
	rm $(OBJ) || true
	rm $(EXE) || true
	rm -rf third_party/glfw
	rm -rf third_party/nanovg