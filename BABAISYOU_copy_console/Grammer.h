#pragma once
#include "Position.h"
class TileMap;
class Tile;
class Grammer
{
private:
	Grammer() = delete;//��ü������ �Ұ���..
public:
	static bool IsText(TileBase* tile); //�� �ؽ�Ʈ�� objectrole�� ���ִ� �ؽ�Ʈ ���� �� �Ǻ��ϴ� �Լ�
	static bool IsNoun(TileBase* tile);
	static bool IsVerb(TileBase* tile);
	static bool IsProperty(TileBase* tile);
	static bool CheckHorizontalText(TileMap* map, const Position& pos); // �� �¿� �ؽ�Ʈ üũ
	static bool CheckVerticalText(TileMap* map, const Position& pos);   // �� ���� �ؽ�Ʈ üũ//�ܺο��� �¿�� ���Ʒ� �����ִ��� �˻��ϴ�...
private: //�������� ������ �˻��۾��� �������Ե� ���������ʾƵ��� �ᱹ ����� �˾Ƶ��Ǵ� ���ڽ���� ����� ����ص� �Ǵ� �����̴�...��길 �Ѱܹް� ó���ؼ� �׳� public�Լ��� �������� �Ѱ��ָ�Ǵ� �׷��Լ�...

};

