#include "Grammer.h"
#include "TileMap.h"
#include "TextTile.h"
#include "Movement.h"
#include "Position.h"
bool Grammer::CheckQuadPosition(TileMap* map, const Position& pos)
{
    //텍스트타일인지 아닌지를 알려면 해당위치의 타일이 텍스트타일인지부터!
    map->GetTile(pos)->GetObjects();//현재 타일맵의 내가 탐색한 위치에있는...것이 오브젝트를 가졌을때 text타일타입인가요?! 라고 물어보는것

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