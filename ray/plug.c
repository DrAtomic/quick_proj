#include <float.h>
#include <stdio.h>
#include <string.h>

#include "raylib.h"
#include "raymath.h"
#include "plug.h"


void plug_init(Plug *plug)
{
	memset(&plug->camera, 0, sizeof(Camera2D));
	plug->camera.zoom = 1.0f;
	plug->radius = 100;
}

void plug_pre_reload(Plug *plug)
{
	(void)plug;
}

void plug_post_reload(Plug *plug)
{
	(void)plug;
}

void plug_update(Plug *plug)
{
	Vector2 mouse_position = GetMousePosition();
	Vector2 mouse_world_pos = GetScreenToWorld2D(GetMousePosition(), plug->camera);
	if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
		Vector2 delta = GetMouseDelta();
		delta = Vector2Scale(delta, -1.0f / plug->camera.zoom);
		plug->camera.target = Vector2Add(plug->camera.target, delta);
	}

	float wheel = GetMouseWheelMove();
	if (wheel != 0) {
		plug->camera.offset = mouse_position;
		plug->camera.target = mouse_world_pos;

		float scale_factor = 1.0f + (0.25f * fabsf(wheel));
		if (wheel < 0)
			scale_factor = 1.0f / scale_factor;
		plug->camera.zoom = Clamp(plug->camera.zoom * scale_factor, 0.125f, 64.0f);
	}

	BeginDrawing();
	{
		Vector2 center = {GetScreenWidth() / 2, GetScreenHeight() / 2};

		ClearBackground(GetColor(0x151515FF));

		DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

		BeginMode2D(plug->camera);
		{
			DrawCircleLinesV(center, plug->radius, SKYBLUE);
		}
		EndMode2D();
	}
	EndDrawing();
}
