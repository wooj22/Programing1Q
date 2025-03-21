#include <stdio.h>
#include "PlayScene.h"
#include "ConsoleRenderer.h"

namespace play {
	COORD g_Player = { 0,0 };
	bool g_bQuit = false;

	// Start
	void Initalize() {
		//printf("---------------Play Scene Initalize----------------\n");
	}

	// Update
	void Update() {
		//printf("Play Scene Update\n");
		ProcessInput();
		PlayerMove();
	}

	// Render
	void Render() {
		//printf("Play Scene Render\n");
		ConsoleRenderer::ScreenClear();
		ConsoleRenderer::ScreenDrawString(0, 0, "PLAY SCENE", FG_RED);
		ConsoleRenderer::ScreenDrawChar(g_Player.X, g_Player.Y, 'P', FG_WHITE);
		ConsoleRenderer::ScreenFlipping();
	}

	void ProcessInput()
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000) { //왼쪽
			g_Player.X--;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000) { //오른쪽
			g_Player.X++;
		}
		if (GetAsyncKeyState(VK_UP) & 0x8000) { //위
			g_Player.Y--;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000) { //아래
			g_Player.Y++;
		}
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) { //종료
			g_bQuit = true;
		}
	}

	void PlayerMove() {
		if (g_Player.X < 0) g_Player.X = 0;
		if (g_Player.X >= ConsoleRenderer::ScreenWidth()) g_Player.X = ConsoleRenderer::ScreenWidth() - 1;
		if (g_Player.Y < 0) g_Player.Y = 0;
		if (g_Player.Y >= ConsoleRenderer::ScreenHeight()) g_Player.Y = ConsoleRenderer::ScreenHeight() - 1;
	}
}
