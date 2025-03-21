#include <stdio.h>
#include "PlayScene.h"
#include "ConsoleRenderer.h"
#include "Input.h"

namespace play {
	COORD g_Player = { 0,0 };
	bool g_bQuit = false;

	// Start
	void Initalize() {
		
	}

	// Update
	void Update() {
		// input & play controll
		ProcessInput();
		PlayerMove();

		// scene change
		if (Input::IsKeyPressed(VK_SPACE)) {

		}
	}

	// Render
	void Render() {
		ConsoleRenderer::ScreenDrawString(0, 0, "[PLAY SCENE]", FG_RED);
		ConsoleRenderer::ScreenDrawChar(g_Player.X, g_Player.Y, 'P', FG_WHITE);
	}

	void ProcessInput()
	{
		if (Input::IsKeyDown(VK_LEFT)) { //왼쪽
			g_Player.X--;
		}
		if (Input::IsKeyDown(VK_RIGHT)) { //오른쪽
			g_Player.X++;
		}
		if (Input::IsKeyDown(VK_UP)) { //위
			g_Player.Y--;
		}
		if (Input::IsKeyDown(VK_DOWN)) { //아래
			g_Player.Y++;
		}
		if (Input::IsKeyDown(VK_ESCAPE)) { //종료
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
