#include "QuantumParams.h"

namespace li
{
	double QuantumParams::GetTimeDelta() const
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>(current - last).count() / 1000.0;
	}
}
