#pragma once
#include "TextTile.h"
#include"Direction.h"
#include "Position.h"
//class Object; //���漱�� �ʿ��Ѱ�? �ʿ����...Ÿ�Ͽ� �̹� ���漱�𵵵Ǿ��ְ� �̹� ������Ʈ ������ ��������� ����Ǿ��ְ� �װ� ��ӹ޾ұ�����...
class VerbToTextTile : public TextTile
{
public:
	//bool CheckQuadPosition(TileBase* tile,const Position& pos);
	//�� �Լ���...üũ�� �ϴ°��� ������..��� ���� �����Ŵ����� �������� ���⼭ �ҰԾƴ϶� ���⼱ ���� �ҷ��ͼ� ���Ʒ��� ���� ���� �Ķ���͵��� �ް� �װɷ� ���� �̰� verbŸ���̸� ������ȯ�ϴ� �Լ��� ����������
	bool CheckVerb();
private:
	Position _QuadPos;

};

