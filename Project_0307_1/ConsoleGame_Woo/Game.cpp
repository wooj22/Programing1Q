#include <stdio.h>
#include <windows.h>
#include "Game.h"
#include "MenuScene.h"
#include "PlayScene.h"
#include "EndScene.h"

// Start : ���� ����
void Initalize() {
	// �� �ʱ�ȭ
	g_SceneCurrent = MENU_SCENE;
	g_SceneNext = PLAY_SCENE;

	// Ű ���� �ʱ�ȭ
	g_PrevKeyState = 0;
	g_keyState = 0;

	printf("Game Start !\n");
}

// Update : SceneCurrent�� ���� Update()ȣ��
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
				printf("������ ���� ���� ��ȯ�� �� �����ϴ�.\n");
				break;
			default:
				printf("������� �ȵǴµ�\n");
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
	Initalize();
	while (true)
	{
		Update();
		Render();
	}

	return 0;
}
