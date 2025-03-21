#include <stdio.h>
#include "MenuScene.h"
#include "ConsoleRenderer.h"
#include "Input.h"

namespace Menu {
	// Start
	void Initalize() {
		
	}

	// Update 
	void Update() {
		// scene change
		if (Input::IsKeyPressed(VK_SPACE)) {

		}
	}

	// Render
	void Render() {
		ConsoleRenderer::ScreenDrawString(0, 0, "MENU SCENE", FG_YELLOW);
	}
}
