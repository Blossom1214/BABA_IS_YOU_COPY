#pragma once
#include "ObjectType.h"
class Object
{
public:
    Object(ObjectType type) : _objectType(type) {}
    virtual ~Object() = default;
    ObjectType GetType() const { return _objectType; }
    virtual void Render() = 0;
protected:
    ObjectType _objectType;
};


