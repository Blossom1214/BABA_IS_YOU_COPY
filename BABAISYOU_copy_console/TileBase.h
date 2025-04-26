#pragma once
#include "TileType.h"
#include "Position.h"

class TileBase 
{
public:
    virtual ~TileBase() = default;//����Ʈ�Ҹ���
    void SetPosition(const Position& pos) { _position = pos; }//�����Ǽ���
    const Position& GetPosition() const { return _position; }//�������б�
    virtual void SetType(TileType type) { _tileType = type; }//Ÿ��Ÿ���� ����
    virtual TileType GetType() const { return _tileType; }//Ÿ��Ÿ���� �б�
    virtual void Render() = 0;
    virtual bool IsTextTile() const = 0;
    virtual bool IsObjectTile() const = 0;
protected:
    Position _position;//������ ��ġ!
    TileType _tileType;//��ǻ� ���Ÿ��
};
