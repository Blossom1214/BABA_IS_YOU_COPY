#include "ControlManager.h"
#include "RuleManager.h"
#include "ObjectManager.h"
#include "TileMap.h"
#include "TileBase.h"
#include <iostream>
#include "Movement.h"
ControlManager::ControlManager(ObjectManager* objMgr, RuleManager* ruleMgr, TileMap* map):_objectManager(objMgr), _ruleManager(ruleMgr), _map(map)
{

}

bool ControlManager::TryMoveAll(Direction dir) 
{
    Position vec = Movement::Vector(dir);
    bool moved = false;
    auto controllables = _objectManager->GetObjectsWithRule("YOU");

    for (auto* obj : controllables)
    {
        if (TryMove(obj, vec)) 
        {
            moved = true;
        }
    }

    return moved;
}

bool ControlManager::TryMove(Object* obj, const Position& dir)
{
    Position next = obj->GetPosition() + dir;
    if (!_map->isInside(next)) return false;

    auto result = _ruleManager->CheckMove(obj, next, dir);
    if (result.isBlocked) return false;

    // 楷尖 PUSH 贸府
    if (result.requiresPush && result.pushedObject)
    {
        if (!TryMove(result.pushedObject, dir))
            return false;
    }

    // 角力 捞悼 贸府
    TileBase* fromTile = _map->GetTile(obj->GetPosition());
    TileBase* toTile = _map->GetTile(next);

    fromTile->RemoveObject(obj);
    toTile->AddObject(obj);
    obj->SetPosition(next);

    return true;
}
