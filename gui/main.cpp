#include <stdio.h>

#include "imgui.h"
#include "implot.h"
#include "backend_abstraction.cpp"

int main(void)
{
	backend_init();

	bool done = false;

	while (!done) {
		check_for_exit(&done);
		new_frame();
		{
			ImGui::Begin("hello world!");
			int buf[20];

			for (size_t i = 0; i < 20; i++)
				buf[i] = i;

			if (ImPlot::BeginPlot("hello plot", ImVec2(-1,0), ImPlotFlags_Equal)) {
				ImPlot::PlotScatter("hello plot", buf, buf, 20);
				ImPlot::EndPlot();
			}
			ImGui::End();
		}
		render();
	}
	backend_exit();


	return 0;
}
