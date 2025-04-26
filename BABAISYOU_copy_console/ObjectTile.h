#pragma once
#include "TileBase.h"
#include <vector>
class Object; 
class ObjectTile : public TileBase
{
public:
    virtual bool IsTextTile() const override { return false; }//거짓
    virtual bool IsObjectTile() const override { return true; }//참

    void AddObject(Object* obj);//오브젝트추가
    void RemoveObject(Object* obj);//오브젝트지우기
    const std::vector<Object*>& GetObjects() const;//타일에들어있는 벡터(오브젝트)를반환
    bool HasObjectType(ObjectType type) const; //오브젝트 타입이 맞는지아닌지구별
    virtual void Render() override;        //렌더링하는 함수
private:
    std::vector<Object*> _objects;//타일하나에 오브젝트가 여러개 들어올수도있어서 벡터로 관리

};
