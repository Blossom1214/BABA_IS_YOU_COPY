#pragma once
#include "TileType.h"
#include "Position.h"

class TileBase 
{
public:
    virtual ~TileBase() = default;//디폴트소멸자
    void SetPosition(const Position& pos) { _position = pos; }//포지션설정
    const Position& GetPosition() const { return _position; }//포지션읽기
    virtual void SetType(TileType type) { _tileType = type; }//타일타입을 설정
    virtual TileType GetType() const { return _tileType; }//타일타입을 읽기
    virtual void Render() = 0;
    virtual bool IsTextTile() const = 0;
    virtual bool IsObjectTile() const = 0;
protected:
    Position _position;//현재의 위치!
    TileType _tileType;//사실상 배경타일
};
