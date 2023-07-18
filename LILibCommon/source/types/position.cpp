#include "position.h"

#include <cmath>

namespace li
{
	WorldPosDelta operator-(const WorldPos& left, const WorldPos& right)
	{
		return WorldPosDelta {left.x - right.x, left.y - right.y} ;
	}

	float WorldPosDelta::GetLenght() const
	{
		return std::sqrt(x * x + y * y);
	}

	std::partial_ordering WorldPosDelta::operator<=>(const WorldPosDelta& other) const
	{
		return GetLenght() <=> other.GetLenght();
	}
}
