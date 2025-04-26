#include "TileMap.h"
#include "TileBase.h"
#include "ObjectTile.h"
#include "TextTile.h"
#include "Object.h"
#include "ObjectType.h"
#include <fstream>
#include <iostream>

TileMap::TileMap()
    : _width(0), _height(0)
{
}

TileMap::~TileMap()
{
    clearTiles();
}

void TileMap::clearTiles()
{
    for (auto& row : _tiles)
    {
        for (auto& tile : row)
        {
            delete tile;
        }
    }
    _tiles.clear();
}

void TileMap::LoadMap(const std::string& filepath)
{
    clearTiles();

    std::ifstream file(filepath);
    if (!file.is_open())
    {
        std::cout << "파일 열기 실패: " << filepath << std::endl;
        return;
    }

    file >> _width >> _height;
    file.ignore();

    _tiles.resize(_height, std::vector<TileBase*>(_width, nullptr));

    for (int i = 0; i < _height; ++i)
    {
        std::string line;
        std::getline(file, line);

        for (int j = 0; j < _width; ++j)
        {
            if (j < line.length())
            {
                _tiles[i][j] = createTileFromChar(line[j], Position(j, i));
            }
            else
            {
                _tiles[i][j] = new ObjectTile(Position(j, i)); // 기본 타일
            }
        }
    }

    file.close();
}

TileBase* TileMap::createTileFromChar(char ch, const Position& pos)
{
    ObjectType type = ObjectType::NONE;

    switch (ch)
    {
    case '.': type = ObjectType::NONE; break;
    case 'W': type = ObjectType::WALL; break;
    case 'B': type = ObjectType::BABA; break;
    case 'F': type = ObjectType::FLAG; break;
    case 'R': type = ObjectType::ROCK; break;
    case 'b': type = ObjectType::TEXT_BABA; break;
    case 'r': type = ObjectType::TEXT_ROCK; break;
    case 'w': type = ObjectType::TEXT_WIN; break;
    case 'y': type = ObjectType::TEXT_YOU; break;
    case 'p': type = ObjectType::TEXT_PUSH; break;
    case 's': type = ObjectType::TEXT_STOP; break;
    case 'i': type = ObjectType::TEXT_IS; break;
    case 'f': type = ObjectType::TEXT_FLAG; break;
    default:  type = ObjectType::NONE; break;
    }

    if (type == ObjectType::TEXT_BABA || type == ObjectType::TEXT_FLAG ||
        type == ObjectType::TEXT_ROCK || type == ObjectType::TEXT_WIN ||
        type == ObjectType::TEXT_PUSH || type == ObjectType::TEXT_STOP ||
        type == ObjectType::TEXT_IS || type == ObjectType::TEXT_YOU)
    {
        return new TextTile(pos, type);
    }
    else
    {
        ObjectTile* tile = new ObjectTile(pos);
        if (type != ObjectType::NONE)
        {
            Object* obj = new Object(type, pos);
            tile->AddObject(obj);
        }
        return tile;
    }
}

TileBase* TileMap::GetTile(const Position& pos)
{
    if (!isInside(pos)) return nullptr;
    return _tiles[pos.s_y][pos.s_x];
}

void TileMap::SetTile(const Position& pos, TileBase* tile)
{
    if (isInside(pos))
    {
        delete _tiles[pos.s_y][pos.s_x];
        _tiles[pos.s_y][pos.s_x] = tile;
    }
}

void TileMap::RenderMap() const
{
    for (const auto& row : _tiles)
    {
        for (const auto& tile : row)
        {
            if (tile)
                tile->Render();
        }
        std::cout << std::endl;
    }
}

Position TileMap::FindObject(ObjectType type) const
{
    for (int y = 0; y < _height; ++y)
    {
        for (int x = 0; x < _width; ++x)
        {
            if (_tiles[y][x] && _tiles[y][x]->HasObjectType(type))
                return Position(x, y);
        }
    }
    return Position(-1, -1);
}

bool TileMap::isInside(const Position& pos) const
{
    return pos.s_x >= 0 && pos.s_x < _width && pos.s_y >= 0 && pos.s_y < _height;
}
