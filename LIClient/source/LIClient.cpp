#include "Precompiled.h"

#include "GameConfig.h"
#include "raylib.h"

#include "ui/Ui.h"
#include "scene/Scene.h"


//int wWinMain()
int main()
{
    // Initialization
   //--------------------------------------------------------------------------------------
    const int screenWidth = 1000;
    const int screenHeight = 800;
    
    InitWindow(screenWidth, screenHeight, "raylib [models] example - box collisions");
	EnableCursor();
    rlImGuiSetup(true);
    SetTargetFPS(60);

    {
		//li::utils::StorageByTypeInternal<li::BaseGameObject> storage;
		//li::Game::Init(&storage);
	    using namespace li;

		Scene().Init();

	    const float footerHeight = 300.f;
	    const float statusWidth = 150.f;
	    while (!WindowShouldClose()) 
	    {
	        

	        UiConfig uiConfig;
	        uiConfig.statusConfig.offset = ImVec2{ 0.f, 0.f };
	        uiConfig.statusConfig.size = ImVec2{ statusWidth, screenHeight };

	        uiConfig.footerConfig.offset = ImVec2{ uiConfig.statusConfig.size.x, screenHeight - footerHeight };
	        uiConfig.footerConfig.size = ImVec2{ screenWidth - uiConfig.statusConfig.size.x, footerHeight };
	        
	        auto & gameConfig = GameConfig();
	        gameConfig.renderPadding = 20.f;


	        gameConfig.renderSize = {
        		screenWidth - gameConfig.renderPadding * 2 - statusWidth,
        		screenHeight - gameConfig.renderPadding * 2 - footerHeight
	        };
	        gameConfig.renderOffset = {
        		statusWidth + gameConfig.renderPadding,
	            gameConfig.renderPadding
	        };

	        Scene().Render(gameConfig.renderSize, gameConfig.renderOffset);

	        BeginDrawing();
	        ClearBackground(RAYWHITE);

	        Scene().Draw(gameConfig.renderSize, gameConfig.renderOffset);
	        Ui().Render(uiConfig);

			ShowCursor();
	        EndDrawing();
	    }
    }


    rlImGuiShutdown();
    CloseWindow(); 

    return 0;
}
