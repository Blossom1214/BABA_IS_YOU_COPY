#pragma once
#include "TileBase.h"
#include "TextRole.h"
class TextTile : public TileBase
{
public:
    TextTile(TextRole role);//�������ʱ�ȭ
    virtual bool IsTextTile() const override { return true; }//��
    virtual bool IsObjectTile() const override { return false; }//����
    TextRole GetTextRole() const;//�������ִ·ѹ�ȯ
    virtual void Render() override = 0;//���⼱ �Ǵٽ��߻�ȭ
protected:
    TextRole _textRole; //�ؽ�Ʈ�� ����������

};