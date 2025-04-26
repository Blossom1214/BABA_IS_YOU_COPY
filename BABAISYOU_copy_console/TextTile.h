#pragma once
#include "Tile.h"
#include "TextRole.h"
class TextTile : public Tile
{
public:
    TextTile(TextRole role);
    ~TextTile() override = default;
public:

    TextRole GetTextRole()const;
protected:
    TextRole _textRole;
};