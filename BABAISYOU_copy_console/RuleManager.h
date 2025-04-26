#pragma once

#include "Direction.h"
#include "Position.h"
#include "Object.h"

class ObjectManager;
class TileMap;

struct RuleResult {
    bool isBlocked = false;
    bool requiresPush = false;
    Object* pushedObject = nullptr;
};

class RuleManager
{
public:
    //void ScanRulesFrom(ObjectManager* objMgr);
    //void CheckAndRegisterRule(TileMap map, Position pos, Direction dir);
    //위 두개는 일단 타일들을 정확하게 분류하고 난뒤에 다시 작성을 해볼것임... 이젠 진짜 게임을 만드는것...
    RuleManager(ObjectManager* objMgr, TileMap* map);

    RuleResult CheckMove(Object* mover, const Position& target, const Position& dir);
    bool IsVictory();

    void ClearRules();
  

private:
    ObjectManager* _objectManager;
    TileMap* _map;
};


//set 자료구조를 쓰는이유(타입과 밸류가 같음)
//찾아야하는 자료의 순번으로 구별하되 그 구조가 벡터형태이면 삽입 삭제가 느리고
//리스트 구조면 그 경우가 많을경우에 오류가 발생할 가능성자체가높음
//따라서 탐색적으로도 편한 구조를 쓰기위해... 키와 밸류가 같은 자료구조를 사용하게되었음
//또한 조건에따라 어떤게 우선순위가 되는지도 필요하게됨
//맵에 들어가자마자 룰에 해당하면 맵에 적용해야함

//1. 탐색 조건
//수평(→) 또는 수직(↓) 방향으로만 탐색
//
//예 : TEXT_BABA TEXT_IS TEXT_YOU → "BABA is YOU"라는 룰로 해석됨
//
//2. 타입 매핑 필요
//TEXT_BABA → BABA
//
//TEXT_ROCK → ROCK
//
//TEXT_FLAG → FLAG
//
//TEXT_IS → 구문 중간에 반드시 있어야 함
//
//TEXT_YOU / TEXT_PUSH / TEXT_STOP / TEXT_WIN → 룰로 해석됨

//타일타입을 에라 모르겟다 그냥 내일하자...
