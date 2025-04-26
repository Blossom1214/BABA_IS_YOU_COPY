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
//    Object* TextToObjectType = _map->GetTile(pos)->GetType();//ù��° ������Ʈ Ÿ��
//	if (!IsTextObject(TileTextToObjectType)) { return; } //�ؽ�Ʈ ������Ʈ�� �ƴϸ� �꿡 ������ϰ� �Լ��� ����
//	ObjectType ObjectToObjectType = ConvertTextToObject(TileTextToObjectType);//
//	//������ ��ġ
//	Position pos2 = pos;
//	if (dir == Direction::RIGHT) { pos2.s_x++; } //������
//	else if (dir == Direction::DOWN) { pos2.s_y++; }//�Ʒ�
//	else { return; } // ���̿��� ���� dir�� ������ �Լ���������� �ϴµ�...������������ �̹� �Է��� ������������ �ޱ⶧���� �����¾���
//
//	if (!map.isInside(pos2)) { return; } //ù��°��ġ�� ��������� �ι�°�� üũ�ϴ� ��ġ���� ���絵 �;��ϰ� �ϴ� �ʹ��̸� üũ�� �ǹ̰����� �ᱹ���̸� �Լ��� Ż��!
//	TileType TileTextverbType = map.GetTile(pos2).GetType(); //�� �ι�° ��ġ���ִ°��� ������
//	if (!IsTextVObject(TileTextverbType)) return; // ���翡 �ش��ϴ���üũ��
//
//	//������ ���Ģ Ÿ������
//	Position pos3 = pos2;//2��Ÿ�Ͽ��� 3��������Ÿ���� ��ġ���������� ����
//	if (dir == Direction::RIGHT) { pos3.s_x++; }//������ Ȯ��!(��� �ʿ䰡 ����...)�̹� 2��°���� �����̳������� �״���Ÿ���� ������ �Ǳ����ؼ��� �ش�������θ� �о����
//	else if (dir == Direction::DOWN) { pos3.s_y++; }//�Ʒ�Ȯ��! ���߿� �����ִ� ���� �������� �����͸� �۾��� ���࿹��
//
//	if (!map.isInside(pos3)) return;//������ �ʹ�����üũ
//	TileType RuleType = map.GetTile(pos3).GetType(); //3��°Ÿ���� ������ ������ ������Ÿ���� ��Ÿ���̶�����
//	if (!IsTextRuleObject(RuleType)) return;//��Ÿ�Ծƴϸ�...�� ��ȯ...
//
//	ObjectType rule = ConvertTextToObject(RuleType);//��Ÿ���� ������Ʈ�� ��ȯ�۾�
//
//	switch (rule)//���� �� ��Ÿ���� ������ ������Ʈ ��ȯ�۾��� ��ģ �Ϳ��ٰ��۾��� ��ħ
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
//�Ʒ� �ڵ带 ���� �ڵ�� �����͸��Ͽ���
//void RuleManager::CheckAndRegisterRule(TileMap& map, Position pos, Direction dir)
//{
//	
//	Position currentPos(pos);
//	TileType TType=map.GetTile(currentPos).GetType();
//	if (IsTextObject(TType)) //���̶��.. ���� �ؽ�Ʈ ������Ʈ�̱⶧����...!�Ʒ��� �Ǵ� ���������� ������ �����͸� ����������!
//	{
//		Position nextPos = currentPos;//������Ʈ�� ������ġ���� ����ĭ�� üũ�ؾ���... �Ʒ��Ǵ� ���� �Ѵ� üũ�ؾ��ϴ°���
//		Position nextNextPos = nextPos;
//		switch (dir)
//		{
//		case Direction::RIGHT:
//			nextPos.s_x++;//����ĭ���ΰ����� �װ�...���翩����
//			if (map.isInside(nextPos))//����ĭ�� �ʹ��� �ƴϿ�����..
//			{
//				if (IsTextVObject(map.GetTile(nextPos).GetType()))//����ĭ�� ����Ÿ���̶��...���� �״��� Ÿ���� Ȯ���ؾ��ϴ� ������ �Ǿ���!!
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
//			if (map.isInside(nextPos))//����ĭ�� �ʹ��� �ƴϿ�����..
//			{
//				if (IsTextVObject(map.GetTile(nextPos).GetType()))//����ĭ�� ����Ÿ���̶��...���� �״��� Ÿ���� Ȯ���ؾ��ϴ� ������ �Ǿ���!!
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


