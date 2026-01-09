IMGUI_DIR = ./deps/imgui

INCLUDE_PATHS = -I.
INCLUDE_PATHS += -I/usr/include/SDL3
INCLUDE_PATHS += -I$(IMGUI_DIR)
INCLUDE_PATHS += -I$(IMGUI_DIR)/backends

APP = app_name

PLUG = lib_plug.so

CXXFLAGS = -Wall -Wextra -g
LIBS = -lGL -ldl `pkg-config sdl3 --libs`
LINK_OPTS = -Wl,-rpath=/usr/local/lib/

all: $(APP) $(PLUG)

imgui.o: imgui.cpp
	g++ -c $(CXXFLAGS) $(INCLUDE_PATHS) imgui.cpp -o imgui.o

$(APP): main.cpp imgui.o
	g++ $(CXXFLAGS) -rdynamic $(INCLUDE_PATHS) main.cpp -o $(APP) imgui.o $(LIBS) $(LINK_OPTS)

plug.o: plug.cpp plug.h
	g++ -c $(CXXFLAGS) -fPIC $(INCLUDE_PATHS) plug.cpp -o plug.o

$(PLUG): plug.o
	g++ -shared -o $(PLUG) plug.o -ldl

clean:
	rm -rf $(APP) $(PLUG) *.o *.so compile_commands.json .cache imgui.ini
