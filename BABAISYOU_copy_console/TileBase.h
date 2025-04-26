#pragma once
#include "Position.h"
#include "ObjectType.h"
#include "TileType.h"
#include <vector>

class Object;
class TileBase //완전무결한 타일의 최상위 추상화된 클래스임... 이제 쓸려면 오버라이드해서쓰라는거야
{
public:
    virtual ~TileBase() {}
    virtual void AddObject(Object* obj) = 0;
    virtual void RemoveObject(Object* obj) = 0;
    virtual const std::vector<Object*>& GetObjects() const = 0;
    virtual bool HasObjectType(ObjectType type) const = 0;

    virtual void SetType(TileType type) = 0;
    virtual TileType GetType() const = 0;

    virtual void SetObject_prev(ObjectType object) = 0;
    virtual ObjectType GetObject_prev() const = 0;

    virtual void Render() = 0;
};