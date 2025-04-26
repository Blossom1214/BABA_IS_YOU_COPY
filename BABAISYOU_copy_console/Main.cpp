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
//위의 전처리는 전부 나중에 하나로 합칠예정..(winapi에서 사용해야하기때문..)
void MoveCursorToTop() //화면 깜밖임을 줄이기위해 커서 를 처음으로 셋팅해서 다시 그리는 용도로사용함
{
    COORD coord = { 0, 0 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void HideCursor() //커서를 하이딩 해서 핸들(콘솔윈도우창)에서 지움
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 1;
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);
}
int main()
{
    HideCursor(); // 처음에 한 번만 실행

    TileMap map;
    ObjectManager objMgr(&map);
    RuleManager ruleMgr(&objMgr, &map);
    ControlManager ctrlMgr(&objMgr, &ruleMgr, &map);
    InputManager inputMgr;

    ruleMgr.ClearRules();              // 초기 룰 클리어
    ruleMgr.ScanRulesFrom(&objMgr);   // 초기 룰 탐색

    while (true)
    {
        MoveCursorToTop();           // 화면 초기화 없이 깜빡임 방지
        map.RenderMap();             // 맵 출력

        if (ruleMgr.IsVictory())     // 승리 조건 검사
        {
            std::cout << "\n게임 클리어!" << std::endl;
            break;
        }

        Direction input = inputMgr.GetInput(); // 입력 받기
        if (input == Direction::PAUSE) break;  // ESC로 종료

        ctrlMgr.TryMoveAll(input);  // ← 여기서는 Direction 그대로 넘김

        ruleMgr.ClearRules();       // 룰 재설정
        ruleMgr.ScanRulesFrom(&objMgr);
    }

    return 0;
}
//게임구현에 필요한 정보들

//게임 클래스 구조구현
//폴더 관리를 해서 계층구조를 만들어 두는것이 좋다
// 이런 식으로 짜서 한번 구현해보자 전방선언도하고 해서 데이터량도 줄여보자..
// 안쓰는거없이 다쓰자

/// BabaIsYou /
//│
//├── / Core / ← 핵심 시스템
//│   ├── GameFlow.h / .cpp        ← 전체 게임 흐름 관리 (O)
//│   ├── StageManager.h / .cpp    ← 현재 스테이지 제어(맵, 룰, 오브젝트 통합) (O)
//│   ├── InputManager.h / .cpp    ← 키 입력 관리 (O)
//│   ├── OptionManager.h / .cpp   ← 키 설정 등 옵션 관리 (O)
//│   └── SaveLoadManager.h / .cpp ← 저장 및 불러오기 (O)
//│
//├── / World / ← 월드와 로비 관련
//│   ├── Lobby.h / .cpp            ← 로비 화면 (O)
//│   └── WorldData.txt             ← 각 월드별 스테이지 정보
//│
//├── / Stage / ← 스테이지 진행 관련
//│   ├── Stage.h / .cpp             ← 스테이지 하나의 실행 단위(O)
//│   ├── RuleManager.h / .cpp       ← 룰 시스템 관리 (O)
//│   ├── ObjectManager.h / .cpp     ← 오브젝트 리스트 및 이동 처리 (O)
//│   └── StageData / ← 맵 파일들
//│       ├── Stage_1.txt
//│       ├── Stage_2.txt
//│       └── ...
//│
//├── / Map / ← 타일맵 관련
//│   ├── TileMap.h / .cpp          ← 맵 배열 관리 및 출력 (O)
//│   ├── TileType.h                ← enum class TileType (O)
//│   ├── Tile.h / .cpp             ← 타일 구조(타입, 오브젝트) (O)
//│
//├── / Object / ← 오브젝트(BABA, ROCK 등)
//│   ├── Object.h / .cpp            ← 공통 Object 베이스 (O)
//│   ├── ObjectType.h               ← enum class ObjectType (O)
//│   └── Position.h                 ← struct Position(좌표 관리용) (O)
//│
//├── / Resource / ← 리소스 및 설정
//│   ├── KeyBinding.cfg             ← 키 설정 파일
//│   └── SaveData.sav              ← 저장 파일
//│
//├── main.cpp              ← 진입점(main + GameFlow 시작)
//└── CMakeLists.txt / .vcxproj     ← 빌드 설정