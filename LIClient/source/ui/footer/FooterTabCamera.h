#pragma once
#include "IFooterTab.h"


namespace li
{
	class FooterTabCamera : public IFooterTab
	{
	public:
		void Render() override;

		float offset_[3] = { -20.f, 20.f, -20.f };
	};
}
