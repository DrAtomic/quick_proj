#include <stdio.h>

#include "imgui.h"
#include "implot.h"
#include "plug.h"

extern "C" void plug_init(void)
{

}

static void say_something(int x)
{
	printf("the number said is %d\n", x);
}

static void say_something(void)
{
	printf("hello!\n");
}

extern "C" void plug_update(void)
{
	ImGui::Begin("hello world!");
	if (ImGui::Button("i am a button")) {
		say_something();
	}
	ImGui::End();

	ImGui::Begin("another button");
	if (ImGui::Button("i am another button")) {
		say_something(1);
	}
	ImGui::End();

	ImGui::Begin("Plot");
	int buf[20];

	for (size_t i = 0; i < 20; i++)
		buf[i] = i;

	ImColor m_color = IM_COL32(255,0,255,100);
	ImPlot::BeginPlot("hello plot", ImVec2(-1,0), ImPlotFlags_Equal);
	ImPlot::SetNextLineStyle(m_color);
	ImPlot::PlotScatter("hello plot", buf, buf, 20);
	ImPlot::EndPlot();
	ImGui::End();
}

extern "C" void *plug_pre_reload(void)
{
	return nullptr;
}

extern "C" void plug_post_reload(void *state)
{
	(void)state;
}
