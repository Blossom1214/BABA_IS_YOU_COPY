#pragma once
#include "TileType.h"
#include "Position.h"

class TileBase //�߻�ȭ Ŭ���� �ٽ��ѹ� �����͸���
{

public:
    virtual ~TileBase() = default;
    void SetPosition(const Position& pos) { _position = pos; }
    const Position& GetPosition() const { return _position; }
    virtual void SetType(TileType type) { _tileType = type; }
    virtual TileType GetType() const { return _tileType; }
    virtual void Render() = 0;
    virtual bool IsTextTile() const = 0;
    virtual bool IsObjectTile() const = 0;
protected:
    Position _position;
    TileType _tileType;

};
