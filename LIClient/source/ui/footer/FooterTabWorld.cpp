#include "FooterTabWorld.h"

#include "scene/Scene.h"
#include "scene/scene_components/SceneComponentDebugGrid.h"
#include "scene/scene_components/SceneComponentLocalHero.h"

namespace li
{
	void FooterTabWorld::Render()
	{
        ImGui::SetNextItemWidth(100);
        ImGui::InputFloat2("xy", xy, "%.1f");

        
        if (ImGui::Button("CreateActor"))
        {
            Scene().AddActor(WorldPos{ xy[0], xy[1] });
        }
        ImGui::SameLine();
        if (ImGui::Button("Cleanup", ImVec2(40, 20)))
        {
            Scene().RemoveAllActors();
        }

        if(ImGui::Checkbox("Show grid", &showGrid))
        {
            Scene().GetOrCreateComponent<SceneComponentDebugGrid>()->SetShowGrid(showGrid);
        }

        if(ImGui::InputFloat2("local hero", xyLocalHero, "%.1f"))
        {
            //Scene().GetOrCreateComponent<SceneComponentLocalHero>()->SetPosition(WorldPos(xyLocalHero[0], xyLocalHero[1]));
        }

        if (Scene().GetOrCreateComponent<SceneComponentLocalHero>()->GetActor() == nullptr) {
            if (ImGui::Button("Create local hero")) {
                Scene().GetOrCreateComponent<SceneComponentLocalHero>()->Init(WorldPos{ xyLocalHero[0], xyLocalHero[1] });
            }
        }
	}
}
