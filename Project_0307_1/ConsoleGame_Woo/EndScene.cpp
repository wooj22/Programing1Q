#include <stdio.h>
#include "EndScene.h"
#include "ConsoleRenderer.h"
#include "Input.h"

namespace end {
	// Start
	void Initalize() {
		
	}

	// Update 
	void Update() {
		// �� ���� �� 10�� �� MENU�� �Ѿ�� ��� �߰�

	}

	// Render
	void Render() {
		//printf("End Scene Render\n");
		ConsoleRenderer::ScreenDrawString(0, 0, "END SCENE  5�ʵ� MENU SCENE���� �̵��մϴ�", FG_GRAY);
	}
}