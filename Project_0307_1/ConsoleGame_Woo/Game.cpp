#include <stdio.h>
#include <windows.h>
#include "Game.h"
#include "MenuScene.h"
#include "PlayScene.h"
#include "EndScene.h"
#include "ConsoleRenderer.h"
#include "Input.h"

namespace Game {
	// �� �ʱ�ȭ
	Scene g_SceneCurrent = Game::MENU_SCENE;

	// Start : ���� ����
	void Initalize() {
		Menu::Initalize();
	}

	// Update : SceneCurrent�� ���� Update()ȣ��
	void Update() {
		// key input
		Input::Update();

		// update
		switch (Game::g_SceneCurrent)
		{
		case Game::MENU_SCENE:
			Menu::Update();
			break;
		case Game::PLAY_SCENE:
			Play::Update();
			break;
		case Game::END_SCENE:
			End::Update();
			break;
		default:
			printf("������� �ȵǴµ�\n");
			break;
		}
	}

	// Render : SceneCurrent�� ���� Render()ȣ��  
	void Render() {
		ConsoleRenderer::ScreenClear();

		switch (Game::g_SceneCurrent)
		{
		case Game::MENU_SCENE:
			Menu::Render();
			break;
		case Game::PLAY_SCENE:
			Play::Render();
			break;
		case Game::END_SCENE:
			End::Render();
			break;
		default:
			printf("������� �ȵǴµ�\n");
			break;
		}

		ConsoleRenderer::ScreenFlipping();
	}
}

// Main : ���� ����
// [Spacebar]�� ������ ���� ��ȯ�մϴ�.
// ���� ���ᰡ ������ �����ϼ���
int main() {
	ConsoleRenderer::ScreenInit();
	Game::Initalize();

	while (true)
	{
		Game::Update();
		Game::Render();
	}

	ConsoleRenderer::ScreenRelease();
	return 0;
}