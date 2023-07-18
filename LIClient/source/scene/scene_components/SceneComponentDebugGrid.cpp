#include "SceneComponentDebugGrid.h"

#include <format>

#include "scene/Scene.h"
#include "ui/Ui.h"
#include "ui/status/StatusTabCamera.h"
#include "ui/status/StatusTabLogger.h"

namespace li
{
	void SceneComponentDebugGrid::Render()
	{
		if (!enabled_)
			return;
		constexpr int gridSize = 40;

		const auto centerPosition = Scene().GetCamera().GetCamera().target;
		
		for (int x = (int)centerPosition.x - gridSize; x <= (int)centerPosition.x + gridSize; x += 1)
		{
			DrawLine3D(
				Vector3{ (float)x, 0, (float)(int)centerPosition.z - gridSize },
				Vector3{ (float)x, 0, (float)(int)centerPosition.z + gridSize },
				(x % 5) ? BLACK : RED
			);
		}

		for (int y = (int)centerPosition.z - gridSize; y <= (int)centerPosition.z + gridSize; y += 1)
		{
			DrawLine3D(
				Vector3{ (float)(int)centerPosition.x - gridSize, 0, (float)y },
				Vector3{ (float)(int)centerPosition.x + gridSize, 0, (float)y },
				(y % 5) ? BLACK : RED
			);
		}
	}
}
