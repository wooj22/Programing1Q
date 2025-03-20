#include <stdio.h>
#include "EndScene.h"
#include "ConsoleRenderer.h"

// �� ���� �� 10�� �� MENU�� �Ѿ�� ��� �߰�
namespace end {
	// Start
	void Initalize() {
		printf("---------------End Scene Initalize----------------\n");
		ConsoleRenderer::ScreenClear();
		ConsoleRenderer::ScreenDrawString(0, 0, "END SCENE", FG_PINK_DARK);
		ConsoleRenderer::ScreenFlipping();
	}

	// Update 
	void Update() {
		printf("End Scene Update\n");
	}

	// Render
	void Render() {
		printf("End Scene Render\n");
	}
}