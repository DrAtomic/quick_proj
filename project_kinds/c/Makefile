INCLUDE_PATHS = -I.

APP = app_name

SOURCES = main.c

CFLAGS = -Wall -Wextra -g
LIBS =
LINK_OPTS =

all: $(APP)

$(APP): main.c
	gcc $(CFLAGS) $(INCLUDE_PATHS) $(SOURCES) -o $(APP) $(LIBS) $(LINK_OPTS)

clean:
	rm $(APP)
