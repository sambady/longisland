#include "Precompiled.h"

#include "Actor.h"

#include <raylib.h>

namespace li
{
	void Actor::Render()
	{
		Vector3 playerPosition = { position_.y + 0.5f,  1.0f , position_.x + 0.5f };
		Vector3 playerSize = { 1.0f, 2.0f, 1.0f };


		DrawCubeV(playerPosition, playerSize, color_);
		DrawCubeWiresV(playerPosition, playerSize, BLUE);
	}

}

