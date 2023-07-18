#pragma once

#include "FastComponentAccess.h"

namespace li
{
	template<typename TBaseClass>
	class IComponentOwner
	{
	public:
		virtual ~IComponentOwner() = default;

		template<std::derived_from<TBaseClass> T, typename TBase = void>
		std::shared_ptr<T> RegisterComponent(FCA<TBase> * fca = nullptr)
		{
			auto obj = std::make_shared<T>();
			components_[std::type_index(typeid(T))] = obj;
			if constexpr(!std::is_same_v<TBase, void>)
			{
				if (fca != nullptr) {
					fca->RegComponent(obj);
				}
			}

			return obj;
		}

		template<std::derived_from<TBaseClass> T>
		std::shared_ptr<T> GetComponent()
		{
			if (auto it = components_.find(std::type_index(typeid(T))); it != components_.end()) {
				return std::dynamic_pointer_cast<T>(it->second);
			}
			return nullptr;
		}

		template<std::derived_from<TBaseClass> T>
		std::shared_ptr<T> GetOrCreateComponent()
		{
			auto it = components_.insert(std::make_pair(std::type_index(typeid(T)), std::make_shared<T>()));
			auto obj = std::dynamic_pointer_cast<T>(it.first->second);

			return obj;
		}

	protected:
		std::unordered_map<std::type_index, std::shared_ptr<TBaseClass>> components_;
	};
}
