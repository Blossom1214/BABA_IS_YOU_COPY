#pragma once
#include "TextTile.h"
class VerbToTextTile : public TextTile
{
public:
	VerbToTextTile(TextRole role);
	~VerbToTextTile() override = default;
public:
	//이제 만들어야하는것..?! grammer에서 위아래옆에 둘중하나라도 둘다 채워져있는게 텍스트라면 이제 체크해줘야하는게 맞음...
	//문법이 성공하고의 여부를 떠나서 그 중앙의 동사를 기준으로 잡고 사실 아래위에만 체크하면 문제는 크게 없을듯합니다...
	
};

