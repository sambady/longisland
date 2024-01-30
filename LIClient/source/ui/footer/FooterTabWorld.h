#pragma once
#include "IFooterTab.h"


namespace li
{
	class FooterTabWorld : public IFooterTab
	{
	public:
		void Render() override;
	public:
		float xy[2] = { 0, 0 };
		bool showGrid = true;

		float xyLocalHero[2] = { 0.5f, 0.5f };
	};
}
