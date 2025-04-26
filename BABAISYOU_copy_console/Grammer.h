#pragma once
#include "Position.h"
class TileMap;
class Grammer
{
private:
	Grammer() = delete;//��ü������ �Ұ���..
public:
	static bool IsText(); //�� �ؽ�Ʈ�� objectrole�� ���ִ� �ؽ�Ʈ ���� �� �Ǻ��ϴ� �Լ�
	static bool IsNoun();
	static bool IsVerb();
	static bool IsProperty();
	static bool CheckQuadPosition(TileMap* map, const Position& pos);//�ܺο��� �¿�� ���Ʒ� �����ִ��� �˻��ϴ�...
private: //�������� ������ �˻��۾��� �������Ե� ���������ʾƵ��� �ᱹ ����� �˾Ƶ��Ǵ� ���ڽ���� ����� ����ص� �Ǵ� �����̴�...��길 �Ѱܹް� ó���ؼ� �׳� public�Լ��� �������� �Ѱ��ָ�Ǵ� �׷��Լ�...

};

