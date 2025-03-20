#include <stdio.h>
#include "EndScene.h"

namespace end {
	// Start : EndScene에 처음 진입할때 호출
	void Initalize() {
		printf("---------------End Initalize----------------\n");
	}

	// Update : 상황에 (입력 또는 시간처리) 따라 SceneNext 설정
	void Update() {
		printf("End Update\n");
	}

	// Render : 엔딩 그리기
	void Render() {
		printf("End Render\n");
	}
}