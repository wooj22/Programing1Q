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
		// 씬 진입 후 10초 뒤 MENU로 넘어가는 기능 추가

	}

	// Render
	void Render() {
		//printf("End Scene Render\n");
		ConsoleRenderer::ScreenDrawString(0, 0, "END SCENE  5초뒤 MENU SCENE으로 이동합니다", FG_GRAY);
	}
}