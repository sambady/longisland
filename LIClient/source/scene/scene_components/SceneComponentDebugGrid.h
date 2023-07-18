#pragma once
#include "scene/ISceneComponent.h"

namespace li
{
	class SceneComponentDebugGrid : public ISceneComponent
	{
	public:
		void Render() override;
		void SetShowGrid(bool isEnable)
		{
			enabled_ = isEnable;
		}

	private:
		bool enabled_ = true;
	};

	
}
