#include "GameFlow.h"
#include "TileMap.h"
#include "RuleManager.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "ObjectType.h"
#include "Tile.h"
#include "TileType.h"
#include "Windows.h"
#include "Position.h"
#include <iostream>
#include "ControlManager.h"
#include "Movement.h"
//���� ��ó���� ���� ���߿� �ϳ��� ��ĥ����..(winapi���� ����ؾ��ϱ⶧��..)
void MoveCursorToTop() //ȭ�� �������� ���̱����� Ŀ�� �� ó������ �����ؼ� �ٽ� �׸��� �뵵�λ����
{
    COORD coord = { 0, 0 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void HideCursor() //Ŀ���� ���̵� �ؼ� �ڵ�(�ܼ�������â)���� ����
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}
int main()
{
    HideCursor(); // ó���� �� ���� ����

    TileMap map;
    ObjectManager objMgr(&map);
    RuleManager ruleMgr(&objMgr, &map);
    ControlManager ctrlMgr(&objMgr, &ruleMgr, &map);
    InputManager inputMgr;

    ruleMgr.ClearRules();              // �ʱ� �� Ŭ����
    ruleMgr.ScanRulesFrom(&objMgr);   // �ʱ� �� Ž��

    while (true)
    {
        MoveCursorToTop();           // ȭ�� �ʱ�ȭ ���� ������ ����
        map.RenderMap();             // �� ���

        if (ruleMgr.IsVictory())     // �¸� ���� �˻�
        {
            std::cout << "\n���� Ŭ����!" << std::endl;
            break;
        }

        Direction input = inputMgr.GetInput(); // �Է� �ޱ�
        if (input == Direction::PAUSE) break;  // ESC�� ����

        ctrlMgr.TryMoveAll(input);  // �� ���⼭�� Direction �״�� �ѱ�

        ruleMgr.ClearRules();       // �� �缳��
        ruleMgr.ScanRulesFrom(&objMgr);
    }

    return 0;
}
//���ӱ����� �ʿ��� ������

//���� Ŭ���� ��������
//���� ������ �ؼ� ���������� ����� �δ°��� ����
// �̷� ������ ¥�� �ѹ� �����غ��� ���漱���ϰ� �ؼ� �����ͷ��� �ٿ�����..
// �Ⱦ��°ž��� �پ���

/// BabaIsYou /
//��
//������ / Core / �� �ٽ� �ý���
//��   ������ GameFlow.h / .cpp        �� ��ü ���� �帧 ���� (O)
//��   ������ StageManager.h / .cpp    �� ���� �������� ����(��, ��, ������Ʈ ����) (O)
//��   ������ InputManager.h / .cpp    �� Ű �Է� ���� (O)
//��   ������ OptionManager.h / .cpp   �� Ű ���� �� �ɼ� ���� (O)
//��   ������ SaveLoadManager.h / .cpp �� ���� �� �ҷ����� (O)
//��
//������ / World / �� ����� �κ� ����
//��   ������ Lobby.h / .cpp            �� �κ� ȭ�� (O)
//��   ������ WorldData.txt             �� �� ���庰 �������� ����
//��
//������ / Stage / �� �������� ���� ����
//��   ������ Stage.h / .cpp             �� �������� �ϳ��� ���� ����(O)
//��   ������ RuleManager.h / .cpp       �� �� �ý��� ���� (O)
//��   ������ ObjectManager.h / .cpp     �� ������Ʈ ����Ʈ �� �̵� ó�� (O)
//��   ������ StageData / �� �� ���ϵ�
//��       ������ Stage_1.txt
//��       ������ Stage_2.txt
//��       ������ ...
//��
//������ / Map / �� Ÿ�ϸ� ����
//��   ������ TileMap.h / .cpp          �� �� �迭 ���� �� ��� (O)
//��   ������ TileType.h                �� enum class TileType (O)
//��   ������ Tile.h / .cpp             �� Ÿ�� ����(Ÿ��, ������Ʈ) (O)
//��
//������ / Object / �� ������Ʈ(BABA, ROCK ��)
//��   ������ Object.h / .cpp            �� ���� Object ���̽� (O)
//��   ������ ObjectType.h               �� enum class ObjectType (O)
//��   ������ Position.h                 �� struct Position(��ǥ ������) (O)
//��
//������ / Resource / �� ���ҽ� �� ����
//��   ������ KeyBinding.cfg             �� Ű ���� ����
//��   ������ SaveData.sav              �� ���� ����
//��
//������ main.cpp              �� ������(main + GameFlow ����)
//������ CMakeLists.txt / .vcxproj     �� ���� ����