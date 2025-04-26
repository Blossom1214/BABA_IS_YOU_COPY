#pragma once
#include "TileType.h"
#include "Position.h"

class TileBase //추상화 클래스 다시한번 리펙터링중
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
