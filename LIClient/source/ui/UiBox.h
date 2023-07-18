#pragma once
#include "utils/IComponentOwner.h"

namespace li
{
	struct UiBoxConfig;

	template<typename T>
	class UiBox : public IComponentOwner<T>
	{
	public:
		virtual void Render(const UiBoxConfig & config) = 0;
	};
}

