#pragma once
#include "TextTile.h"
//class Object; //���漱�� �ʿ��Ѱ�? �ʿ����...Ÿ�Ͽ� �̹� ���漱�𵵵Ǿ��ְ� �̹� ������Ʈ ������ ��������� ����Ǿ��ְ� �װ� ��ӹ޾ұ�����...
class VerbToTextTile : public TextTile
{
public:
	VerbToTextTile(TextRole role);
	~VerbToTextTile() override = default;
};

