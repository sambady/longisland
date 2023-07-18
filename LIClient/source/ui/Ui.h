#pragma once
#include "IBaseGameObject.h"
#include "IUiComponent.h"
#include "UiBoxConfig.h"
#include "utils/FastComponentAccess.h"

namespace li
{
	class Status;
	class Footer;

	struct UiConfig
	{
		UiBoxConfig footerConfig;
		UiBoxConfig statusConfig;
	};

	class Ui_ : public FCA<IUiComponent>
	{
	public:
		static Ui_ & Instance()
		{
			static Ui_ i;
			return i;
		}

		Ui_();

		void Render(const UiConfig& config);
	private:

		std::shared_ptr<Footer> footerMenu_;
		std::shared_ptr<Status> statusWindow_;
	};

	Ui_ & Ui();
}
