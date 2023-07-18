#pragma once

namespace li
{
	struct QuantumParams
	{
		std::chrono::time_point<std::chrono::system_clock> current;
		std::chrono::time_point<std::chrono::system_clock> last;
		double GetTimeDelta() const;
	};
}

