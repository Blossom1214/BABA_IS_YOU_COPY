#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
struct Position;
class TileBase;
class Object;

enum class TileType;
enum class ObjectType;
class TileMap
{
public:
	TileMap();
	~TileMap();
public:
	TileBase* GetTile(const Position& pos)const;//해당 타일 위치 반환
	void SetTile(Position pos, TileBase* tile);//해당 위치의 타일을 다른 타입의 타일로 변환하는 함수
	void LoadMap(const std::string& filemap);
	ObjectType GetObjectTile(TileBase* tile);


	//TileType ConvertCharToTileType(char ch);
	ObjectType ConvertCharToObjectType(char ch);


	void RenderMap();
	Position FindObject(ObjectType target);
	bool isInside(const Position& pos) const;

	//타일맵 밖으로 나가지 못하게 막기위한 함수
	int GetHeight()const { return _height; }
	int GetWidth()const { return _width; }
	
private:
	int _height;
	int _width;
	std::vector<std::vector<TileBase*>>* _tileMap;
	//타일 베이스(추상클래스)에서 다형성을 사용해서 해당 부모를 상속받는 자식(타일)에게
	//즉 부모를 호출했을때 동적 바인딩으로 인해서 그의 자식에 해당하는 타일을 불러서 사용할수있게 만들어 주게 됩니다...
	//tilebase가 누구를 가져올꺼야?!!(타일을 생성할꺼임...) _tilemap을 생성할때 tilebase가 가르키는건 자식객체인
	//타일을 동적할당해서 생성하게되는데
	//그타일의 함수를 부모클래스에서호출하면 해당 클래스에서는 찾을수없음..(애초에 vfptr로 찾아가기때문에 사실 생성이 안되어있어야만 부모를 찾아감)
	//(지금은 타일만 있음)
};

