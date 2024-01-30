#include "SceneComponentLocalHero.h"

#include "algorithm/algorithm_position.h"
#include "helpers/WorldPositionHelper.h"
#include "navmesh/navmesh_type_converter.h"
#include "navmesh/path_finder.h"
#include "scene/Actor.h"
#include "scene/Scene.h"
#include "ui/Ui.h"
#include "ui/status/StatusTabLogger.h"
#include "utils/stl/stl_container_helper.h"
#include "world_map/SceneComponentWorldMap.h"

namespace li
{
	void SceneComponentLocalHero::Init(const WorldPos& position)
	{
		actor_ = std::make_shared<Actor>(position, RED);

	}

	void SceneComponentLocalHero::SetPosition(const WorldPos & position)
	{
		if (actor_ == nullptr)
			return;
		actor_->SetPosition(position);
	}

	void SceneComponentLocalHero::Update(const QuantumParams& quantumParams)
	{
		if (actor_ == nullptr)
			return;
		
		if (path_.empty())
			return;

		auto funcCleanUpPath = [&]()
		{
			path_.clear();
			lastPoint_.reset();
		};

		if(!lastPoint_)
		{
			lastPoint_ = *path_.begin();
		}

		auto lastPointIt = std::ranges::find(path_, *lastPoint_);
		if (lastPointIt == path_.end())
			return;

		auto nextPointIt = lastPointIt + 1;
		if (nextPointIt == path_.end()) {
			path_.clear();
			lastPoint_.reset();
			return;
		}

		auto nextPoint = *nextPointIt;
		auto lastPoint = *lastPointIt;

		auto direction = nextPoint - lastPoint;
		direction.Normalize();
		auto currentPosition = actor_->GetPosition();

		auto sizeToEnd = nextPoint - actor_->GetPosition();
		//actor_->SetPosition(*);


		auto speed = 2.f * quantumParams.GetTimeDelta();

		auto distanceBetweenPoint = (nextPoint - lastPoint).GetLenght();
		auto distanceBetweenActorAndLast = (currentPosition - lastPoint).GetLenght();


		if(sizeToEnd.GetLenght() > speed && distanceBetweenPoint > distanceBetweenActorAndLast) {
			auto newPos = currentPosition + direction * speed;
			actor_->SetPosition(newPos);
		} 
		else {
			actor_->SetPosition(nextPoint);
			lastPoint_ = nextPoint;
		}
	}

	void SceneComponentLocalHero::Render()
	{
		if (actor_ == nullptr)
			return;


		auto worldMap = Scene().GetComponent<SceneComponentWorldMap>();
		std::vector<NavMesh::Polygon> pols;
		worldMap->DoWithTrees([&](const auto & pos)
			{
				if((CellToWorld(pos) - actor_->GetPosition()).GetLenght() > 50)
					return;

				NavMesh::Polygon poligon;
				poligon.AddPoint(pos.x, pos.y);
				pols.push_back(poligon);
			});

		
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
			if (auto worldPos = Scene().GetMouseWorldPosition(); worldPos)
			{
				auto timeStart = std::chrono::system_clock::now();
				NavMesh::PathFinder pathFinder;

				std::vector<WorldPos> points = { actor_->GetPosition() , *worldPos };

				pathFinder.AddPolygons(pols, 2);

				pathFinder.AddExternalPoints(utils::VectorTransform<WorldPos, NavMesh::Point>(points, WorldPosToPoint));
				path_ = pathFinder.GetPath(
					actor_->GetPosition(),
					*worldPos);
				if(!path_.empty()) {
					path_[0] = actor_->GetPosition();
				}
				lastPoint_.reset();

				auto timeEnd = std::chrono::system_clock::now();

				Ui().GetComp<StatusTabLogger>()->AddRecord(
					std::format("Path {}",
						std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - timeStart).count()));

			}
		}

		if (path_.size() > 1)
		{
			for(auto i = 1; i < path_.size(); i++)
			{
				DrawLine3D(
					helpers::WorldPosToVector3(path_[i - 1]),
					helpers::WorldPosToVector3(path_[i]),
					BLUE);
			}
		}


		for(auto & pol : pols)
		{
			//DrawCube(Vector3{ 1.f, 0.f, 1.f }, -5, 1, -5, RED);
		}

		actor_->Render();
	}
}
