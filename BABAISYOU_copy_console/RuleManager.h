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
    //�� �ΰ��� �ϴ� Ÿ�ϵ��� ��Ȯ�ϰ� �з��ϰ� ���ڿ� �ٽ� �ۼ��� �غ�����... ���� ��¥ ������ ����°�...
    RuleManager(ObjectManager* objMgr, TileMap* map);

    RuleResult CheckMove(Object* mover, const Position& target, const Position& dir);
    bool IsVictory();

    void ClearRules();
  

private:
    ObjectManager* _objectManager;
    TileMap* _map;
};


//set �ڷᱸ���� ��������(Ÿ�԰� ����� ����)
//ã�ƾ��ϴ� �ڷ��� �������� �����ϵ� �� ������ ���������̸� ���� ������ ������
//����Ʈ ������ �� ��찡 ������쿡 ������ �߻��� ���ɼ���ü������
//���� Ž�������ε� ���� ������ ��������... Ű�� ����� ���� �ڷᱸ���� ����ϰԵǾ���
//���� ���ǿ����� ��� �켱������ �Ǵ����� �ʿ��ϰԵ�
//�ʿ� ���ڸ��� �꿡 �ش��ϸ� �ʿ� �����ؾ���

//1. Ž�� ����
//����(��) �Ǵ� ����(��) �������θ� Ž��
//
//�� : TEXT_BABA TEXT_IS TEXT_YOU �� "BABA is YOU"��� ��� �ؼ���
//
//2. Ÿ�� ���� �ʿ�
//TEXT_BABA �� BABA
//
//TEXT_ROCK �� ROCK
//
//TEXT_FLAG �� FLAG
//
//TEXT_IS �� ���� �߰��� �ݵ�� �־�� ��
//
//TEXT_YOU / TEXT_PUSH / TEXT_STOP / TEXT_WIN �� ��� �ؼ���

//Ÿ��Ÿ���� ���� �𸣰ٴ� �׳� ��������...
