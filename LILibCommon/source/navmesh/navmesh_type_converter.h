#pragma once

#include "point.h"
#include "../types/position.h"

namespace li
{
	struct WorldPos;
	NavMesh::Point WorldPosToPoint(const WorldPos & pos);
	WorldPos PointToWorldPos(const NavMesh::Point & point);

}
