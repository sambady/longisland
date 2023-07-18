#include "StatusTabCamera.h"

#include "scene/Scene.h"


namespace li
{
	void PrintVector2(const char * name, const Vector2 & vector2)
	{
		ImGui::Text(name);
		ImGui::Text("%.1f", vector2.x);
		ImGui::SameLine();
		ImGui::Text("%.1f", vector2.y);
	}

	void PrintVector3(const char* name, const WorldPos& worldPos)
	{
		ImGui::Text(name);
		ImGui::Text("%.2f", worldPos.x);
		ImGui::SameLine();
		ImGui::Text("%.2f", worldPos.y);
	}

	void StatusTabCamera::Render()
	{
		Scene().FillMouseInfo();
		PrintVector2("mouse_pos", mousePos);
		PrintVector3("world_pos", worldPos);
	}


}
