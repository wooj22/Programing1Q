#include <stdio.h>
#include <windows.h>
#include "EndScene.h"

// 씬 진입 후 10초 뒤 MENU로 넘어가는 기능 추가
namespace end {
	// Start
	void Initalize() {
		printf("---------------End Initalize----------------\n");
	}

	// Update 
	void Update() {
		printf("End Update\n");
	}

	// Render
	void Render() {
		printf("End Render\n");
	}
}