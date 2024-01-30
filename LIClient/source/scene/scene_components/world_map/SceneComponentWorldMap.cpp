#include "Precompiled.h"
#include "SceneComponentWorldMap.h"

#include <random>

#include "scene/Scene.h"
#include "algorithm/algorithm_position.h"

namespace li
{
	void SceneComponentWorldMap::Init()
	{
		std::vector<std::pair<int, int>> positions;
		for(int x = 10 ; x < 100; x++) {
			for(int y = 10 ; y < 100 ; y++) {
				positions.push_back({x,y});
			}
		}
		std::vector<std::pair<int, int>> dest;
		std::ranges::sample(positions, std::back_inserter(dest), 100,
		                    std::mt19937 {std::random_device{}()});

		for(auto & it : dest) {
			trees_.push_back(WorldToCell(WorldPos(it.first, it.second)));
		}
	}

	void SceneComponentWorldMap::Render()
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
		{
			if (auto worldPos = Scene().GetMouseWorldPosition(); worldPos)
			{
				if (auto it = std::find(trees_.begin(), trees_.end(), WorldToCell(*worldPos)); it == trees_.end())
				{
					trees_.push_back(WorldToCell(*worldPos));
				}
			}
		}

		for(auto & tree : trees_)
		{
			Vector3 playerPosition = { (float)tree.y + 0.5f,  1.0f , (float)tree.x + 0.5f };
			Vector3 playerSize = { 1.0f, 2.0f, 1.0f };


			DrawCubeV(playerPosition, playerSize, GRAY);
			DrawCubeWiresV(playerPosition, playerSize, BLUE);
		}
	}

	void SceneComponentWorldMap::Update(const QuantumParams& quantumParams)
	{

	}

	void SceneComponentWorldMap::DoWithTrees(const std::function<void(const CellPos&)>& visitor)
	{
		for(auto & it : trees_)
		{
			visitor(it);
		}
	}
}
