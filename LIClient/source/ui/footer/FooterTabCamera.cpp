#include "FooterTabCamera.h"

#include "scene/Scene.h"

namespace li
{
	Vector3 GetCameraOffset(const float offset[3])
	{
		return Vector3{
			offset[0], offset[1], offset[2]
		};
	}


	void FooterTabCamera::Render()
	{	
		ImGui::SetNextItemWidth(100);

		if (ImGui::InputFloat3("camera", offset_, "%.0f"))
		{
			Scene().GetCamera().SetCameraOffset(GetCameraOffset(offset_));
		}
		
		if (ImGui::Checkbox("pespective", &cameraType_))
		{
			auto cameraType = CAMERA_ORTHOGRAPHIC;
			float fovy;
			if (cameraType_) {
				cameraType = CAMERA_PERSPECTIVE;
				fovy = 30.f;
			}
			else {
				cameraType = CAMERA_ORTHOGRAPHIC;
				fovy = 20.f;
			}
			Scene().GetCamera().SetCameraType(cameraType);
			Scene().GetCamera().SetFovy(fovy);
		}
	
	}
}
