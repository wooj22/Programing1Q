#include <stdio.h>
#include "MenuScene.h"

namespace menu {
	// Start : MenuScene 진입 초기화
	void Initalize() {
		printf("---------------Menu Initalize----------------\n");
	}

	// Update : 상황에 (입력 또는 시간처리) 따라 SceneNext 설정
	void Update() {
		printf("Menu Update\n");
	}

	// Render : 메뉴그리기
	void Render() {
		printf("Menu Render\n");
	}
}
