#pragma once
#include "Tile.h"

class TextTile : public Tile
{
public:
    TextTile();
    ~TextTile() override = default;

public:
    bool HasPushRule() const; //���������� ���� ��ȯ(���߿� ������� ex) text is stop�̷��� ����� false�� �ٲ���߰�����...)
};