#pragma once
#include "types/position.h"

namespace li
{
	class Actor
	{
	public:
		Actor(const WorldPos & pos, const Color & color)
			: color_(color)
			, position_(pos){}
		void Render();

		void SetPosition(const WorldPos& pos)
		{
			position_ = pos;
		}
		const WorldPos& GetPosition()
		{
			return position_;
		}
	private:
		Color color_;
		WorldPos position_;
	};

}



