#pragma once

#include <vector>
#include <string>
#include "Position.h"

class TileBase;
class Object;

enum class TileType;
enum class ObjectType;

class TileMap
{
public:
    TileMap();
    ~TileMap();

public:
    TileBase* GetTile(const Position& pos) const;
    void SetTile(const Position& pos, TileBase* tile);
    void LoadMap(const std::string& filemap);
    ObjectType GetObjectTile(TileBase* tile);
    ObjectType ConvertCharToObjectType(char ch);
    void RenderMap();
    Position FindObject(ObjectType target);
    bool isInside(const Position& pos) const;

    int GetHeight() const { return _height; }
    int GetWidth() const { return _width; }

private:
    int _height;
    int _width;
    std::vector<std::vector<TileBase*>> _tileMap; // ❗ 포인터 제거
};
