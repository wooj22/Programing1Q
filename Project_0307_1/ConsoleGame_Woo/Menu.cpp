#include <stdio.h>
#include "MenuScene.h"

namespace menu {
	// Start : MenuScene ���� �ʱ�ȭ
	void Initalize() {
		printf("---------------Menu Initalize----------------\n");
	}

	// Update : ��Ȳ�� (�Է� �Ǵ� �ð�ó��) ���� SceneNext ����
	void Update() {
		printf("Menu Update\n");
	}

	// Render : �޴��׸���
	void Render() {
		printf("Menu Render\n");
	}
}
