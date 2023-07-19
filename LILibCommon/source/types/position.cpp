#include "position.h"

#include <cmath>

namespace li
{
	WorldPosDelta operator-(const WorldPos& left, const WorldPos& right)
	{
		return WorldPosDelta {left.x - right.x, left.y - right.y} ;
	}

	WorldPos WorldPos::operator+(const WorldPosDelta & delta)
	{
		return WorldPos {x + delta.x, y + delta.y};
	}

	WorldPos WorldPos::operator-(const WorldPosDelta & delta)
	{
		return WorldPos {x - delta.x, y - delta.y};
	}

	float WorldPosDelta::GetLenght() const
	{
		return std::sqrt(x * x + y * y);
	}

	void WorldPosDelta::Normalize() 
	{
    	float length = GetLenght();

		if (length > 0)
		{
			float ilength = 1.0f/length;
			x = x*ilength;
			y = y*ilength;
		}
	}

	std::partial_ordering WorldPosDelta::operator<=>(const WorldPosDelta& other) const
	{
		return GetLenght() <=> other.GetLenght();
	}

	WorldPosDelta WorldPosDelta::operator*(float val) const
	{
		return WorldPosDelta {x * val, y * val};
	}
}
