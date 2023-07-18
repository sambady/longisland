#pragma once
#include "IBaseGameObject.h"


namespace li
{
	struct GameConfig_
	{
		static GameConfig_ & Instance()
		{
			static GameConfig_ i;
			return i;
		}

		Vector2 renderSize = { 0.f, 0.f };
		Vector2 renderOffset = { 0.f, 0.f };
		float renderPadding = 0.f;
	};

	GameConfig_& GameConfig();
}
