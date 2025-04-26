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
    void SetType(TileType type) override; //�ش� Ÿ���� Ÿ���� �����ִ� �Լ�
    TileType GetType() const override; //Ÿ���� Ÿ���� �о���µ� ���

    void SetObject_prev(ObjectType object) override;
    ObjectType GetObject_prev() const override;
    
    void AddObject(Object* obj)override; //Ÿ�Ͽ� ������Ʈ�߰��۾�
    void RemoveObject(Object* obj)override; //�ش�Ÿ�Ͽ��ִ� ������Ʈ�� ������۾�
    const std::vector<Object*>& GetObjects() const override; //���Ϳ� �����ص� ������Ʈ�� �о����
    bool HasObjectType(ObjectType type) const override;//�׿�����Ʈ�� ��� ������Ʈ Ÿ���� �������� �Ǻ�
    
    void Render() final override; // �ֿܼ� ���� ��¿� �Լ� //�ڽ��� ���̻� �̰� �������� ��������...������ ��ġ�� ���� �������̱⵵�ϱ⶧����...
   
protected:
    TileType _tileType;
    ObjectType _prevObjectType;
	
    std::vector<Object*> _objects; //�ش���ġ�� �ִ� ������Ʈ��...(�� �ش���ġ�� �ߺ����� �����ϰ� �ϴ� ���Ͱ���)
   
    
};
