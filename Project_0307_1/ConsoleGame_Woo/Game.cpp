#include <stdio.h>
#include <windows.h>
#include "Game.h"
#include "MenuScene.h"
#include "PlayScene.h"
#include "EndScene.h"

// Start : 게임 시작
void Initalize() {
	// 씬 초기화
	g_SceneCurrent = MENU_SCENE;
	g_SceneNext = PLAY_SCENE;

	// 키 상태 초기화
	g_PrevKeyState = 0;
	g_keyState = 0;

	printf("Game Start !\n");
}

// Update : SceneCurrent에 따라 Update()호출
void Update() {
	// scene change
	g_keyState = GetAsyncKeyState(VK_SPACE);
	if ((g_keyState & 0x8000) && !(g_PrevKeyState & 0x8000)) {
		switch (g_SceneCurrent) 
		{
			case MENU_SCENE:
				play::Initalize();
				g_SceneCurrent = PLAY_SCENE;
				break;
			case PLAY_SCENE:
				end::Initalize();
				g_SceneCurrent = END_SCENE;
				break;
			case END_SCENE:
				printf("마지막 씬은 씬을 전환할 수 없습니다.\n");
				break;
			default:
				printf("여기오면 안되는데\n");
				break;
		}
	}
	g_PrevKeyState = g_keyState;

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
	Initalize();
	while (true)
	{
		Update();
		Render();
	}

	return 0;
}
