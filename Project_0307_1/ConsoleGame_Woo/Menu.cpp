#include <stdio.h>
#include "MenuScene.h"
#include "ConsoleRenderer.h"

namespace menu {
	// Start
	void Initalize() {
		printf("---------------Menu Scene Initalize----------------\n");
		ConsoleRenderer::ScreenInit();
		ConsoleRenderer::ScreenDrawString(0, 0, "MENU SCENE", FG_PINK_DARK);
		ConsoleRenderer::ScreenFlipping();
	}

	// Update 
	void Update() {
		
	}

	// Render
	void Render() {
		
	}
}
