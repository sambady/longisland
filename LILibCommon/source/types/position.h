#pragma once

#include <compare>

namespace li
{
	struct WorldPosDelta;
	struct WorldPos
	{
		friend WorldPosDelta operator-(const WorldPos & left, const WorldPos & right);
		WorldPos operator+(const WorldPosDelta & delta);
		WorldPos operator-(const WorldPosDelta & delta);
		float x = 0.0f;
		float y = 0.0f;
	};

	struct WorldPosDelta
	{
		float GetLenght() const;
		void Normalize();
		std::partial_ordering operator<=>(const WorldPosDelta& other) const;
		WorldPosDelta operator*(float val) const;
		float x = 0.0f;
		float y = 0.0f;
	};

	struct CellPos
	{
		int x = 0;
		int y = 0;
	};
}