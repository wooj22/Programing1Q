#include <stdio.h>
#include <windows.h>
#include "EndScene.h"

// �� ���� �� 10�� �� MENU�� �Ѿ�� ��� �߰�
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