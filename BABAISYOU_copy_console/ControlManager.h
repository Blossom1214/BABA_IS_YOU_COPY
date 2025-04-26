#pragma once
#include "Direction.h"
#include "Position.h"
#include "Object.h"
#include <vector>
class RuleManager;
class ObjectManager;
class TileMap;

class ControlManager
{
public:
    ControlManager(ObjectManager* objMgr, RuleManager* ruleMgr, TileMap* map);

    bool TryMoveAll(Direction dir);

private:
    bool TryMove(Object* obj, const Position& dir);

private:
    ObjectManager* _objectManager;
    RuleManager* _ruleManager;
    TileMap* _map;
};