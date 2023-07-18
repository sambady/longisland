#pragma once

namespace li
{
	struct QuantumParams;

	class ISceneComponent
	{
	public:
		virtual ~ISceneComponent() = default;
		virtual void Init() {}
		virtual void Render() = 0;
		virtual void Update(const QuantumParams & quantumParams) {}

		int drawOrder = 0;
	};
}
