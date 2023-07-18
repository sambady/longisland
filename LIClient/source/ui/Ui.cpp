#include "Ui.h"

#include "footer/Footer.h"
#include "status/Status.h"

namespace li
{
	Ui_& Ui()
	{
		return Ui_::Instance();
	}

	Ui_::Ui_()
	{
		footerMenu_ = std::make_shared<Footer>(*this);
		statusWindow_ = std::make_shared<Status>(*this);
	}

	void Ui_::Render(const UiConfig& config)
	{
		rlImGuiBegin();
		footerMenu_->Render(config.footerConfig);
		statusWindow_->Render(config.statusConfig);
		rlImGuiEnd();
	}
}
