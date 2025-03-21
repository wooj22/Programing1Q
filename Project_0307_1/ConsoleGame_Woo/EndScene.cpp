#include <stdio.h>
#include "EndScene.h"
#include "ConsoleRenderer.h"
#include "Input.h"
#include "Time.h"

namespace End {
	// Start
	void Initalize() {
		Time::Initialize();
	}

	// Update 
	void Update() {
		// scene change (현재 Game.cpp에 구현되어있음)
		Time::UpdateTime();
		if (Time::GetTotalTime() >= 10.0) {

		}
	}

	// Render
	void Render() {
		//printf("End Scene Render\n");
		ConsoleRenderer::ScreenDrawString(0, 0, "END SCENE  5초뒤 MENU SCENE으로 이동합니다", FG_GRAY);
	}
}