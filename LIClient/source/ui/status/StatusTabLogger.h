#pragma once

#include "ui/IUiComponent.h"

namespace li
{
	class StatusTabLogger : public IUiComponent
	{
	public:
		void Render() override;
		void AddRecord(const std::string& rec);
	private:
		int records_amount_ = 10;
		std::deque<std::string> records_;
	};
}

