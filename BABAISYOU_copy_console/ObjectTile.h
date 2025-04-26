#pragma once

#include "TileBase.h"
#include <vector>

class Object;

class ObjectTile : public TileBase
{
private:
    std::vector<Object*> _objects;

public:
    virtual bool IsTextTile() const override { return false; }
    virtual bool IsObjectTile() const override { return true; }

    void AddObject(Object* obj);
    void RemoveObject(Object* obj);
    const std::vector<Object*>& GetObjects() const;
    bool HasObjectType(ObjectType type) const;

    virtual void Render() override;
};
