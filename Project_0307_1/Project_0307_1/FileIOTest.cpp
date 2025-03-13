#include <iostream>
#include <windows.h>
using namespace std;

// 파일 입출력 디렉토리 확인
// 실행 프로세스의 파일 경로와 작업 디렉토리의 경로는 보통(탐색기 실행)은 같지만 실행 방법에 따라 다를 수 있음
// ex) 비주얼 스튜디오에서 소스코드를 실행하는 환경. Exe출력 위치와 작업 디렉토리가 다름
// ex) 명령 프롬프트에서 Cmd에서 실행파일의 경로까지 진입하지 않고 경로까지 포함하여 exe를 실행하는경우
// ex) 바로가기를 만들고 작업 디렉토리를 따로 설정하는 경우
// 리소스 파일을 참조할때 프로젝트 바깥에 리소스 폴더를 따로 만들어서 해당 디렉토리를 참조하도록 함

int main() {
	char szBuffer1[MAX_PATH] = { 0, };
	char szBuffer2[MAX_PATH] = { 0, };
	GetModuleFileNameA(NULL, szBuffer1, MAX_PATH);
	GetCurrentDirectoryA(MAX_PATH, szBuffer2);

	cout << "GetModuleFileNameA : " << szBuffer1 << '\n' << "GetCurrentDirectoryA : " << szBuffer2;

	return 0;
}