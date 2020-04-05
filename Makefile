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

# Third Party libraries
NANO_SRC := $(wildcard ./third_party/nanovg/src/*.c)
NANO_OBJS := $(NANO_SRC:./third_party/nanovg/src/%.c=$(ODIR)/nanovg/%.oc)
IMGUI_OBJS := $(wildcard ./objs/imgui/*.o)

LDFLAGS = $()
LDLIBS = -ldl -lXrandr -lXext -lX11 -lpthread -lm -lGL
CPPFLAGS = -g --std=c++2a -I$(IDIR) 
CFLAGS = -g -I$(IDIR) 

default: executable

$(ODIR)/nanovg/%.oc: ./third_party/nanovg/src/%.c
	gcc $(CFLAGS) -c $< $(LDLIBS) -o $@

$(ODIR)/%.oc: $(SDIR)/%.c
	gcc $(CFLAGS) -c $< $(LDLIBS) -o $@

$(ODIR)/%.o: $(SDIR)/%.cc $(SDIR)/*.hh
	g++ $(CPPFLAGS) -c $< $(LDLIBS) -o $@

$(EXE): $(OBJ) $(IMGUI_OBJS)
	g++ $(LDFLAGS) $(CPPFLAGS) $^ $(LIB) $(LDLIBS) -o $@


executable: $(EXE)


setup:
	git submodule init
	git submodule update
	
	mkdir includes -p
	mkdir includes/GNClib -p
	mkdir libs/ -p
	mkdir objs/ -p
	mkdir objs/nanovg -p

libraries:
	make -C ./third_party/GNClib/
	cp ./third_party/GNClib/liblinalg.a libs/
	cp ./third_party/GNClib/*.hh includes/GNClib/

	mkdir ./includes/nanovg/ -p
	cp ./third_party/nanovg/src/*.h ./includes/nanovg/

	cmake -S third_party/glfw/ -B third_party/glfw/build/ -G "Unix Makefiles"
	make -C third_party/glfw/build/
	cp third_party/glfw/build/src/libglfw3.a libs/libglfw3.a

	ar -r -c -s libnanovg.a $(NANO_OBJS)
	mv libnanovg.a ./libs/libnanogv.a


install: setup $(NANO_OBJS) libraries



clean:
	rm $(OBJ) || true
	rm $(EXE) || true

apocalypse:
	rm $(OBJ) || true
	rm $(EXE) || true
	rm -rf third_party/glfw
	rm -rf third_party/nanovg