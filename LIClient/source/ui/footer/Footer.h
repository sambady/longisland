#pragma once

#include "ui/IUiComponent.h"
#include "ui/UiBox.h"

namespace li
{
	class Ui_;
	class IFooterTab;

	class Footer : public UiBox<IFooterTab>
	{
	public:
		

		Footer(Ui_& ui);

		void Render(const UiBoxConfig& config) override;
		void Render(const ImVec2& offset, const ImVec2& size);

	private:
		std::optional<std::type_index> currentActiveTab_;
	};
}
