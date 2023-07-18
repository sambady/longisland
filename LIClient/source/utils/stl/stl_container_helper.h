#pragma once

namespace li::utils
{
	template<typename TIn, typename TOut, typename TConverter>
	std::vector<TOut> VectorTransform(const std::vector<TIn> & input, TConverter converter)
	{
		std::vector<TOut> output;
		for(auto & it : input)
		{
			output.push_back(converter(it));
		}
		return output;
	}
}