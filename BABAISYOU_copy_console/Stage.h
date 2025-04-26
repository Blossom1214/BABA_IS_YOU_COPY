#pragma once
#include "InputManager.h"
#include "ControlManager.h"
#include "RuleManager.h"
#include "ObjectManager.h"
#include "TileMap.h"

class StageManager
{
public:
    StageManager();
    ~StageManager();

    void Update();
    void Render();
    void PrintWin();

private:
    InputManager _inputManager;
    TileMap _map;
    ObjectManager* _objectManager;
    RuleManager* _ruleManager;
    ControlManager* _controlManager;

    void Init();
};

