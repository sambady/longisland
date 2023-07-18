#pragma once

namespace li
{
	namespace raylib_ex
	{
		// Get a ray trace from mouse position
		Ray GetMouseRayEx(Vector2 mouse, const Camera camera, float sceneWidth, float sceneHeight);

		WorldPos ScreenToWorldPos(Vector2 mouse, const Camera& camera, float sceneWidth, float sceneHeight);
	}
}