#include "algorithm_position.h"

namespace li
{
	WorldPos operator+=(const li::WorldPos& pos, const WorldPosDelta& delta)
	{
		return WorldPos{ pos.x + delta.x, pos.y + delta.y };
	}

	WorldPos operator-=(const WorldPos& pos, const li::WorldPosDelta& delta)
	{
		return WorldPos{ pos.x + delta.x, pos.y + delta.y };
	}
	
	bool operator==(const WorldPos& left, const WorldPos& right)
	{
		return left.x == right.x && left.y == right.y;
	}

	CellPos WorldToCell(const WorldPos& pos)
	{
		return CellPos{ (int)pos.x, (int)pos.y };
	}

	bool operator==(const CellPos& left, const CellPos& right)
	{
		return left.x == right.x && left.y == right.y;
	}
}