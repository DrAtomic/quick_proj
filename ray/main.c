#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

#include "plug.h"

const char *lib_plug_file_name = "libplug.so";
void *libplug;

plug_init_t plug_init;
plug_update_t plug_update;
plug_pre_reload_t plug_pre_reload;
plug_post_reload_t plug_post_reload;

Plug plug;

void libplug_reload(void)
{
	if (libplug)
		dlclose(libplug);
	libplug =  dlopen(lib_plug_file_name, RTLD_NOW);
	if (libplug == NULL) {
		fprintf(stderr, "failed to load libplug\n");
		exit(1);
	}
	plug_init = dlsym(libplug, "plug_init");
	if (plug_init == NULL) {
		fprintf(stderr, "failed to load plug_init\n");
		exit(1);
	}
	plug_update = dlsym(libplug, "plug_update");
	if (plug_update == NULL) {
		fprintf(stderr, "failed to load plug_update\n");
		exit(1);
	}
	plug_pre_reload = dlsym(libplug, "plug_pre_reload");
	if (plug_pre_reload == NULL) {
		fprintf(stderr, "failed to load plug_pre_reload\n");
		exit(1);
	}
	plug_post_reload = dlsym(libplug, "plug_post_reload");
	if (plug_post_reload == NULL) {
		fprintf(stderr, "failed to load plug_post_reload\n");
		exit(1);
	}
	printf("reloading!\n");
}

int main(void)
{
	libplug_reload();
	size_t factor = 80;

	SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_WINDOW_ALWAYS_RUN);
	InitWindow(factor*16, factor*9, "balancer");
	SetTargetFPS(60);

	plug_init(&plug);
	while (!WindowShouldClose()) {
		if (IsKeyPressed(KEY_R)) {
			plug_pre_reload(&plug);
			libplug_reload();
			plug_post_reload(&plug);
		}
		plug_update(&plug);
	}

	CloseWindow();

	return 0;
}
