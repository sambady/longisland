#pragma once
#include "Camera.h"
#include "ISceneComponent.h"
#include "QuantumParams.h"
#include "utils/IComponentOwner.h"

namespace li
{
	class Actor;
	class Town;

	class Scene_ : public IComponentOwner<ISceneComponent>
	{
	public:
		static Scene_& Instance()
		{
			static Scene_ i;
			return i;
		}

		Scene_();

		void AddActor(const WorldPos& pos);
		void RemoveAllActors();

		void Init();

		void Render(const Vector2 & renderSize, const Vector2& renderOffset);

		void Draw(const Vector2& renderSize, const Vector2& renderOffset);

		LiCamera& GetCamera()
		{
			return camera_;
		}

		void FillMouseInfo() const;

		std::optional<WorldPos> GetMouseWorldPosition();

	private:

		void CreateOrUpdateRenderTexture(const Vector2& renderSize);

		std::map<ActorId, std::shared_ptr<Actor>> actors_;
		std::map<TownId, std::shared_ptr<Town>> towns_;
		std::optional<RenderTexture2D> target_;

		LiCamera camera_;

		QuantumParams quantumParams_;
	};

	Scene_ & Scene();
}
