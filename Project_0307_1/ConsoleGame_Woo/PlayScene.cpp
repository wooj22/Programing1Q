#include <stdio.h>
#include "PlayScene.h"

namespace play {
	// Start : PlayScene�� ó�� �����Ҷ� ȣ��
	void Initalize() {
		printf("---------------Play Initalize----------------\n");
	}

	// Update : ��Ȳ�� (�Է� �Ǵ� �ð�ó��) ���� SceneNext ����
	void Update() {
		printf("Play Update\n");
	}

	// Render : �÷��� ȭ�� �׸���
	void Render() {
		printf("Play Render\n");
	}
}
