#include "TextTile.h"

TextTile::TextTile(TextRole role) :_textRole(role)
{
}

TextRole TextTile::GetTextRole() const
{
	return _textRole;
}
