#include "TextTile.h"
TextTile::TextTile(): Tile()
{
 
}

bool TextTile::HasPushRule() const
{
    return true;
}