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
		// scene change (���� Game.cpp�� �����Ǿ�����)
		Time::UpdateTime();
		if (Time::GetTotalTime() >= 10.0) {

		}
	}

	// Render
	void Render() {
		//printf("End Scene Render\n");
		ConsoleRenderer::ScreenDrawString(0, 0, "END SCENE  5�ʵ� MENU SCENE���� �̵��մϴ�", FG_GRAY);
	}
}