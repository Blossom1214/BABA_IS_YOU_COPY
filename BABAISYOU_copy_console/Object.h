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
	ObjectType GetType()const;//오브젝트 타입읽기
	const Position& GetPosition()const;//포지션얻기
	void SetPosition(const Position& pos);//오브젝트의 포지션셋팅

	void AddRule(const std::string& rule);//룰추가
	void RemoveRule(const std::string& rule);//룰빼기

	bool HasRule(const std::string& rule) const;//룰테이블에 해당룰이있는지 체크

private:

	ObjectType _type;
	Position _position;
	std::unordered_set<std::string> _rules;//룰저장 키==밸류 해시테이블
};

