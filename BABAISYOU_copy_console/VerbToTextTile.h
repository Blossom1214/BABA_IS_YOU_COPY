#pragma once
#include "TextTile.h"
//class Object; //전방선언 필요한가? 필요없음...타일에 이미 전방선언도되어있고 이미 오브젝트 포인터 멤버변수도 선언되어있고 그걸 상속받았긴햇음...
class VerbToTextTile : public TextTile
{
public:
	VerbToTextTile(TextRole role);
	~VerbToTextTile() override = default;
};

