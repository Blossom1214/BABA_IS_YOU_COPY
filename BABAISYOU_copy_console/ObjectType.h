#pragma once
enum class ObjectType
{
	//해당타일에 있는 오브젝트가 있는지 없는지(플레이어가 움직였을때 충돌처리를 위해서 만들어야하는 부분) 
	//즉 tiletype과 비교하기위해서 있음... 둘이 비교했을때 즉 충돌했을때 판단하는 여부가 됨..
	NONE, //아무것도 없음
	BABA,
	ROCK,
	WALL,
	FLAG,

	TEXT_BABA,
	TEXT_ROCK,
	TEXT_WALL,
	TEXT_FLAG,

	TEXT_STOP,
	TEXT_IS,
	TEXT_YOU,
	TEXT_WIN,
	TEXT_PUSH

};