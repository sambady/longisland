#include "Footer.h"

#include "FooterTabCamera.h"
#include "FooterTabWorld.h"
#include "IFooterTab.h"
#include "ui/Ui.h"

namespace li
{
    Footer::Footer(Ui_& ui)
    {
        RegisterComponent<FooterTabCamera>(&ui)->tabName_ = "camera";
        RegisterComponent<FooterTabWorld>(&ui)->tabName_ = "world";

        currentActiveTab_ = std::type_index(typeid(FooterTabWorld));
    }

    void Footer::Render(const UiBoxConfig& config) 
	{
        ImGui::SetNextWindowPos(config.offset);
		ImGui::SetNextWindowSize(config.size);

        ImGui::Begin("Test footer", nullptr,
			ImGuiWindowFlags_NoDecoration
		);

		for(const auto& [tabType, tab ]: components_) {
            ImGui::SameLine(0.0, 2.0f);
		    if(ImGui::Button(tab->tabName_.c_str(), ImVec2(100.0f, 0.0f)))
		    {
                currentActiveTab_ = tabType;
            }
		}

        auto it = components_.find(*currentActiveTab_);
        if (it == components_.end())
            return;
        
        it->second->Render();

        ImGui::End();
	}

}
