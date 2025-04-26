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
                cout << "스테이지 클리어!!" << endl;
                return;
            }

        }
    }
}

//bool ObjectManager::TryMove(Position currentPos, Direction dir)//이동이 가능하다면..?!? 이동할수있게끔 만들어주어야함
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
//    ObjectType nextObj = _tileMap->GetTile(nextPos).GetObject(); //내가밀 오브젝트 생각.
//    if (nextObj != ObjectType::NONE && _ruleManager->IsPushable(nextObj)) //내가 밀 오브젝트가 맞는지 아닌지 혹은 밀수있는지 아닌지체크
//    {
//        if (!TryPush(nextPos, dir)) //거짓으로 반환되면 이제 더이상 푸시할수없다는거니까 false이동을 못시켜야함
//            return false;
//    }
//    else if (nextObj != ObjectType::NONE)
//    {
//        return false;
//    }
//    // 이동 처리!
//    ObjectType myType = _tileMap->GetTile(currentPos).GetObject(); //현재의 타일의 위치를 반환하여 그 타일의 오브젝트타입을 반환
//    _tileMap->GetTile(currentPos).SetObject(ObjectType::NONE);
//    _tileMap->GetTile(nextPos).SetObject(myType);
//    return true;
//}

//bool ObjectManager::TryPush(Position nextPos, Direction dir) //그 뒤의 블럭까지도 체크해야함..
//{
//    Position nextNextPos = nextPos;//내가 미는 오브젝트의 뒤의 자리를 체크해줘야함..
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
//    }//체크해서 성공이면 위치를 옮겨주면됨
//    if (!_tileMap->isInside(nextNextPos))//밀려나는 오류도 수정을..완료....
//    {
//        return false;
//    }
//    ObjectType targetPushObj = _tileMap->GetTile(nextPos).GetObject();//내가 밀고싶은 오브젝트
//    ObjectType targetNextPushObj = _tileMap->GetTile(nextNextPos).GetObject();//내가 밀고싶은 오브젝트의 뒷칸!
//    if (targetNextPushObj != ObjectType::NONE)//none타입의 오브젝트는 애초에 밀고말고할께 아님..
//    {
//        if (!_ruleManager->IsPushable(targetNextPushObj))//?! 움직일수있는 목록에있는가?!
//        {
//            return false;
//        }
//        if (!TryPush(nextNextPos, dir))//재귀적 호출로 해당 오브젝트의 다음 주소를 찾아봄..
//        {
//            return false;
//        }
//        //이제 밀수있으면 이동 작업을 진행해야함
//        //일단 예외처리는 완료..?! 부족한게 있으면 추가해보겟음..
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
//            if (_ruleManager->IsControllable(obj) && _ruleManager->IsWin(_tileMap->GetTile(pos).GetObject_prev()))//이부분이 문제
//            {
//                
//                return true;
//            }
//
//        }
//    }
//    return false;
//}
	
	//지금 해야하는게 내가 플레이할수있는 오브젝트인지 를 판별해야하는 문제임

//타일맵의 해당위치에 있는 타일의 오브젝트 타입을 가져와야하는것
//그럼 일단 해당위치를 얻을 수있는것을 가져와야함 즉 포지션을 반환하는걸 가져와애