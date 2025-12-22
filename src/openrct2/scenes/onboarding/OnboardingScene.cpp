/*****************************************************************************
 * Copyright (c) 2014-2025 OpenRCT2 developers
 *
 * For a complete list of all authors, please refer to contributors.md
 * Interested in contributing? Visit https://github.com/OpenRCT2/OpenRCT2
 *
 * OpenRCT2 is licensed under the GNU General Public License version 3.
 *****************************************************************************/

#include "OnboardingScene.h"

#include "../../Context.h"
#include "../../Diagnostic.h"
#include "../../Game.h"
#include "../../GameState.h"
#include "../../OpenRCT2.h"
#include "../../audio/Audio.h"
#include "../../interface/Viewport.h"
#include "../../localisation/StringIds.h"
#include "../../ui/WindowManager.h"
#include "../../windows/Intent.h"
#include "../../world/Map.h"

#include <sstream>

using namespace OpenRCT2;

OnboardingScene::OnboardingScene(IContext& context)
    : Scene(context)
{
}

void OnboardingScene::Load()
{
    LOG_VERBOSE("OnboardingScene::Load()");

    gLegacyScene = LegacyScene::playing;
    gameStateInitAll(getGameState(), kDefaultMapSize);
    ContextResetSubsystems();
    ContextOpenWindow(WindowClass::mainWindow);
    WindowSetFlagForAllViewports(VIEWPORT_FLAG_RENDERING_INHIBITED, true);
    WindowResizeGui(ContextGetWidth(), ContextGetHeight());

    // TODO: not particularly helpful yet, but it's a start
    auto* windowMgr = Ui::GetWindowManager();
    windowMgr->ShowError("Unable to load g1.dat!", "Your RollerCoaster Tycoon 2 path may be incorrectly set.");

    LOG_VERBOSE("OnboardingScene::Load() finished");
}

void OnboardingScene::Tick()
{
    gInUpdateCode = true;

    ContextHandleInput();

    auto* windowMgr = Ui::GetWindowManager();
    windowMgr->InvalidateAll();

    gInUpdateCode = false;
}

void OnboardingScene::Stop()
{
    Audio::StopAll();
}
