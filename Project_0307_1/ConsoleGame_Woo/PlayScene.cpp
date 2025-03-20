#include <stdio.h>
#include "PlayScene.h"

namespace play {
	// Start : PlayScene에 처음 진입할때 호출
	void Initalize() {
		printf("---------------Play Initalize----------------\n");
	}

	// Update : 상황에 (입력 또는 시간처리) 따라 SceneNext 설정
	void Update() {
		printf("Play Update\n");
	}

	// Render : 플레이 화면 그리기
	void Render() {
		printf("Play Render\n");
	}
}
