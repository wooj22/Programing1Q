#include <stdio.h>
#include "EndScene.h"

namespace end {
	// Start : EndScene�� ó�� �����Ҷ� ȣ��
	void Initalize() {
		printf("---------------End Initalize----------------\n");
	}

	// Update : ��Ȳ�� (�Է� �Ǵ� �ð�ó��) ���� SceneNext ����
	void Update() {
		printf("End Update\n");
	}

	// Render : ���� �׸���
	void Render() {
		printf("End Render\n");
	}
}