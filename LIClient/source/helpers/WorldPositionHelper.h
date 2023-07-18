#pragma once


namespace li
{
	namespace helpers
	{
		Vector3 WorldPosToVector3(const WorldPos& aPosition);
		Vector3 WorldPosDeltaToVector3(const WorldPosDelta & aPosition);
		WorldPosDelta Vector3ToWorldPosDelta(const Vector3 & vector3);

		WorldPosDelta RorateDegrees(const WorldPosDelta & aDelta, float degrees);

		
	}
}