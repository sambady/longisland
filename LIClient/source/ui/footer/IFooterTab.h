#pragma once
#include "ui/IUiComponent.h"
#include "utils/IComponentOwner.h"

namespace li
{
	class IFooterTab : public IUiComponent, IComponentOwner<IUiComponent>
	{
	public:
		std::string tabName_;
	};
}
