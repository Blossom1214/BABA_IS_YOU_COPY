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
	TileBase* GetTile(const Position& pos)const;//�ش� Ÿ�� ��ġ ��ȯ
	void SetTile(Position pos, TileBase* tile);//�ش� ��ġ�� Ÿ���� �ٸ� Ÿ���� Ÿ�Ϸ� ��ȯ�ϴ� �Լ�
	void LoadMap(const std::string& filemap);
	ObjectType GetObjectTile(TileBase* tile);


	//TileType ConvertCharToTileType(char ch);
	ObjectType ConvertCharToObjectType(char ch);


	void RenderMap();
	Position FindObject(ObjectType target);
	bool isInside(const Position& pos) const;

	//Ÿ�ϸ� ������ ������ ���ϰ� �������� �Լ�
	int GetHeight()const { return _height; }
	int GetWidth()const { return _width; }
	
private:
	int _height;
	int _width;
	std::vector<std::vector<TileBase*>>* _tileMap;
	//Ÿ�� ���̽�(�߻�Ŭ����)���� �������� ����ؼ� �ش� �θ� ��ӹ޴� �ڽ�(Ÿ��)����
	//�� �θ� ȣ�������� ���� ���ε����� ���ؼ� ���� �ڽĿ� �ش��ϴ� Ÿ���� �ҷ��� ����Ҽ��ְ� ����� �ְ� �˴ϴ�...
	//tilebase�� ������ �����ò���?!!(Ÿ���� �����Ҳ���...) _tilemap�� �����Ҷ� tilebase�� ����Ű�°� �ڽİ�ü��
	//Ÿ���� �����Ҵ��ؼ� �����ϰԵǴµ�
	//��Ÿ���� �Լ��� �θ�Ŭ��������ȣ���ϸ� �ش� Ŭ���������� ã��������..(���ʿ� vfptr�� ã�ư��⶧���� ��� ������ �ȵǾ��־�߸� �θ� ã�ư�)
	//(������ Ÿ�ϸ� ����)
};

