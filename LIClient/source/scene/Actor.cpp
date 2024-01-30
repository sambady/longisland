#include "Precompiled.h"

#include "Actor.h"

#include <raylib.h>

namespace li
{
	void Actor::Render()
	{
		Vector3 playerPosition = { position_.y,  1.0f , position_.x};
		Vector3 playerSize = { 1.0f, 2.0f, 1.0f };


		DrawCubeV(playerPosition, playerSize, color_);
		DrawCubeWiresV(playerPosition, playerSize, BLUE);
	}

}

