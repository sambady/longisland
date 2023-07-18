#pragma once
#include "scene/ISceneComponent.h"

namespace li
{

	class SceneComponentWorldMap : public ISceneComponent
	{
	public:
		void Init() override;
		void Render() override;
		void Update(const QuantumParams& quantumParams) override;

		void DoWithTrees(const std::function<void(const CellPos&)> & visitor);
	private:
		std::vector<CellPos> trees_;
	};

}