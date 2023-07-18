#pragma once

#include "scene/ISceneComponent.h"

namespace li
{
	class Town;

	class SceneComponentTownManager : public ISceneComponent
	{
	public:
		void CreateTown(const WorldPos & centerPos_);

		void Update(const QuantumParams & quantumParams) override;
		void Render() override;
	private:
		std::map<int, Town> towns_;

	};

	
}
