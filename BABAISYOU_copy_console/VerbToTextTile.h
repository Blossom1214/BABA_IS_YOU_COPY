#pragma once
#include "TextTile.h"
#include"Direction.h"
#include "Position.h"
//class Object; //전방선언 필요한가? 필요없음...타일에 이미 전방선언도되어있고 이미 오브젝트 포인터 멤버변수도 선언되어있고 그걸 상속받았긴햇음...
class VerbToTextTile : public TextTile
{
public:
	//bool CheckQuadPosition(TileBase* tile,const Position& pos);
	//위 함수는...체크를 하는것이 맞지만..사실 저건 문법매니저가 할일이지 여기서 할게아니라 여기선 저걸 불러와서 위아래와 같이 방향 파라미터들을 받고 그걸로 이제 이게 verb타입이면 참을반환하는 함수를 만들어줘야함
	bool CheckVerb();
private:
	Position _QuadPos;

};

