#include "Precompiled.h"

#include "Scene.h"

#include "Actor.h"
#include "GameConfig.h"
#include "scene_components/SceneComponentDebugGrid.h"
#include "scene_components/SceneComponentLocalHero.h"
#include "scene_components/world_map/SceneComponentWorldMap.h"
#include "ui/Ui.h"
#include "ui/status/StatusTabCamera.h"
#include "utils/RaylibEx.h"

namespace li
{
	Scene_ & Scene()
	{
		return Scene_::Instance();
	}


	int GetRenderOffset()
	{
		return 20;
	}


    int GetRenderWidth() {
		return GetScreenWidth() - GetRenderOffset() * 2;
	}

	int GetRenderHeight()
	{
		return GetScreenHeight() - GetRenderOffset() * 2 - 200;
	}

	Vector2 GetWorldMouseCoordinate()
	{
		Vector2 mouse = GetMousePosition();
		Vector2 virtualMouse = { 0 };
		virtualMouse.x = (mouse.x - (GetScreenWidth() - GetRenderWidth()) * 0.5f);
		virtualMouse.y = (mouse.y - (GetScreenHeight() - GetRenderHeight()) * 0.5f);
		virtualMouse = Vector2Clamp(virtualMouse, Vector2 { 0, 0 }, Vector2 { (float)GetRenderWidth(), (float)GetRenderHeight() });
		return virtualMouse;
	}


	Scene_::Scene_()
	{

	}

	void Scene_::Init()
	{
		RegisterComponent<SceneComponentDebugGrid>()->drawOrder = 1;
		RegisterComponent<SceneComponentLocalHero>()->drawOrder = 2;
		RegisterComponent<SceneComponentWorldMap>()->drawOrder = 3;
		camera_.Init();

		quantumParams_.current = std::chrono::system_clock::now();
		quantumParams_.last = std::chrono::system_clock::now();

		for(const auto & component : components_ | std::views::values)
		{
			component->Init();
		}
	}


	void Scene_::AddActor(const WorldPos & pos)
	{
		auto nextId = 1;
		if (!actors_.empty())
			nextId = actors_.rbegin()->first + 1;

		actors_[nextId] = std::make_shared<Actor>(pos, GREEN);

	}

	void Scene_::RemoveAllActors()
	{
		actors_.clear();
	}

	void Scene_::Render(const Vector2& renderSize, const Vector2& renderOffset)
	{
		camera_.UpdateKeyboard();


		CreateOrUpdateRenderTexture(renderSize);
		
		SetTextureFilter(target_->texture, TEXTURE_FILTER_BILINEAR);  // Texture scale filter to use

		BeginTextureMode(*target_);
		ClearBackground(YELLOW);  // Clear render texture background color

		BeginMode3D(camera_.GetCamera());

		std::vector<std::shared_ptr<ISceneComponent>> components;

		for(const auto & component : components_ | std::views::values)
		{
			components.push_back(component);
		}
		std::ranges::sort(components, [](const auto & a, const auto & b)
		{
			return a->drawOrder > b->drawOrder;
		});

		quantumParams_.last = quantumParams_.current;
		quantumParams_.current = std::chrono::system_clock::now();

		for(auto & it : components)
		{
			it->Update(quantumParams_);
			it->Render();
		}

		for (auto& actor : actors_ | std::views::values)
		{
			actor->Render();
		}

		EndMode3D();

		EndTextureMode();
	}

	void Scene_::Draw(const Vector2& renderSize, const Vector2& renderOffset)
	{
		ClearBackground(BLACK); 

		DrawTexturePro(target_->texture,
			Rectangle { 0.0f, 0.0f, (float)target_->texture.width, (float)-target_->texture.height },
			Rectangle{ renderOffset.x, renderOffset.y,renderSize.x,renderSize.y},
			Vector2 { 0, 0 },
			0.0f, WHITE);
	}

	void Scene_::CreateOrUpdateRenderTexture(const Vector2& renderSize)
	{
		if(!target_ ||
			target_->texture.width != renderSize.x ||
			target_->texture.height != renderSize.y)
		{
			if(target_)
			{
				UnloadRenderTexture(*target_);
			}

			target_ = LoadRenderTexture(renderSize.x, renderSize.y);
		}
	}

	void Scene_::FillMouseInfo() const
	{
		Vector2 mouseScenePosition = Vector2Subtract(
			GetMousePosition(), GameConfig().renderOffset
		);
		
		auto cameraStatus = Ui().GetComp<StatusTabCamera>();

		if (mouseScenePosition.x < 0.f || mouseScenePosition.x > GameConfig().renderSize.x ||
			mouseScenePosition.y < 0.f || mouseScenePosition.y > GameConfig().renderSize.y)
		{
			cameraStatus->mousePos = { 0.f, 0.f };
			cameraStatus->worldPos = { 0.f, 0.f };;
		}
		else
		{
			auto worldPos = raylib_ex::ScreenToWorldPos(mouseScenePosition, camera_.GetCamera(), GameConfig().renderSize.x, GameConfig().renderSize.y);
			cameraStatus->mousePos = mouseScenePosition;
			cameraStatus->worldPos = worldPos;
		}
	}

	std::optional<WorldPos> Scene_::GetMouseWorldPosition()
	{
		Vector2 mouseScenePosition = Vector2Subtract(
			GetMousePosition(), GameConfig().renderOffset
		);

		if (mouseScenePosition.x >= 0.f && mouseScenePosition.x <= GameConfig().renderSize.x &&
			mouseScenePosition.y >= 0.f && mouseScenePosition.y <= GameConfig().renderSize.y)
		{
			return raylib_ex::ScreenToWorldPos(mouseScenePosition, camera_.GetCamera(), GameConfig().renderSize.x, GameConfig().renderSize.y);
		}
		else
		{
			return std::nullopt;
		}
	}
}
