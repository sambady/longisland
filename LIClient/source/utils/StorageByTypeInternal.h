#pragma once

namespace li
{
	namespace utils
	{
		template<typename T>
		class StorageByTypeInternal
		{
		public:
			std::shared_ptr<T> Get(std::type_index ti)
			{
				if (auto it = components_.find(ti); it != components_.end())
				{
					return it->second;
				}
				else
				{
					return nullptr;
				}
			}

			std::shared_ptr<T> Create(std::type_index ti, const std::shared_ptr<T>& obj)
			{
				components_[ti] = obj;
				return obj;
			}
		private:
			std::unordered_map<std::type_index, std::shared_ptr<T>> components_;
		};

	}

}


