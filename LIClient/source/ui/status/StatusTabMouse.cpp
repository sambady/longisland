#include "StatusTabMouse.h"

#include "scene/Scene.h"

namespace li
{
	void StatusTabMouse::Render()
	{
		//ImGui::SetNextItemWidth(100);
		//
		//if(auto mouseScenePosition = Scene().GetMouseSceneCoordinate(); mouseScenePosition)
		//{
		//	ImGui::LabelText("mouse", "%.2f:%.2f", mouseScenePosition->x, mouseScenePosition->y);
		//}
		//else
		//{
		//	ImGui::LabelText("mouse", "not found");
		//}
		//
		//auto mousePosition = GetMousePosition();
		//
		//ImGui::LabelText("real mouse", "%.0f: %.0f", mousePosition.x, mousePosition.y);

		//if (ImGui::InputFloat("fov", &fov, 1, 5, "%.0f"))
		//{
		//	Scene().GetCamera().GetCamera().fovy = fov;
		//}
		//
		//ImGui::SetNextItemWidth(100);
		//if (ImGui::InputFloat3("camera", offset_, "%.0f"))
		//{
		//	Scene().GetCamera().SetCameraOffset(GetCameraOffset(offset_));
		//}
		//
		//if (ImGui::Checkbox("pespective", &cameraType_))
		//{
		//	auto cameraType = CAMERA_ORTHOGRAPHIC;
		//	if (cameraType_) {
		//		cameraType = CAMERA_PERSPECTIVE;
		//	}
		//	else {
		//		cameraType = CAMERA_ORTHOGRAPHIC;
		//	}
		//	Scene().GetCamera().SetCameraType(cameraType);
		//}
	}
}
