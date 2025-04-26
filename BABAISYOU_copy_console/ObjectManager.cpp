#include "ObjectManager.h"
#include "TileMap.h"
#include "TileBase.h"
#include "Object.h"
#include "Position.h"
#include "Direction.h"
#include "InputManager.h"
#include <iostream>
using namespace std;


ObjectManager::ObjectManager(TileMap* map) :_Map(map)
{

}

ObjectManager::~ObjectManager()
{
}




vector<Object*> ObjectManager::GetObjectsWithRule(const string& rule)
{
    vector<Object*> result;
    for (int y = 0; y < _Map->GetHeight(); ++y) 
    {
        for (int x = 0; x < _Map->GetWidth(); ++x)
        {
           TileBase* tile = _Map->GetTile(Position(x, y));
            for (Object* obj : tile->GetObjects())
            {
                if (obj->HasRule(rule)) 
                {
                    result.push_back(obj);
                }
            }
        }
    }
    return result;
}

void ObjectManager::ApplyWinCondition()
{
    for (int y = 0; y < _Map->GetHeight(); ++y)
    {
        for (int x = 0; x < _Map->GetWidth(); ++x)
        {
            TileBase* tile = _Map->GetTile(Position(x, y));

            bool hasYou = false;
            bool hasWin = false;
            for (Object* obj : tile->GetObjects())
            {
                if (obj->HasRule("YOU")) { hasYou = true; }
                if (obj->HasRule("WIN")) { hasWin=true; }
          
            }
            if (hasYou && hasWin)
            {
                cout << "�������� Ŭ����!!" << endl;
                return;
            }

        }
    }
}

//bool ObjectManager::TryMove(Position currentPos, Direction dir)//�̵��� �����ϴٸ�..?!? �̵��Ҽ��ְԲ� ������־����
//{       
//    Position nextPos = currentPos;
//    switch (dir)
//    {
//    case Direction::UP:    
//        nextPos.s_y--; 
//        break;
//    case Direction::DOWN:  
//        nextPos.s_y++; 
//        break;
//    case Direction::LEFT:  
//        nextPos.s_x--;
//        break;
//    case Direction::RIGHT: 
//        nextPos.s_x++; 
//        break;
//    default: 
//        return false;
//    }
//    if (!_tileMap->isInside(nextPos))
//    {
//        return false;
//    }
//    if (_ruleManager->IsWin(_tileMap->GetTile(nextPos).GetObject()))
//    {
//        ObjectType myType = _tileMap->GetTile(currentPos).GetObject();
//        _tileMap->GetTile(nextPos).SetObject_prev(_tileMap->GetTile(nextPos).GetObject());
//        _tileMap->GetTile(currentPos).SetObject(ObjectType::NONE);
//        _tileMap->GetTile(nextPos).SetObject(myType);
//       return true;
//    }
//    if (!IsBlocked(nextPos))
//    {
//        return false;
//    } 
//    ObjectType nextObj = _tileMap->GetTile(nextPos).GetObject(); //������ ������Ʈ ����.
//    if (nextObj != ObjectType::NONE && _ruleManager->IsPushable(nextObj)) //���� �� ������Ʈ�� �´��� �ƴ��� Ȥ�� �м��ִ��� �ƴ���üũ
//    {
//        if (!TryPush(nextPos, dir)) //�������� ��ȯ�Ǹ� ���� ���̻� Ǫ���Ҽ����ٴ°Ŵϱ� false�̵��� �����Ѿ���
//            return false;
//    }
//    else if (nextObj != ObjectType::NONE)
//    {
//        return false;
//    }
//    // �̵� ó��!
//    ObjectType myType = _tileMap->GetTile(currentPos).GetObject(); //������ Ÿ���� ��ġ�� ��ȯ�Ͽ� �� Ÿ���� ������ƮŸ���� ��ȯ
//    _tileMap->GetTile(currentPos).SetObject(ObjectType::NONE);
//    _tileMap->GetTile(nextPos).SetObject(myType);
//    return true;
//}

//bool ObjectManager::TryPush(Position nextPos, Direction dir) //�� ���� �������� üũ�ؾ���..
//{
//    Position nextNextPos = nextPos;//���� �̴� ������Ʈ�� ���� �ڸ��� üũ�������..
//    switch (dir)
//    {
//    case Direction::UP:
//        nextNextPos.s_y--;
//        break;
//    case Direction::DOWN:
//        nextNextPos.s_y++;
//        break;
//    case Direction::LEFT:
//        nextNextPos.s_x--;
//        break;
//    case Direction::RIGHT:
//        nextNextPos.s_x++;
//        break;
//    default:
//        return false;
//    }//üũ�ؼ� �����̸� ��ġ�� �Ű��ָ��
//    if (!_tileMap->isInside(nextNextPos))//�з����� ������ ������..�Ϸ�....
//    {
//        return false;
//    }
//    ObjectType targetPushObj = _tileMap->GetTile(nextPos).GetObject();//���� �а���� ������Ʈ
//    ObjectType targetNextPushObj = _tileMap->GetTile(nextNextPos).GetObject();//���� �а���� ������Ʈ�� ��ĭ!
//    if (targetNextPushObj != ObjectType::NONE)//noneŸ���� ������Ʈ�� ���ʿ� �а����Ҳ� �ƴ�..
//    {
//        if (!_ruleManager->IsPushable(targetNextPushObj))//?! �����ϼ��ִ� ��Ͽ��ִ°�?!
//        {
//            return false;
//        }
//        if (!TryPush(nextNextPos, dir))//����� ȣ��� �ش� ������Ʈ�� ���� �ּҸ� ã�ƺ�..
//        {
//            return false;
//        }
//        //���� �м������� �̵� �۾��� �����ؾ���
//        //�ϴ� ����ó���� �Ϸ�..?! �����Ѱ� ������ �߰��غ�����..
//
//    }
//    _tileMap->GetTile(nextNextPos).SetObject(targetPushObj);
//    _tileMap->GetTile(nextPos).SetObject(ObjectType::NONE);
//    return true;
//}
    


//bool ObjectManager::IsBlocked(Position posStop)
//{
//    ObjectType targetStopObj = _tileMap->GetTile(posStop).GetObject();
//    
//
//    if (_ruleManager->IsBlocked(targetStopObj))
//    {      
//        return false;
//    }
//    
//    return true;
//}

//bool ObjectManager::IsWinConditionMet()
//{
//
//    for (int i = 0; i < _tileMap->GetHeight(); ++i)
//    {
//        for (int j = 0; j < _tileMap->GetWidth(); ++j)
//        {
//            Position pos(j, i);
//            ObjectType obj = _tileMap->GetTile(pos).GetObject();
//            if (_ruleManager->IsControllable(obj) && _ruleManager->IsWin(_tileMap->GetTile(pos).GetObject_prev()))//�̺κ��� ����
//            {
//                
//                return true;
//            }
//
//        }
//    }
//    return false;
//}
	
	//���� �ؾ��ϴ°� ���� �÷����Ҽ��ִ� ������Ʈ���� �� �Ǻ��ؾ��ϴ� ������

//Ÿ�ϸ��� �ش���ġ�� �ִ� Ÿ���� ������Ʈ Ÿ���� �����;��ϴ°�
//�׷� �ϴ� �ش���ġ�� ���� ���ִ°��� �����;��� �� �������� ��ȯ�ϴ°� �����;�