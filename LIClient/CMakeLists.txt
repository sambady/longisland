cmake_minimum_required(VERSION 3.0.0)

project(LIClient)


find_package(raylib CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

add_executable(LIClient 
./3dparty/rlimgui/extras/FA6FreeSolidFontData.h
./3dparty/rlimgui/extras/FontAwsome_LICENSE.txt
./3dparty/rlimgui/extras/IconsFontAwesome6.h
./3dparty/rlimgui/rlImGui.cpp
./3dparty/rlimgui/rlImGui.h
./3dparty/rlimgui/rlImGuiColors.h
./source/helpers/WorldPositionHelper.cpp
./source/helpers/WorldPositionHelper.h
./source/IBaseGameObject.h
./source/LIClient.cpp
./source/Precompiled.h
./source/GameConfig.h
./source/GameConfig.cpp
./source/scene/Actor.cpp
./source/scene/Actor.h
./source/scene/Building.cpp
./source/scene/Building.h
./source/scene/Camera.cpp
./source/scene/Camera.h
./source/scene/ISceneComponent.h
./source/scene/QuantumParams.cpp
./source/scene/QuantumParams.h
./source/scene/Scene.cpp
./source/scene/Scene.h
./source/scene/scene_components/SceneComponentDebugGrid.cpp
./source/scene/scene_components/SceneComponentDebugGrid.h
./source/scene/scene_components/SceneComponentLocalHero.cpp
./source/scene/scene_components/SceneComponentLocalHero.h
./source/scene/scene_components/town/SceneComponentTownManager.cpp
./source/scene/scene_components/town/SceneComponentTownManager.h
./source/scene/scene_components/town/Town.cpp
./source/scene/scene_components/town/Town.h
./source/scene/scene_components/world_map/SceneComponentWorldMap.cpp
./source/scene/scene_components/world_map/SceneComponentWorldMap.h
./source/TestCompileSpeed.cpp
./source/ui/footer/Footer.cpp
./source/ui/footer/Footer.h
./source/ui/footer/FooterTabCamera.cpp
./source/ui/footer/FooterTabCamera.h
./source/ui/footer/FooterTabWorld.cpp
./source/ui/footer/FooterTabWorld.h
./source/ui/footer/IFooterTab.h
./source/ui/IUiComponent.h
./source/ui/status/Status.cpp
./source/ui/status/Status.h
./source/ui/status/StatusTabCamera.cpp
./source/ui/status/StatusTabCamera.h
./source/ui/status/StatusTabLogger.cpp
./source/ui/status/StatusTabLogger.h
./source/ui/status/StatusTabMouse.cpp
./source/ui/status/StatusTabMouse.h
./source/ui/Ui.cpp
./source/ui/Ui.h
./source/ui/UiBox.cpp
./source/ui/UiBox.h
./source/ui/UiBoxConfig.h
./source/utils/FastComponentAccess.h
./source/utils/IComponentOwner.h
./source/utils/LiNonCopyable.h
./source/utils/RayLibEx.cpp
./source/utils/RaylibEx.h
./source/utils/stl/stl_container_helper.cpp
./source/utils/stl/stl_container_helper.h
./source/utils/StorageByTypeInternal.h
)
target_include_directories(LIClient PRIVATE "source")
target_include_directories(LIClient PRIVATE "3dparty")
target_include_directories(LIClient PRIVATE "./")
target_include_directories(LIClient PRIVATE "../LILibCommon/source")

target_link_libraries(LIClient PRIVATE raylib)
target_link_libraries(LIClient PRIVATE imgui::imgui)
target_link_libraries(LIClient PRIVATE "${CMAKE_SOURCE_DIR}/../LILibCommon/build/liblicommon.lib")

target_precompile_headers(LIClient PRIVATE "source/Precompiled.h")
target_compile_features(LIClient PRIVATE cxx_std_20)
