#include "RaylibEx.h"

namespace li
{
	namespace raylib_ex
	{
		Ray GetMouseRayEx(Vector2 mouse, const Camera camera, float sceneWidth, float sceneHeight)
		{
			Ray ray = { 0, 0 , 0, 0, 0, 0};

			// Calculate normalized device coordinates
			// NOTE: y value is negative
			float x = (2.0f * mouse.x) / (float)sceneWidth - 1.0f;
			float y = 1.0f - (2.0f * mouse.y) / (float)sceneHeight;
			float z = 1.0f;

			// Store values in a vector
			Vector3 deviceCoords = { x, y, z };

			// Calculate view matrix from camera look at
			Matrix matView = MatrixLookAt(camera.position, camera.target, camera.up);

			Matrix matProj = MatrixIdentity();

			if (camera.projection == CAMERA_PERSPECTIVE)
			{
				// Calculate projection matrix from perspective
				matProj = MatrixPerspective(camera.fovy * DEG2RAD, ((double)sceneWidth / (double)sceneHeight), 0.001, 1000.0);
			}
			else if (camera.projection == CAMERA_ORTHOGRAPHIC)
			{
				float aspect = (float)sceneWidth / (float)sceneHeight;
				double top = camera.fovy / 2.0;
				double right = top * aspect;

				// Calculate projection matrix from orthographic
				matProj = MatrixOrtho(-right, right, -top, top, 0.01, 1000.0);
			}

			// Unproject far/near points
			Vector3 nearPoint = Vector3Unproject(Vector3{ deviceCoords.x, deviceCoords.y, 0.0f }, matProj, matView);
			Vector3 farPoint = Vector3Unproject(Vector3{ deviceCoords.x, deviceCoords.y, 1.0f }, matProj, matView);

			// Unproject the mouse cursor in the near plane.
			// We need this as the source position because orthographic projects, compared to perspective doesn't have a
			// convergence point, meaning that the "eye" of the camera is more like a plane than a point.
			Vector3 cameraPlanePointerPos = Vector3Unproject(Vector3{ deviceCoords.x, deviceCoords.y, -1.0f }, matProj, matView);

			// Calculate normalized direction vector
			Vector3 direction = Vector3Normalize(Vector3Subtract(farPoint, nearPoint));

			if (camera.projection == CAMERA_PERSPECTIVE) ray.position = camera.position;
			else if (camera.projection == CAMERA_ORTHOGRAPHIC) ray.position = cameraPlanePointerPos;

			// Apply calculated vectors to ray
			ray.direction = direction;

			return ray;
		}

		WorldPos ScreenToWorldPos(Vector2 mouse, const Camera& camera, float sceneWidth, float sceneHeight)
		{
			auto ray = GetMouseRayEx(mouse, camera, sceneWidth, sceneHeight);

			auto p1 = ray.position;
			auto p2 = ray.direction;

			auto x = p1.x - (p1.y * p2.x) / p2.y;
			auto y = p1.z - (p1.y * p2.z) / p2.y;

			return WorldPos{ y, x };
		}
	}
}