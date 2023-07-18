#include "navmesh_type_converter.h"

namespace li
{
	struct WorldPos;

	NavMesh::Point WorldPosToPoint(const WorldPos& pos)
	{
		return NavMesh::Point {(int)pos.x, (int)pos.y};
	}

	WorldPos PointToWorldPos(const NavMesh::Point& point)
	{
		return WorldPos {(float)point.x + 0.5f, (float)point.y + 0.5f };
	}
}
