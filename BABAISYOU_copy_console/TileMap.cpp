#include "TileMap.h"
#include "TileBase.h"
#include "ObjectType.h"
#include "Position.h"
#include "Object.h"
#include <fstream>
#include <iostream>
using namespace std;
TileMap::TileMap(): _height(0), _width(0)
{
    LoadMap("../Stage/Stage1.txt");
}

TileMap::~TileMap()
{
    for (int i = 0; i < _height; ++i)
    {
        for (int j = 0; j < _width; ++j)
        {
            delete _tileMap[i][j];
        }
    }
}

TileBase* TileMap::GetTile(const Position& pos) const
{
    if (!isInside(pos)) {return nullptr;}
    return _tileMap[pos.s_y][pos.s_x];
}

void TileMap::SetTile(const Position& pos, TileBase* tile)
{
    if (isInside(pos)) 
    {
        _tileMap[pos.s_y][pos.s_x] = tile;
    }
}

void TileMap::LoadMap(const string& filemap)
{
    std::ifstream file(filemap);
    if (!file.is_open())
    {
        cout << "파일 열기 실패" << endl;
        return;
    }

    file >> _width >> _height;
    file.ignore();

    _tileMap.resize(_height, vector<TileBase*>(_width, nullptr));

    for (int i = 0; i < _height; ++i)
    {
        string line;
        getline(file, line);

        for (int j = 0; j < _width; ++j)
        {
            TileBase* tile = new TileBase();
            _tileMap[i][j] = tile;

            if (j < line.length())
            {
                char ch = line[j];
                ObjectType objType = ConvertCharToObjectType(ch);

                Position pos(j, i);
                tile->SetType(TileType::EMPTY);

                if (objType != ObjectType::NONE)
                {
                    Object* obj = new Object(objType, pos);
                    tile->AddObject(obj);
                }
            }
        }
    }

    file.close();
}

ObjectType TileMap::GetObjectTile(TileBase* tile)
{
    const auto& objs = tile->GetObjects();
    if (!objs.empty())
        return objs.back()->GetType();
    return ObjectType::NONE;
}

ObjectType TileMap::ConvertCharToObjectType(char ch)
{
    switch (ch)
    {
    case '.': return ObjectType::NONE;
    case 'W': return ObjectType::WALL;
    case 'B': return ObjectType::BABA;
    case 'F': return ObjectType::FLAG;
    case 'R': return ObjectType::ROCK;
    case 'b': return ObjectType::TEXT_BABA;
    case 'r': return ObjectType::TEXT_ROCK;
    case 'w': return ObjectType::TEXT_WIN;
    case 'y': return ObjectType::TEXT_YOU;
    case 'p': return ObjectType::TEXT_PUSH;
    case 's': return ObjectType::TEXT_STOP;
    case 'i': return ObjectType::TEXT_IS;
    case 'f': return ObjectType::TEXT_FLAG;
    default:  return ObjectType::NONE;
    }
}

void TileMap::RenderMap()
{
    for (int i = 0; i < _height; ++i)
    {
        for (int j = 0; j < _width; ++j)
        {
            if (_tileMap[i][j])
                _tileMap[i][j]->Render();
        }
        std::cout << std::endl;
    }
}

Position TileMap::FindObject(ObjectType target)
{
    for (int y = 0; y < _height; ++y)
    {
        for (int x = 0; x < _width; ++x)
        {
            if (_tileMap[y][x] && _tileMap[y][x]->HasObjectType(target))
            {
                return Position(x, y);
            }
        }
    }
    return Position(-1, -1);
}

bool TileMap::isInside(const Position& pos) const
{
    return pos.s_x >= 0 && pos.s_x < _width && pos.s_y >= 0 && pos.s_y < _height;
}
