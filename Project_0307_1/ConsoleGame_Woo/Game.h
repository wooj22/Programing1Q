#pragma once
#include "ConsoleRenderer.h"

// enum���� Scene ����
enum Scene {
	MENU_SCENE,
	PLAY_SCENE,
	END_SCENE
};

Scene g_SceneCurrent;
Scene g_SceneNext;

// �� ��ȯ ���� : [Spacebar]
SHORT g_PrevKeyState;
SHORT g_keyState;