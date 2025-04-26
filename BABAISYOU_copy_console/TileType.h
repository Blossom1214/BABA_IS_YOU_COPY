#pragma once
enum class TileType
{
	//타일이 아무것도 없다면 아래의타입을가짐...
	EMPTY,
	//실제 오브젝트
	BABA,
	ROCK,
	WALL,
	FLAG,

	//글자인 즉 실제 오브젝트가아닌 문자상태를 의미하는 텍스트블록
	TEXT_BABA,
	TEXT_ROCK,
	TEXT_WALL,
	TEXT_FLAG,
	
	//단어를 연결하는 동사나 특수한 블록
	TEXT_STOP,
	TEXT_IS,
	TEXT_YOU,
	TEXT_WIN,
	TEXT_PUSH


};