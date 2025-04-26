#include "Grammer.h"
#include "Tile.h"
#include "ObjectToTextTile.h"
#include "VerbToTextTile.h"
#include "StateToTextTile.h"
#include "TileMap.h"
bool Grammer::IsText(Tile* tile)
{
	return ObjectRole(_type) == ObjectRole::TEXT;
}

bool Grammer::IsNoun(Tile* tile)
{
	return ObjectRole(_type) == ObjectRole::NOUN;
}

bool Grammer::IsVerb(Tile* tile)
{
	return ObjectRole(_type) == ObjectRole::VERB;
}

bool Grammer::IsProperty(Tile* tile)
{
	return ObjectRole(_type) == ObjectRole::PROPERTY;
}

bool Grammer::CheckHorizontalText(TileMap* map, const Position& pos)
{
	return false;
}

bool Grammer::CheckVerticalText(TileMap* map, const Position& pos)
{
	return false;
}
