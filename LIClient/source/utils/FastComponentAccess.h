#pragma once

namespace li
{
	template<typename TBaseClass>
	class FCA
	{
	public:
		virtual ~FCA() = default;

		template<std::derived_from<TBaseClass> T>
		void RegComponent(const std::shared_ptr<T> & obj)
		{
			fca_components_[std::type_index(typeid(T))] = obj;
		}

		template<std::derived_from<TBaseClass> T>
		std::shared_ptr<T> GetComp() const
		{
			if(auto it = fca_components_.find(std::type_index(typeid(T))); it != fca_components_.end())	{
				return std::static_pointer_cast<T>(it->second);
			}
			return nullptr;
		}
	protected:
		std::unordered_map<std::type_index, std::shared_ptr<TBaseClass>> fca_components_;
	};
}