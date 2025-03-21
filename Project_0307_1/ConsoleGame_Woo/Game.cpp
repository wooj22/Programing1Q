#include <stdio.h>
#include <windows.h>
#include "Game.h"
#include "MenuScene.h"
#include "PlayScene.h"
#include "EndScene.h"
#include "ConsoleRenderer.h"
#include "Input.h"

/*  END SCENE �����ð� üũ�� ����  */
LARGE_INTEGER freq, startTime, endTime;
double elapsedTime = 0;

// Start : ���� ����
void Initalize() {
	// �� �ʱ�ȭ
	g_SceneCurrent = MENU_SCENE;
	//g_SceneNext = PLAY_SCENE;

	// Ű ���� �ʱ�ȭ
	g_PrevKeyState = 0;
	g_keyState = 0;

	// �޴��� ����
	menu::Initalize();
}

// Update : SceneCurrent�� ���� Update()ȣ��
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
				// END SCENE ����, 10�ʵ� MENU SCENE ��ȯ
				QueryPerformanceFrequency(&freq);
				QueryPerformanceCounter(&startTime);
				break;
			case END_SCENE:
				break;
			default:
				printf("������� �ȵǴµ�\n");
				break;
		}
	}
	g_PrevKeyState = g_keyState;	// pre Ű ���� ����

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

			// END SCENE 5�� ����� MENU SCENE �̵�
			QueryPerformanceCounter(&endTime);
			elapsedTime = static_cast<double>(endTime.QuadPart - startTime.QuadPart) / freq.QuadPart;

			if (elapsedTime >= 5.0) {
				g_SceneCurrent = MENU_SCENE;
				menu::Initalize();
			}
			break;
		default:
			printf("������� �ȵǴµ�\n");
			break;
	}
}

// Render : SceneCurrent�� ���� Render()ȣ��  
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
		printf("������� �ȵǴµ�\n");
		break;
	}
}

// Main : ���� ����
// [Spacebar]�� ������ ���� ��ȯ�մϴ�.
// ���� ���ᰡ ������ �����ϼ���
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
