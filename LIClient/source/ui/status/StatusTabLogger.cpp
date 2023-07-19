#include "StatusTabLogger.h"

namespace li
{
	void StatusTabLogger::Render()
	{
		ImGui::InputInt("log size", &records_amount_);

		ImGui::BeginListBox("", ImVec2{ 140, 200 });

		for(auto & it : records_)
		{
			ImGui::Text("%s", it.c_str());
		}

		ImGui::EndListBox();
	}

	void StatusTabLogger::AddRecord(const std::string & rec)
	{
		if (!records_.empty() && records_.front() == rec)
			return;

		records_.push_front(rec);
		if(records_.size() > records_amount_)
		{
			records_.resize(records_amount_);
		}

	}
}
