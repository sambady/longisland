namespace li
{
	namespace helpers
	{
		Vector3 WorldPosToVector3(const WorldPos& aPosition)
		{
			return Vector3{
				aPosition.y, 0.f, aPosition.x 
			};
		}

		Vector3 WorldPosDeltaToVector3(const WorldPosDelta& aPosition)
		{
			return Vector3{
				aPosition.y, 0.f, aPosition.x
			};
		}

		WorldPosDelta Vector3ToWorldPosDelta(const Vector3& vector3)
		{
			return WorldPosDelta{ vector3.z, vector3.x };
		}

		WorldPosDelta RorateDegrees(const WorldPosDelta& aDelta, float degrees)
		{
			return Vector3ToWorldPosDelta(
				Vector3RotateByAxisAngle(
					WorldPosDeltaToVector3(aDelta), Vector3{ 0.f, 1.f, 0.f }, degrees)
				);
		}
	}
}