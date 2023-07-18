#pragma once


namespace li
{
	struct IUiComponent
	{
		virtual ~IUiComponent() = default;
		virtual void Render() = 0;
	};
}
