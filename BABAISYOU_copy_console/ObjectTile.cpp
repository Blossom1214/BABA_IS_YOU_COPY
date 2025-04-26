#include "ObjectTile.h"
#include "Object.h" 

#include <algorithm> 

void ObjectTile::AddObject(Object* obj)
{
    if (obj)
        _objects.push_back(obj);
}

void ObjectTile::RemoveObject(Object* obj)
{
    if (!obj)
        return;

    auto it = std::find(_objects.begin(), _objects.end(), obj);
    if (it != _objects.end())
        _objects.erase(it);
}

const std::vector<Object*>& ObjectTile::GetObjects() const
{
    return _objects;
}

bool ObjectTile::HasObjectType(ObjectType type) const
{
    for (const auto& obj : _objects)
    {
        if (obj && obj->GetType() == type)
            return true;
    }
    return false;
}

void ObjectTile::Render()
{
    for (const auto& obj : _objects)
    {
        if (obj)
            obj->Render();
    }
}
