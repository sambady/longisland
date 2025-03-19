#include "StatusTabCamera.h"

#include "scene/Scene.h"


namespace li
{

	void StatusTabCamera::Render()
	{
		Scene().FillMouseInfo();
		//StatusTabHelpers::PrintVector2("mouse_pos", mousePos);
		//StatusTabHelpers::PrintVector3("world_pos", worldPos);
	}


}
