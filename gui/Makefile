IMGUI_DIR = ./deps/imgui

INCLUDE_PATHS = -I.
INCLUDE_PATHS += -I/usr/include/SDL2
INCLUDE_PATHS += -I$(IMGUI_DIR)
INCLUDE_PATHS += -I$(IMGUI_DIR)/backends

APP = app_name

SOURCES = main.cpp

CXXFLAGS = -Wall -Wextra -g
LIBS = -lGL -ldl `sdl2-config --libs`
LINK_OPTS = -Wl,-rpath=/usr/local/lib/

all: $(APP)
imgui.o: imgui.cpp
	g++ -c $(CXXFLAGS) $(INCLUDE_PATHS) imgui.cpp -o imgui.o
$(APP): main.cpp backend_abstraction.cpp imgui.o
	g++ $(CXXFLAGS) $(INCLUDE_PATHS) $(SOURCES) -o $(APP) $(LIBS) $(LINK_OPTS) imgui.o
clean:
	rm $(APP) *.o
