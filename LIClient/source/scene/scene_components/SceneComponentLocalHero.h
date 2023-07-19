#pragma once

#include "scene/ISceneComponent.h"

namespace li
{
	class Actor;

	class SceneComponentLocalHero : public ISceneComponent
	{
	public:
		void Init(const WorldPos& position);
		void SetPosition(const WorldPos& aPosition);

		void Update(const QuantumParams& quantumParams) override;
		void Render() override;

		const std::shared_ptr<Actor> & GetActor() const
		{
			return actor_;
		}
	private:
		std::shared_ptr<Actor> actor_;

		std::vector<WorldPos> path_;
		std::optional<WorldPos> lastPoint_;
	};

	
}
