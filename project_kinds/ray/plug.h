#ifndef PLUG_H
#define PLUG_H

#include "raylib.h"

typedef struct {
	Camera2D camera;
	float radius;
} Plug;

typedef void (*plug_init_t) (Plug *plug);
typedef void (*plug_update_t)(Plug *plug);
typedef void (*plug_pre_reload_t)(Plug *plug);
typedef void (*plug_post_reload_t)(Plug *plug);

#endif /* PLUG_H */
