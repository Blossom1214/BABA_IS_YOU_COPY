#include "RuleManager.h"
#include "ObjectManager.h"
#include "TileMap.h"
#include "TileBase.h"
#include <iostream>
using namespace std;



//void RuleManager::ScanRulesFrom(ObjectManager* objMgr)
//{
//    for (int y = 0; y < _map->GetHeight(); ++y) {
//        for (int x = 0; x < _map->GetWidth(); ++x) {
//            Position pos(x, y);
//            CheckAndRegisterRule(*_map, pos, Direction::RIGHT);
//            CheckAndRegisterRule(*_map, pos, Direction::DOWN);
//        }
//    }
//}
//void RuleManager::CheckAndRegisterRule(TileMap map, Position pos, Direction dir)
//{
//    Object* TextToObjectType = _map->GetTile(pos)->GetType();//첫번째 오브젝트 타입
//	if (!IsTextObject(TileTextToObjectType)) { return; } //텍스트 오브젝트가 아니면 룰에 적용안하고 함수를 나감
//	ObjectType ObjectToObjectType = ConvertTextToObject(TileTextToObjectType);//
//	//동사의 위치
//	Position pos2 = pos;
//	if (dir == Direction::RIGHT) { pos2.s_x++; } //오른쪽
//	else if (dir == Direction::DOWN) { pos2.s_y++; }//아래
//	else { return; } // 그이외의 값이 dir로 들어오면 함수를나가기는 하는데...하지만위에서 이미 입력을 무조건적으로 받기때문에 문제는없음
//
//	if (!map.isInside(pos2)) { return; } //첫번째위치는 상관없지만 두번째로 체크하는 위치에는 동사도 와야하고 일단 맵밖이면 체크할 의미가없음 결국밖이면 함수를 탈출!
//	TileType TileTextverbType = map.GetTile(pos2).GetType(); //그 두번째 위치에있는값을 저장함
//	if (!IsTextVObject(TileTextverbType)) return; // 동사에 해당하는지체크함
//
//	//마지막 룰규칙 타일점검
//	Position pos3 = pos2;//2번타일에서 3번마지막타일의 위치를쓰기위한 저장
//	if (dir == Direction::RIGHT) { pos3.s_x++; }//오른쪽 확인!(사실 필요가 없다...)이미 2번째에서 결정이나버리면 그다음타일은 문장이 되기위해서는 해당방향으로만 읽어야함
//	else if (dir == Direction::DOWN) { pos3.s_y++; }//아래확인! 나중에 위에있던 값을 기준으로 리펙터링 작업을 진행예정
//
//	if (!map.isInside(pos3)) return;//여전히 맵밖인지체크
//	TileType RuleType = map.GetTile(pos3).GetType(); //3번째타일의 정보를 저장후 마지막타일을 룰타입이라지정
//	if (!IsTextRuleObject(RuleType)) return;//룰타입아니면...또 반환...
//
//	ObjectType rule = ConvertTextToObject(RuleType);//룰타입을 오브젝트로 변환작업
//
//	switch (rule)//이제 저 룰타입을 가지고 오브젝트 변환작업을 거친 것에다가작업을 거침
//	{
//	case ObjectType::TEXT_YOU:
//		ADD_YOU(ObjectToObjectType);
//		break;
//	case ObjectType::TEXT_PUSH:
//		ADD_PUSH(ObjectToObjectType);
//		break;
//	case ObjectType::TEXT_STOP:
//		ADD_STOP(ObjectToObjectType);
//		break;
//	case ObjectType::TEXT_WIN:
//		ADD_WIN(ObjectToObjectType);
//		break;
//	default:
//		break;
//	}
//}
//아래 코드를 위의 코드로 리펙터링하였음
//void RuleManager::CheckAndRegisterRule(TileMap& map, Position pos, Direction dir)
//{
//	
//	Position currentPos(pos);
//	TileType TType=map.GetTile(currentPos).GetType();
//	if (IsTextObject(TType)) //참이라면.. 이제 텍스트 오브젝트이기때문에...!아래로 또는 오른쪽으로 벡터의 포인터를 움직여보자!
//	{
//		Position nextPos = currentPos;//오브젝트의 현재위치에서 다음칸을 체크해야함... 아래또는 위로 둘다 체크해야하는것임
//		Position nextNextPos = nextPos;
//		switch (dir)
//		{
//		case Direction::RIGHT:
//			nextPos.s_x++;//다음칸으로갔을때 그게...동사여야함
//			if (map.isInside(nextPos))//다음칸에 맵밖이 아니여야함..
//			{
//				if (IsTextVObject(map.GetTile(nextPos).GetType()))//다음칸에 동사타일이라면...이제 그다음 타일을 확인해야하는 차레가 되었다!!
//				{	
//					
//					nextNextPos.s_x++;
//					if (map.isInside(nextNextPos))
//					{
//						if (IsTextRuleObject(map.GetTile(nextNextPos).GetType()))
//						{
//							ObjectType TextObj = ConvertTextToObject(TType);
//							ObjectType ruleObj =ConvertTextToObject(map.GetTile(nextNextPos).GetType());
//							switch (ruleObj)
//							{
//							case ObjectType::TEXT_STOP:
//								ADD_STOP(TextObj);
//								break;
//							case ObjectType::TEXT_YOU:
//								ADD_YOU(TextObj);
//								break;
//							case ObjectType::TEXT_WIN:
//								ADD_WIN(TextObj);
//								break;
//							case ObjectType::TEXT_PUSH:
//								ADD_PUSH(TextObj);
//								break;
//							default:
//								break;
//							}
//
//						}
//					}
//								
//				}
//			}
//		break;
//		case Direction::DOWN:
//			nextPos.s_y++;
//			if (map.isInside(nextPos))//다음칸에 맵밖이 아니여야함..
//			{
//				if (IsTextVObject(map.GetTile(nextPos).GetType()))//다음칸에 동사타일이라면...이제 그다음 타일을 확인해야하는 차레가 되었다!!
//				{
//					nextNextPos.s_y++;
//					if (map.isInside(nextNextPos))
//					{
//						if (IsTextRuleObject(map.GetTile(nextNextPos).GetType()))
//						{
//							ObjectType TextObj = ConvertTextToObject(TType);
//							ObjectType ruleObj = ConvertTextToObject(map.GetTile(nextNextPos).GetType());
//							switch (ruleObj)
//							{
//							case ObjectType::TEXT_STOP:
//								ADD_STOP(TextObj);
//								break;
//							case ObjectType::TEXT_YOU:
//								ADD_YOU(TextObj);
//								break;
//							case ObjectType::TEXT_WIN:
//								ADD_WIN(TextObj);
//								break;
//							case ObjectType::TEXT_PUSH:
//								ADD_PUSH(TextObj);
//								break;
//							default:
//								break;
//							}
//
//						}
//					}
//
//				}
//			}
//			break;
//		default:
//			break;
//		}
//	}
//}

RuleManager::RuleManager(ObjectManager* objMgr, TileMap* map): _objectManager(objMgr), _map(map)
{
}

RuleResult RuleManager::CheckMove(Object* mover, const Position& target, const Position& dir)
{
	RuleResult result;
	if (!_map->isInside(target)) {
		result.isBlocked = true;
		return result;
	}

    TileBase* tile = _map->GetTile(target);

    for (Object* obj : tile->GetObjects()) {
        if (obj->HasRule("STOP")) {
            result.isBlocked = true;
            return result;
        }
        if (obj->HasRule("PUSH")) {
            Position next = target + dir;
            if (!_map->isInside(next)) {
                result.isBlocked = true;
                return result;
            }

            TileBase* nextTile = _map->GetTile(next);
            if (!nextTile->GetObjects().empty()) {
                result.isBlocked = true;
                return result;
            }

            result.requiresPush = true;
            result.pushedObject = obj;
        }
    }

	return result;
}

bool RuleManager::IsVictory()
{
    for (int y = 0; y < _map->GetHeight(); ++y) {
        for (int x = 0; x < _map->GetWidth(); ++x) {
            TileBase* tile = _map->GetTile(Position(x, y));

            bool hasYou = false;
            bool hasWin = false;
            for (Object* obj : tile->GetObjects()) {
                if (obj->HasRule("YOU")) hasYou = true;
                if (obj->HasRule("WIN")) hasWin = true;
            }

            if (hasYou && hasWin)
                return true;
        }
    }

    return false;
}


void RuleManager::ClearRules()
{
    for (int y = 0; y < _map->GetHeight(); ++y) {
        for (int x = 0; x < _map->GetWidth(); ++x) {
            auto* tile = _map->GetTile(Position(x, y));
            for (auto* obj : tile->GetObjects()) {
                obj->RemoveRule("YOU");
                obj->RemoveRule("PUSH");
                obj->RemoveRule("STOP");
                obj->RemoveRule("WIN");
            }
        }
    }
}


