#pragma once

#include "ui/IUiComponent.h"
#include "ui/UiBox.h"
#include "utils/IComponentOwner.h"

namespace li
{
	class Ui_;
	class IStatusTab;

	//class Status : public IComponentOwner<IUiComponent>
	class Status : public UiBox<IUiComponent>
	{
	public:
		Status(Ui_ & ui);

		void Render(const UiBoxConfig & uiBoxConfig) override;

	private:
	};
}
