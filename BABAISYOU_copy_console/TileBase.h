#pragma once
#include "Position.h"
#include "ObjectType.h"
#include "TileType.h"
#include <vector>

class Object;
class TileBase //���������� Ÿ���� �ֻ��� �߻�ȭ�� Ŭ������... ���� ������ �������̵��ؼ�����°ž�
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