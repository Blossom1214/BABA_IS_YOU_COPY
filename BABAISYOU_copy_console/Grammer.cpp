#include "Grammer.h"
#include "TileMap.h"
#include "TextTile.h"
#include "Movement.h"
#include "Position.h"
bool Grammer::CheckQuadPosition(TileMap* map, const Position& pos)
{
    //�ؽ�ƮŸ������ �ƴ����� �˷��� �ش���ġ�� Ÿ���� �ؽ�ƮŸ����������!
    map->GetTile(pos)->GetObjects();//���� Ÿ�ϸ��� ���� Ž���� ��ġ���ִ�...���� ������Ʈ�� �������� textŸ��Ÿ���ΰ���?! ��� ����°�

    return false;
}
bool Grammer::IsText()
{
	return ObjectRole(_type) == ObjectRole::TEXT;
}

bool Grammer::IsNoun()
{
	return ObjectRole(_type) == ObjectRole::NOUN;
}

bool Grammer::IsVerb()
{
	return ObjectRole(_type) == ObjectRole::VERB;
}

bool Grammer::IsProperty()
{
	return ObjectRole(_type) == ObjectRole::PROPERTY;
}