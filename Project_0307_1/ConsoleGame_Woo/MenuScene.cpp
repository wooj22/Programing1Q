#include <stdio.h>
#include "MenuScene.h"
#include "ConsoleRenderer.h"
#include "Input.h"

namespace menu {
	// Start
	void Initalize() {
		//printf("---------------Menu Scene Initalize----------------\n");
		ConsoleRenderer::ScreenClear();
		ConsoleRenderer::ScreenDrawString(0, 0, "MENU SCENE", FG_YELLOW);
		ConsoleRenderer::ScreenFlipping();
	}

	// Update 
	void Update() {
		//printf("Menu Scene Render\n");
	}

	// Render
	void Render() {
		//printf("Menu Scene Render\n");
	}
}
