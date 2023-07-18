#include "Camera.h"

#include "helpers/WorldPositionHelper.h"

namespace li
{
	void LiCamera::Init()
	{
		camera_ = Camera{
			{ -20.0f, 20.0f, -20.0f },
			{ 0.0f, 0.0f, 0.0f },
			{ 0.0f, 1.0f, 0.0f },
			45.0f, 0 };

		camera_.projection = CAMERA_ORTHOGRAPHIC;             // Camera mode type
	}

	void LiCamera::SetCameraPosition(const WorldPos& aTargetPosition)
	{
		//camera_.position = Vector3Add(
		//	 helpers::WorldPosToVector3(aTargetPosition),
		//	 GetUi().GetFooterMenu().GetComponent<FooterTabCamera>()->GetCameraOffset());
		//camera_.target = helpers::WorldPosToVector3(aTargetPosition);
	}

	void LiCamera::MoveCamera(const WorldPosDelta& aTargetPosition)
	{
		auto moveVector = helpers::WorldPosDeltaToVector3(aTargetPosition);
		
		camera_.position = Vector3Add(
			camera_.position, moveVector
			);

		camera_.target = Vector3Add(
			camera_.target,
			moveVector);
	}

	void LiCamera::SetCameraOffset(const Vector3 offset)
	{
		camera_.position = Vector3Add(camera_.target, offset);
	}

	void LiCamera::SetCameraType(int cameraType)
	{
		camera_.projection = cameraType;
	}

	void LiCamera::SetFovy(float fovy)
	{
		camera_.fovy = fovy;
	}

	Vector3 LiCamera::GetCameraDirection() const
	{
		auto direction = Vector3Subtract(camera_.target, camera_.position);

		return Vector3Multiply(Vector3Normalize(direction), Vector3{0.1f, 0.1f, 0.1f});
	}

	void LiCamera::UpdateKeyboard()
	{
		if (IsKeyDown('W'))	{
			MoveCamera(helpers::Vector3ToWorldPosDelta(GetCameraDirection()));
		}
		if (IsKeyDown('S'))	{
			MoveCamera(helpers::RorateDegrees(helpers::Vector3ToWorldPosDelta(GetCameraDirection()), PI));
		}
		if (IsKeyDown('A'))	{
			MoveCamera(helpers::RorateDegrees(helpers::Vector3ToWorldPosDelta(GetCameraDirection()), PI * 0.5f));
		}
		if (IsKeyDown('D'))	{
			MoveCamera(helpers::RorateDegrees(helpers::Vector3ToWorldPosDelta(GetCameraDirection()), PI * 1.5f));
		}
	}

} 
