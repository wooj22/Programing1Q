#include <stdio.h>
#include "EndScene.h"
#include "ConsoleRenderer.h"
#include "Input.h"


// �� ���� �� 10�� �� MENU�� �Ѿ�� ��� �߰�
namespace end {
	// Start
	void Initalize() {
		//printf("---------------End Scene Initalize----------------\n");
	}

	// Update 
	void Update() {
		//printf("End Scene Update\n");
	}

	// Render
	void Render() {
		//printf("End Scene Render\n");
		ConsoleRenderer::ScreenDrawString(0, 0, "END SCENE  5�ʵ� MENU SCENE���� �̵��մϴ�", FG_GRAY);
	}
}