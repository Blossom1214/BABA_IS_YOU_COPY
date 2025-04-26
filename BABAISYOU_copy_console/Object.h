#pragma once
#include "Position.h"
#include "ObjectType.h"
#include "ObjectRole.h"
#include <unordered_set>
#include <string>

class Object
{
public:
	Object(ObjectType type, const Position& pos):_type(type), _position(pos){}
public:
	ObjectType GetType()const;//������Ʈ Ÿ���б�
	const Position& GetPosition()const;//�����Ǿ��
	void SetPosition(const Position& pos);//������Ʈ�� �����Ǽ���

	void AddRule(const std::string& rule);//���߰�
	void RemoveRule(const std::string& rule);//�껩��

	bool HasRule(const std::string& rule) const;//�����̺� �ش�����ִ��� üũ

private:

	ObjectType _type;
	Position _position;
	std::unordered_set<std::string> _rules;//������ Ű==��� �ؽ����̺�
};

