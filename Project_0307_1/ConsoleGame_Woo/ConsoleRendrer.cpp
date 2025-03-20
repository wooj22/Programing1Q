#include "ConsoleRenderer.h"
#include <stdio.h>

namespace ConsoleRenderer
{
    HANDLE hConsoleHandle;      // �ʱ� �ܼ� â�� �ڵ�

    int nScreenWidth = 0;       // �ܼ� â�� �ʺ�
    int nScreenHeight = 0;      // �ܼ� â�� ����
    int nScreenBufferSize = 0;  // �ܼ� â�� ��ũ�� ���� ũ�� (�ʺ� * ����)
    int nScreenBufferIndex = 0; // ���� ��� ���� ��ũ�� ������ �ε��� (0 �Ǵ� 1)
    HANDLE hScreenBuffer[2];    // �ܼ� â���� ����� ���� ���۸� ��ũ�� ���� (2��)

    /**
     * @brief �ܼ� ȭ�� �ʱ�ȭ (���� ���۸� ����)
     *
     * 1. ���� �ܼ� �ڵ��� ������
     * 2. �ܼ� ȭ�鿡 ����� ���� ���� (2��) ����
     * 3. Ŀ���� ���� (�⺻ �ܼ� �� ������ ���� ��� ����)
     * 4. ���� �ܼ� â�� ũ�⸦ ������ ȭ�� �ʺ�, ����, ��ü ���� ũ�� ����
     */
    void ScreenInit()
    {
        // ���� �ܼ� �ڵ��� ������
        hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

        // ���� ���ۿ� �ܼ� ��ũ�� ���� ���� (2��)
        hScreenBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
        hScreenBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

        // �⺻ �ܼ� �� ������ ��ũ�� ������ Ŀ���� ����
        CONSOLE_CURSOR_INFO cursorInfo = { 0, };
        cursorInfo.bVisible = FALSE;
        cursorInfo.dwSize = 1; // Ŀ�� ũ�� ���� (1~100 ����)

        SetConsoleCursorInfo(hConsoleHandle, &cursorInfo);
        SetConsoleCursorInfo(hScreenBuffer[0], &cursorInfo);
        SetConsoleCursorInfo(hScreenBuffer[1], &cursorInfo);

        // ���� �ܼ� â�� ũ�� ������ ������
        CONSOLE_SCREEN_BUFFER_INFO Info;
        GetConsoleScreenBufferInfo(hConsoleHandle, &Info);

        // �ܼ� â�� �ʺ�, ���� �� ��ü ȭ�� ���� ũ�� ����
        nScreenHeight = Info.srWindow.Bottom - Info.srWindow.Top + 1;
        nScreenWidth = Info.srWindow.Right - Info.srWindow.Left + 1;
        nScreenBufferSize = nScreenWidth * nScreenHeight;
    }

    /**
     * @brief ȭ�� ��ȯ (���� ���۸��� �̿��� ȭ�� ����)
     *
     * ���� ������ �ʴ� ���۸� Ȱ��ȭ�Ͽ� ȭ���� �ε巴�� �����ϰ�,
     * ���� �������� �غ��ϱ� ���� ���� �ε����� ���� (0 <-> 1)
     */
    void ScreenFlipping()
    {
        // ���� Ȱ��ȭ�� ��ũ�� ���۸� �����Ͽ� ȭ���� ��ȯ
        SetConsoleActiveScreenBuffer(hScreenBuffer[nScreenBufferIndex]);

        // ���� �������� ���� ����� ���� �ε����� ���� (0, 1 �ݺ�)
        nScreenBufferIndex = (nScreenBufferIndex + 1) % 2;
    }

    /**
     * @brief ���� ��� ���� ���۸� ���� ����(' ')�� ä�� ȭ���� ����
     */
    void ScreenClear()
    {
        COORD Coor = { 0, 0 }; // ���� ��ġ (���� ���)
        DWORD dw;

        // ���� Ȱ��ȭ�� ���۸� ���� ���ڷ� ä��
        FillConsoleOutputCharacter(hScreenBuffer[nScreenBufferIndex], ' ', nScreenBufferSize, Coor, &dw);
    }

    /**
     * @brief �ܼ� ��ũ�� ���� ���� (���α׷� ���� �� ȣ��)
     */
    void ScreenRelease()
    {
        CloseHandle(hScreenBuffer[0]);
        CloseHandle(hScreenBuffer[1]);
    }

    /**
     * @brief Ư�� ��ġ (x, y)�� ���� (ch) ��� �� �Ӽ� ����
     *
     * @param x ���� ��� X ��ǥ
     * @param y ���� ��� Y ��ǥ
     * @param ch ����� ����
     * @param attr ���� ���� �� �Ӽ� (WORD Ÿ��)
     * @return true ����
     * @return false ����
     */
    bool ScreenDrawChar(int x, int y, char ch, WORD attr)
    {
        COORD cdPos;
        BOOL bRval = FALSE;
        DWORD dwCharsWritten;

        cdPos.X = x;
        cdPos.Y = y;

        // ���ڸ� ���
        bRval = FillConsoleOutputCharacterA(hScreenBuffer[nScreenBufferIndex], ch, 1, cdPos, &dwCharsWritten);
        if (!bRval) printf("Error, FillConsoleOutputCharacter()\n");

        // ���� �Ӽ� (���� ��) ����
        bRval = FillConsoleOutputAttribute(hScreenBuffer[nScreenBufferIndex], attr, 1, cdPos, &dwCharsWritten);
        if (!bRval) printf("Error, FillConsoleOutputAttribute()\n");

        return bRval;
    }

    /**
     * @brief Ư�� ��ġ (x, y)�� ���ڿ� ��� �� �Ӽ� ����
     *
     * @param x ����� X ��ǥ
     * @param y ����� Y ��ǥ
     * @param pStr ����� ���ڿ�
     * @param attr ���ڿ� ���� �� �Ӽ� (WORD Ÿ��)
     * @return true ����
     * @return false ����
     */
    bool ScreenDrawString(int x, int y, const char* pStr, WORD attr)
    {
        COORD cdPos;
        BOOL bRval = FALSE;
        DWORD dwCharsWritten;

        cdPos.X = x;
        cdPos.Y = y;

        DWORD nNumberOfBytesToWrite = (DWORD)strlen(pStr);

        // ���ڿ� ���
        WriteConsoleOutputCharacterA(hScreenBuffer[nScreenBufferIndex], pStr, nNumberOfBytesToWrite, cdPos, &dwCharsWritten);

        // ���ڿ� �Ӽ� ����
        bRval = FillConsoleOutputAttribute(hScreenBuffer[nScreenBufferIndex], attr, nNumberOfBytesToWrite, cdPos, &dwCharsWritten);
        if (!bRval) printf("Error, FillConsoleOutputAttribute()\n");

        return bRval;
    }

    /**
     * @brief �ܼ� ��ü ���� �Ӽ� ����
     *
     * @param attr ������ �Ӽ� �� (WORD Ÿ��)
     * @return true ����
     * @return false ����
     */
    bool ScreenSetAttributes(WORD attr)
    {
        COORD cdPos = { 0, 0 };
        bool bRval = FALSE;
        DWORD dwCharsWritten;

        // �ܼ� ��ü �Ӽ� ����
        bRval = FillConsoleOutputAttribute(hScreenBuffer[nScreenBufferIndex], attr, nScreenBufferSize, cdPos, &dwCharsWritten);
        if (!bRval)
        {
            printf("Error, FillConsoleOutputCharacter()\n");
        }

        return bRval;
    }

    /**
     * @brief ���� �ܼ� �ʺ� ��ȯ
     */
    int ScreenWidth()
    {
        return nScreenWidth;
    }

    /**
     * @brief ���� �ܼ� ���� ��ȯ
     */
    int ScreenHeight()
    {
        return nScreenHeight;
    }
};
