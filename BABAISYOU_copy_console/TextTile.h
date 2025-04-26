#pragma once
#include "TileBase.h"
#include "TextRole.h"
class TextTile : public TileBase
{
public:
    TextTile(TextRole role);//생성자초기화
    virtual bool IsTextTile() const override { return true; }//참
    virtual bool IsObjectTile() const override { return false; }//거짓
    TextRole GetTextRole() const;//가지고있는롤반환
    virtual void Render() override = 0;//여기선 또다시추상화
protected:
    TextRole _textRole; //텍스트의 역할을저장

};