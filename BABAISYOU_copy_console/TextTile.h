#pragma once
#include "Tile.h"

class TextTile : public Tile
{
public:
    TextTile();
    ~TextTile() override = default;

public:
    bool HasPushRule() const; //고정적으로 참을 반환(나중에 더생기면 ex) text is stop이런게 생기면 false로 바꿔줘야겟지만...)
};