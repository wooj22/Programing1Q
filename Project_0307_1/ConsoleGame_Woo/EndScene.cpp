#include <stdio.h>
#include "EndScene.h"
#include "ConsoleRenderer.h"

// 씬 진입 후 10초 뒤 MENU로 넘어가는 기능 추가
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