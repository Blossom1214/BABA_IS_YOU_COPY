#include "Tile.h"
#include "Object.h"
#include <iostream>
#include <algorithm>
using namespace std;

Tile::Tile() :_tileType(TileType::EMPTY),_prevObjectType(ObjectType::NONE)
{
}

Tile::~Tile()
{
    for (Object* obj : _objects)
    {
        delete obj;
    }
    _objects.clear();
}


void Tile::SetType(TileType type)
{
	_tileType = type;
}
TileType Tile::GetType() const
{
    return _tileType;
}


void Tile::SetObject_prev(ObjectType object)
{
    _prevObjectType = object;
}

ObjectType Tile::GetObject_prev() const
{
    return  _prevObjectType;
}

void Tile::AddObject(Object* obj)
{
    _objects.push_back(obj);
}

void Tile::RemoveObject(Object* obj)
{
    auto it = remove(_objects.begin(), _objects.end(), obj);
    _objects.erase(it,_objects.end()); //너무길긴한데 리펙터링 한번 더할듯...
     //리무브는 알고리즘 함수로 처음부터 끝까지 현재 오브젝트 벡터안에서 obj에 해당하는것들을 맨 뒤로 밀어버림 그뒤에 그 obj의 위치를 시작지점으로 하고 end까지의 정보를 싹 날려버림..
}

const vector<Object*>& Tile::GetObjects() const
{
    return _objects;
}

bool Tile::HasObjectType(ObjectType type) const
{
    for (const auto* obj : _objects)
    {
        if (obj->GetType() == type)
        {
            return true;
        }
    }
    return false;
}



void Tile::Render() {
    if (!_objects.empty()) {
        switch (_objects.back()->GetType()) {
        case ObjectType::BABA:     cout << "[B]"; break;
        case ObjectType::ROCK:     cout << "[R]"; break;
        case ObjectType::WALL:     cout << "[W]"; break;
        case ObjectType::FLAG:     cout << "[F]"; break;
        case ObjectType::TEXT_BABA:cout << " b "; break;
        case ObjectType::TEXT_IS:  cout << " i "; break;
        case ObjectType::TEXT_YOU: cout << " y "; break;
        case ObjectType::TEXT_PUSH:cout << " p "; break;
        case ObjectType::TEXT_WIN: cout << " w "; break;
        case ObjectType::TEXT_STOP:cout << " s "; break;
        case ObjectType::TEXT_FLAG:cout << " f "; break;
        case ObjectType::TEXT_ROCK:cout << " r "; break;
        default: cout << "[?]"; break;
        }
    }
    else {
        switch (_tileType) {
        case TileType::EMPTY:      cout << "[ ]"; break;
        case TileType::WALL:       cout << "[W]"; break;
        case TileType::BABA:       cout << "[B]"; break;
        case TileType::ROCK:       cout << "[R]"; break;
        case TileType::FLAG:       cout << "[F]"; break;
        case TileType::TEXT_BABA:  cout << " b "; break;
        case TileType::TEXT_IS:    cout << " i "; break;
        case TileType::TEXT_YOU:   cout << " y "; break;
        case TileType::TEXT_PUSH:  cout << " p "; break;
        case TileType::TEXT_WIN:   cout << " w "; break;
        case TileType::TEXT_STOP:  cout << " s "; break;
        case TileType::TEXT_FLAG:  cout << " f "; break;
        case TileType::TEXT_ROCK:  cout << " r "; break;
        default: cout << "[?]"; break;
        }
    }
}
