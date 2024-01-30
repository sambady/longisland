#pragma once

#include "../types/position.h"

namespace li
{
	WorldPos operator+=(const WorldPos& pos, const WorldPosDelta& delta);
	WorldPos operator-=(const WorldPos& pos, const WorldPosDelta& delta);
	
	bool operator==(const WorldPos& left, const WorldPos& right);

	CellPos WorldToCell(const WorldPos & pos);
	WorldPos CellToWorld(const CellPos & pos);
	bool operator==(const CellPos& left, const CellPos& right);
}
