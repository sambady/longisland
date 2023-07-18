#pragma once

namespace li
{
	class LiCamera
	{
	public:
		void Init();
		void UpdateKeyboard();

		void SetCameraPosition(const WorldPos& aTargetPosition);
		void MoveCamera(const WorldPosDelta & aTargetPosition);

		void SetCameraOffset(const Vector3 offset);
		void SetCameraType(int cameraType);

		void SetFovy(float fovy);

		const Camera& GetCamera() const
		{
			return camera_;
		}
	private:
		Vector3 GetCameraDirection() const;

		Camera camera_;

	};

}
