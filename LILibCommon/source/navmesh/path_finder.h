#pragma once

#include <vector>
#include <map>
#include <utility>
	

#include "point.h"
#include "polygon.h"
#include "segment.h"


namespace li
{
	struct WorldPos;
}

namespace NavMesh {

	class PathFinder
	{
	public:
		// Call one time when map changes.
		// Resets the map and creates the graph.
		//
		// |polygons_to_add| - convex polygons on the map.
		// |inflate_by| - how far away paths must go from any polygon
		void AddPolygons(const std::vector<Polygon>& polygons_to_add, int inflate_by);
		
		// Call any time after AddPolygons().
		// It removes previously added external points and adds
		// |points| to the graph.
		void AddExternalPoints(const std::vector<Point>& points_);
		void AddExternalPoints(const std::vector<li::WorldPos>& points_);

		// Get shortest path between two points.
		// points must be first added via AddExternalPoints().
		std::vector<Point> GetPath(const Point& start_coord, const Point& dest_coord);

		std::vector<li::WorldPos> GetPath(const li::WorldPos& start_coord, const li::WorldPos& dest_coord);


		// For debugging. Returns all the edges in the graph.
		std::vector<Segment> GetEdgesForDebug() const;
	private:
		int GetVertex(const Point& c);
		void AddEdge(int be, int en);
		bool CanAddSegment(const Segment& s, const std::vector<std::pair<int, int>>& tangents);

		std::vector<Polygon> polygons_;
		std::vector<Point> ext_points_;

		std::vector<int> free_vertices_;
		std::map<Point, int> vertex_ids_;
		std::vector<Point> v_;

		std::vector<std::vector<bool>> polygon_point_is_inside_;

		std::vector<std::vector<std::pair<int, double>>> edges_;
	};


}
