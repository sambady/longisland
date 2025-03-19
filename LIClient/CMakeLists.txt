cmake_minimum_required(VERSION 3.24.0)

project(LIClient)


include(FetchContent)


Set(FETCHCONTENT_QUIET FALSE)

message(STATUS "Include raylib")
set(RAYLIB_VERSION 5.5)
FetchContent_Declare(
        raylib
        URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
        FIND_PACKAGE_ARGS ${RAYLIB_VERSION} EXACT
)
SET(BUILD_EXAMPLES OFF CACHE INTERNAL "")

#FetchContent_Declare(
#        raylib
#        GIT_REPOSITORY https://github.com/raysan5/raylib
#        GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(raylib)

message(STATUS "Include imgui")
FetchContent_Declare(
        ImGui
        GIT_REPOSITORY https://github.com/ocornut/imgui
        GIT_PROGRESS TRUE)

FetchContent_MakeAvailable(ImGui)
FetchContent_GetProperties(ImGui SOURCE_DIR IMGUI_DIR)

add_library(
        imgui STATIC
        ${imgui_SOURCE_DIR}/imgui.cpp
        ${imgui_SOURCE_DIR}/imgui_draw.cpp
        ${imgui_SOURCE_DIR}/imgui_widgets.cpp
        ${imgui_SOURCE_DIR}/imgui_tables.cpp)
target_include_directories(imgui INTERFACE ${imgui_SOURCE_DIR})


#FetchContent_MakeAvailable(imgui)


#find_package(raylib CONFIG REQUIRED)
#find_package(imgui CONFIG REQUIRED)

message(STATUS "Include rlImGui")
FetchContent_Declare(
        rlImGui
        GIT_REPOSITORY https://github.com/raylib-extras/rlImGui
        GIT_TAG main
        GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(rlImGui)
FetchContent_GetProperties(rlImGui SOURCE_DIR RLIMGUI_DIR)

add_library(rlimgui STATIC ${rlimgui_SOURCE_DIR}/rlImgui.cpp)
target_link_libraries(rlimgui PRIVATE imgui raylib)
target_include_directories(rlimgui INTERFACE ${rlimgui_SOURCE_DIR})

add_executable(LIClient
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
target_link_libraries(LIClient PRIVATE imgui)
target_link_libraries(LIClient PRIVATE rlimgui)
target_link_libraries(LIClient PRIVATE LILibCommon)

target_precompile_headers(LIClient PRIVATE "source/Precompiled.h")
target_compile_features(LIClient PRIVATE cxx_std_20)
