#include "Grammer.h"
#include "Tile.h"
#include "ObjectToTextTile.h"
#include "VerbToTextTile.h"
#include "StateToTextTile.h"
#include "TileMap.h"
#include "Movement.h"
bool Grammer::IsText(TileBase* tile)
{
	return dynamic_cast<TextTile*>(tile) != nullptr;
}

bool Grammer::IsNoun(TileBase* tile)
{
    TextTile* textTile = dynamic_cast<TextTile*>(tile); //다운캐스팅
    if (!textTile) 
    {
        return false;
    }
    switch (textTile->GetTextRole())
    {
    case TextRole::BABA:
    case TextRole::ROCK:
    case TextRole::WALL:
    case TextRole::FLAG:
        return true;
    default:
        return false;
    }
}

bool Grammer::IsVerb(TileBase* tile)
{
    TextTile* textTile = dynamic_cast<TextTile*>(tile); //다운캐스팅
    if (!textTile)
    {
        return false;
    }
    switch (textTile->GetTextRole())
    {
    case TextRole::IS:
        return true;
    default:
        return false;
    }
}

bool Grammer::IsProperty(TileBase* tile)
{
    TextTile* textTile = dynamic_cast<TextTile*>(tile); //다운캐스팅
    if (!textTile)
    {
        return false;
    }
    switch (textTile->GetTextRole())
    {
    case TextRole::YOU:
    case TextRole::PUSH:
    case TextRole::STOP:
    case TextRole::WIN:
        return true;
    default:
        return false;
    }
}

bool Grammer::CheckHorizontalText(TileMap* map, const Position& pos)
{
	TileBase*tile = map->GetTile(pos);
	if (!tile||!IsText(tile))//둘중하나라도 거짓이라면 아래 코드로 반환..
	{
		return false;
	}
    
    TileBase* leftTile = map->GetTile(pos + Movement::Vector(Direction::LEFT));
    TileBase* rightTile = map->GetTile(pos + Movement::Vector(Direction::RIGHT));

    if (leftTile && IsText(leftTile) && rightTile && IsText(rightTile))
    {
        return true;
    }
    return false;
}

bool Grammer::CheckVerticalText(TileMap* map, const Position& pos)
{
    TileBase* tile = map->GetTile(pos);
    if (!tile || !IsText(tile))//둘중하나라도 거짓이라면 아래 코드로 반환..
    {
        return false;
    }

    TileBase* upTile = map->GetTile(pos + Movement::Vector(Direction::UP));
    TileBase* downTile = map->GetTile(pos + Movement::Vector(Direction::DOWN));

    if (upTile && IsText(upTile) && downTile && IsText(downTile))
    {
        return true;
    }
    return false;
	
}
