RAY_DIR = ./deps/raylib-5.0/src

INCLUDE_PATHS = -I.
INCLUDE_PATHS += -I$(RAY_DIR)

APP = app_name

SOURCES = main.c

CXXFLAGS = -Wall -Wextra -g
LIBS = -L./$(RAY_DIR)
LINK_OPTS = -l:libraylib.a -lm

all: $(APP)
$(RAY_DIR)/libraylib.a:
	make -C $(RAY_DIR)
$(APP): $(RAY_DIR)/libraylib.a main.c
	gcc $(CXXFLAGS) $(INCLUDE_PATHS) $(SOURCES) -o $(APP) $(LIBS) $(LINK_OPTS) 
clean:
	make -C $(RAY_DIR) clean
	rm $(APP)
