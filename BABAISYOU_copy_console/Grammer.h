#pragma once
#include "Position.h"
class TileMap;
class Tile;
class Grammer
{
private:
	Grammer() = delete;//객체생성은 불가함..
public:
	static bool IsText(TileBase* tile); //그 텍스트가 objectrole에 들어가있는 텍스트 인지 즉 판별하는 함수
	static bool IsNoun(TileBase* tile);
	static bool IsVerb(TileBase* tile);
	static bool IsProperty(TileBase* tile);
	static bool CheckHorizontalText(TileMap* map, const Position& pos); // ← 좌우 텍스트 체크
	static bool CheckVerticalText(TileMap* map, const Position& pos);   // ← 상하 텍스트 체크//외부에서 좌우랑 위아래 뭐가있는지 검사하는...
private: //만든이유 어차피 검사작업은 누구에게도 공개하지않아도됨 결국 결과만 알아도되는 블랙박스라는 기법을 사용해도 되는 존재이다...계산만 넘겨받고 처리해서 그냥 public함수로 참거짓만 넘겨주면되는 그런함수...

};

