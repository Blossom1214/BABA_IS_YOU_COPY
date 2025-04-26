#pragma once
#include "TileBase.h"
#include "TileType.h"
#include "ObjectType.h"
#include "Position.h"
#include <vector>
#include <algorithm>
class Object;
class Tile :public TileBase
{
public:
	Tile();
	~Tile()override;
public:
    void SetType(TileType type) override; //해당 타일의 타입을 정해주는 함수
    TileType GetType() const override; //타일의 타입을 읽어오는데 사용

    void SetObject_prev(ObjectType object) override;
    ObjectType GetObject_prev() const override;
    
    void AddObject(Object* obj)override; //타일에 오브젝트추가작업
    void RemoveObject(Object* obj)override; //해당타일에있는 오브젝트를 지우는작업
    const std::vector<Object*>& GetObjects() const override; //벡터에 저장해둔 오브젝트를 읽어오기
    bool HasObjectType(ObjectType type) const override;//그오브젝트가 어떠한 오브젝트 타입을 가지는지 판별
    
    void Render() final override; // 콘솔에 문자 출력용 함수 //자식은 더이상 이걸 쓸이유가 전혀없음...어차피 위치는 따로 측정중이기도하기때문에...
   
protected:
    TileType _tileType;
    ObjectType _prevObjectType;
	
    std::vector<Object*> _objects; //해당위치에 있는 오브젝트들...(즉 해당위치에 중복으로 존재하게 하는 벡터가됨)
   
    
};
