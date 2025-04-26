#pragma once
#include <vector>
#include <string>
#include "Position.h"
class TileBase;
class Object;
enum class ObjectType;
class TileMap
{
public:
    TileMap();
    ~TileMap();

public:
    void LoadMap(const std::string& filepath);
    void RenderMap() const;

    TileBase* GetTile(const Position& pos);
    void SetTile(const Position& pos, TileBase* tile);

    Position FindObject(ObjectType type) const;
    bool isInside(const Position& pos) const;

    int GetWidth() const { return _width; }
    int GetHeight() const { return _height; }

private:
    void clearTiles(); // 내부 타일 메모리 정리용
    TileBase* createTileFromChar(char ch, const Position& pos); // 문자 기준으로 타일 생성

private:
    int _width;
    int _height;
    std::vector<std::vector<TileBase*>> _tiles;
};

