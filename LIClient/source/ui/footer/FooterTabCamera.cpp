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

		auto & camera = Scene().GetCamera();

		//if (ImGui::InputFloat3("camera", offset_, "%.0f"))
		//{
		//	Scene().GetCamera().SetCameraOffset(GetCameraOffset(offset_));
		//}

		const int cameraTypeOld = camera.GetCameraType();
		bool isPerspective = cameraTypeOld == CAMERA_PERSPECTIVE;

		if (ImGui::Checkbox("pespective", &isPerspective))
		{
			auto cameraType = cameraTypeOld;
			if (isPerspective) {
				cameraType = CAMERA_PERSPECTIVE;
			}
			else {
				cameraType = CAMERA_ORTHOGRAPHIC;
			}

			if(cameraType != cameraTypeOld) {
				camera.SetCameraType(cameraType);
			}
		}
	
	}
}
