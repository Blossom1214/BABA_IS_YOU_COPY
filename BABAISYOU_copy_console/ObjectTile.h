#pragma once
#include "TileBase.h"
#include <vector>
class Object; 
class ObjectTile : public TileBase
{
public:
    virtual bool IsTextTile() const override { return false; }//����
    virtual bool IsObjectTile() const override { return true; }//��

    void AddObject(Object* obj);//������Ʈ�߰�
    void RemoveObject(Object* obj);//������Ʈ�����
    const std::vector<Object*>& GetObjects() const;//Ÿ�Ͽ�����ִ� ����(������Ʈ)����ȯ
    bool HasObjectType(ObjectType type) const; //������Ʈ Ÿ���� �´����ƴ�������
    virtual void Render() override;        //�������ϴ� �Լ�
private:
    std::vector<Object*> _objects;//Ÿ���ϳ��� ������Ʈ�� ������ ���ü����־ ���ͷ� ����

};
