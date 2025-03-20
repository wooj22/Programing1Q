#pragma once
#include "ConsoleRenderer.h"

// enum으로 Scene 관리
enum Scene {
	MENU_SCENE,
	PLAY_SCENE,
	END_SCENE
};

Scene g_SceneCurrent;
Scene g_SceneNext;

// 씬 전환 조건 : [Spacebar]
SHORT g_PrevKeyState;
SHORT g_keyState;