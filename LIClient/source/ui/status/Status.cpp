#include "Status.h"

#include "StatusTabCamera.h"
#include "StatusTabLogger.h"
#include "StatusTabMouse.h"
#include "ui/Ui.h"

namespace li
{
    Status::Status(Ui_& ui)
    {
        RegisterComponent<StatusTabMouse>(&ui);
        RegisterComponent<StatusTabLogger>(&ui);
        RegisterComponent<StatusTabCamera>(&ui);
    }

	void Status::Render(const UiBoxConfig& uiBoxConfig)
	{
        ImGui::SetNextWindowPos(uiBoxConfig.offset);
		ImGui::SetNextWindowSize(uiBoxConfig.size);

        ImGui::Begin("Test status", nullptr,
			ImGuiWindowFlags_NoDecoration
		);

		for(const auto& component: components_ | std::views::values) {
            component->Render();
		}

        ImGui::End();
	}

}
