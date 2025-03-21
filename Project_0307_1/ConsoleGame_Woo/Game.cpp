#include <stdio.h>
#include <windows.h>
#include "Game.h"
#include "MenuScene.h"
#include "PlayScene.h"
#include "EndScene.h"
#include "ConsoleRenderer.h"
#include "Input.h"

/*  END SCENE 유지시간 체크용 변수  */
LARGE_INTEGER freq, startTime, endTime;
double elapsedTime = 0;

// Start : 게임 시작
void Initalize() {
	// 씬 초기화
	g_SceneCurrent = MENU_SCENE;
	//g_SceneNext = PLAY_SCENE;

	// 키 상태 초기화
	g_PrevKeyState = 0;
	g_keyState = 0;

	// 메뉴씬 시작
	menu::Initalize();
}

// Update : SceneCurrent에 따라 Update()호출
void Update() {
	// key input
	Input::Update();

	// scene change
	g_keyState = GetAsyncKeyState(VK_SPACE);
	if ((g_keyState & 0x8000) && !(g_PrevKeyState & 0x8000)) {
		switch (g_SceneCurrent) 
		{
			case MENU_SCENE:
				g_SceneCurrent = PLAY_SCENE;
				play::Initalize();
				break;
			case PLAY_SCENE:
				g_SceneCurrent = END_SCENE;
				end::Initalize();
				// END SCENE 진입, 10초뒤 MENU SCENE 전환
				QueryPerformanceFrequency(&freq);
				QueryPerformanceCounter(&startTime);
				break;
			case END_SCENE:
				break;
			default:
				printf("여기오면 안되는데\n");
				break;
		}
	}
	g_PrevKeyState = g_keyState;	// pre 키 상태 저장

	// update
	switch (g_SceneCurrent)
	{
		case MENU_SCENE:
			menu::Update();
			break;
		case PLAY_SCENE:
			play::Update();
			break;
		case END_SCENE:
			end::Update();

			// END SCENE 5초 경과시 MENU SCENE 이동
			QueryPerformanceCounter(&endTime);
			elapsedTime = static_cast<double>(endTime.QuadPart - startTime.QuadPart) / freq.QuadPart;

			if (elapsedTime >= 5.0) {
				g_SceneCurrent = MENU_SCENE;
				menu::Initalize();
			}
			break;
		default:
			printf("여기오면 안되는데\n");
			break;
	}
}

// Render : SceneCurrent에 따라 Render()호출  
void Render() {
	switch (g_SceneCurrent)
	{
	case MENU_SCENE:
		menu::Render();
		break;
	case PLAY_SCENE:
		play::Render();
		break;
	case END_SCENE:
		end::Render();
		break;
	default:
		printf("여기오면 안되는데\n");
		break;
	}
}

// Main : 게임 진행
// [Spacebar]를 누르면 씬을 전환합니다.
// 루프 종료가 없으니 주의하세요
int main() {
	ConsoleRenderer::ScreenInit();
	Initalize();

	while (true)
	{
		Update();
		Render();
	}

	ConsoleRenderer::ScreenRelease();
	return 0;
}
