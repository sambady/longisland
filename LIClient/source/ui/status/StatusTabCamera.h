#pragma once

#include "ui/IUiComponent.h"

namespace li
{
	class StatusTabCamera : public IUiComponent
	{
	public:
		void Render() override;

		Vector2 mousePos;
		WorldPos worldPos;
	};
}

